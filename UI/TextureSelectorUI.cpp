#include "TextureSelectorUI.h"
#include "ui_TextureSelectorUI.h"
#include <QDebug>
#include <QFile>
#include <QJsonDocument>
#include <QJsonValue>
#include <QJsonArray>
#include <QGridLayout>
#include <QEvent>
#include <QFileDialog>

namespace MelonGames {
    namespace Particles {

        TextureSelectorUI::TextureSelectorUI(QWidget *parent) :
            QWidget(parent),
            ui(new Ui::TextureSelectorUI)
          , pixmapsSize(80, 80
                        )
          , selectedTexture(0)
        {
            ui->setupUi(this);

            loadTextures();
        }

        TextureSelectorUI::~TextureSelectorUI()
        {
            delete ui;
        }

        bool TextureSelectorUI::eventFilter(QObject* watched, QEvent* event)
        {
            if (event->type() == QEvent::MouseButtonPress)
            {
                int index = 0;
                for (auto image : images)
                {
                    if ((QObject*)image == watched)
                    {
                        selectedTexture = index;
                        emit onSelectedTextureChanged(this);
                        break;
                    }
                    ++index;
                }
            }

            return false;
        }

        const TextureSelectorUI::Texture* TextureSelectorUI::getSelectedTexture() const
        {
            if (textures.size() > selectedTexture)
            {
                return &textures.at(selectedTexture);
            }

            return nullptr;
        }

        void TextureSelectorUI::on_pushButton_clicked()
        {
            QString path = QFileDialog::getOpenFileName(this, "Open image file", "", "PNG (*.png)");
            if (!path.isEmpty())
            {
                addTexture(path, false);
            }
        }

        void TextureSelectorUI::loadTextures()
        {
            QFile file("://ImagesList.json");
            file.open(QIODevice::ReadOnly | QIODevice::Text);
            QByteArray fileContents = file.readAll();
            file.close();

            QJsonArray imagesArray = QJsonDocument::fromJson(fileContents).array();
            for (QJsonValue imageJson : imagesArray)
            {
                QString imageName = imageJson.toString();
                addTexture(imageName, true);
            }

            if (!textures.isEmpty())
            {
                selectedTexture = 0;
                emit onSelectedTextureChanged(this);
            }
        }

        void TextureSelectorUI::addTexture(const QString& imageName, bool internal)
        {
            const int nColumns = 5;

            QString qPath = (internal ? (":/images/" + imageName) : imageName);
            QImage image(qPath);
            Texture texture;
            texture.image = image;
            texture.pixmap = QPixmap::fromImage(image).scaled(pixmapsSize,  Qt::KeepAspectRatio);
            texture.path = imageName;
            textures.append(texture);

            QLabel* label = new QLabel();
            label->setMinimumSize(pixmapsSize);
            label->setMaximumSize(pixmapsSize);
            label->setPixmap(texture.pixmap);
            label->setStyleSheet("border: 1px solid; background-color:rgb(200, 200, 200)");

            int itemIndex = (textures.size() - 1);
            int column = (itemIndex % nColumns);
            int row = (itemIndex / nColumns);
            QGridLayout* layout = static_cast<QGridLayout*>(ui->scrollAreaWidgetContents->layout());
            layout->addWidget(label, row, column);

            images.append(label);
            label->installEventFilter(this);
        }

    } // namespace Particles
} // namespace MelonGames
