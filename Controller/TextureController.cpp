#include "TextureController.h"
#include "UI/TextureSelectorUI.h"
#include <QDebug>
#include <QEvent>
#include "Scene/particlesscene.h"
#include "2d/CCParticleSystemQuad.h"
#include "renderer/CCTextureCache.h"
#include "base/CCDirector.h"

namespace MelonGames {
    namespace Particles {

        TextureController::TextureController(QObject *parent)
            : QObject(parent)
            , imageLabel(nullptr)
            , embeddedRadioButton(nullptr)
            , externalRadioButton(nullptr)
            , textureSelector(nullptr)
            , scene(nullptr)
        {
            textureSelector = new TextureSelectorUI();
            connect(textureSelector, SIGNAL(onSelectedTextureChanged(TextureSelectorUI*)), this, SLOT(onSelectedTextureChanged(TextureSelectorUI*)));
            onSelectedTextureChanged(textureSelector);
        }

        TextureController::~TextureController()
        {

        }

        void TextureController::setUIWidgets(QLabel *imageLabel, QRadioButton *embeddedRadioButton, QRadioButton *externalRadioButton)
        {
            this->imageLabel = imageLabel;
            this->embeddedRadioButton = embeddedRadioButton;
            this->externalRadioButton = externalRadioButton;

            imageLabel->installEventFilter(this);

            imageLabel->setStyleSheet("border: 1px solid; background-color:rgb(200, 200, 200)");
        }

        void TextureController::registerParticlesScene(ParticlesScene* scene)
        {
            this->scene = scene;

            onSelectedTextureChanged(textureSelector);
        }

        bool TextureController::isTextureEmbedded() const
        {
            return (embeddedRadioButton->isChecked());
        }

        const QImage* TextureController::getTextureImage(QString& outPath) const
        {
            if (const TextureSelectorUI::Texture* texture = textureSelector->getSelectedTexture())
            {
                outPath = texture->path;
                return &(texture->image);
            }

            return nullptr;
        }

        void TextureController::closeUI()
        {
            textureSelector->close();
            textureSelector = nullptr;
        }

        bool TextureController::eventFilter(QObject* watched, QEvent* event)
        {
            if (watched == imageLabel)
            {
                if (event->type() == QEvent::MouseButtonPress)
                {
                    textureSelector->show();
                    textureSelector->raise();
                }
            }

            return false;
        }

        void TextureController::onSelectedTextureChanged(TextureSelectorUI* textureSelector)
        {
            if (scene)
            {
                const TextureSelectorUI::Texture* texture = textureSelector->getSelectedTexture();
                if (texture)
                {
                    imageLabel->setPixmap(texture->pixmap.scaled(imageLabel->size(), Qt::KeepAspectRatio));

                    cocos2d::Texture2D* cocosTexture = cocos2d::Director::getInstance()->getTextureCache()->addImage(texture->path.toStdString());
                    scene->getParticleSystem(cocos2d::ParticleSystem::Mode::GRAVITY)->setTexture(cocosTexture);
                    scene->getParticleSystem(cocos2d::ParticleSystem::Mode::RADIUS)->setTexture(cocosTexture);
                }
            }
        }

    } // namespace Particles
} // namespace MelonGames

