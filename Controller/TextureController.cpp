#include "TextureController.h"
#include <QDebug>
#include <QFile>
#include <QJsonDocument>
#include <QJsonValue>
#include <QJsonArray>

namespace MelonGames {
    namespace Particles {

        TextureController::TextureController(QObject *parent)
            : QObject(parent)
            , imageLabel(nullptr)
            , embeddedRadioButton(nullptr)
            , externalRadioButton(nullptr)
        {
        }

        TextureController::~TextureController()
        {

        }

        void TextureController::setUIWidgets(QLabel *imageLabel, QRadioButton *embeddedRadioButton, QRadioButton *externalRadioButton)
        {
            this->imageLabel = imageLabel;
            this->embeddedRadioButton = embeddedRadioButton;
            this->externalRadioButton = externalRadioButton;

            connect(embeddedRadioButton, SIGNAL(clicked()), this, SLOT(onRadioButtonClicked()));
            connect(externalRadioButton, SIGNAL(clicked()), this, SLOT(onRadioButtonClicked()));

            loadPixmaps();

            reload();
        }

        void TextureController::onRadioButtonClicked()
        {
            qDebug() << "Hey!";
        }

        void TextureController::loadPixmaps()
        {
            Q_ASSERT(imageLabel != nullptr && "Need the imageLabel to know the size the pixmaps need to be scaled to");

            QFile file("://ImagesList.json");
            file.open(QIODevice::ReadOnly | QIODevice::Text);
            QByteArray fileContents = file.readAll();
            file.close();

            QJsonArray imagesArray = QJsonDocument::fromJson(fileContents).array();
            for (QJsonValue imageJson : imagesArray)
            {
                QString imageName = imageJson.toString();
                QImage image(imageName);
                pixmaps.push_back(QPixmap::fromImage(image).scaled(imageLabel->size(), Qt::KeepAspectRatio));
            }
        }

        void TextureController::reload()
        {
            imageLabel->setPixmap(pixmaps.front());
        }

    } // namespace Particles
} // namespace MelonGames

