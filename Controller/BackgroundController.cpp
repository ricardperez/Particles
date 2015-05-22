#include "BackgroundController.h"
#include "../Scene/particlesscene.h"
#include "2d/CCParticleSystemQuad.h"
#include <QFileDialog>
#include <QColorDialog>
#include <QDebug>

namespace MelonGames {
    namespace Particles {

        BackgroundController::BackgroundController(QObject *parent)
            : QObject(parent)
            , scene(nullptr)
            , changeImageButton(nullptr)
            , imageNameLabel(nullptr)
            , hasBackgroundImage(false)
            , backgroundColorButton(nullptr)
            , positionType(cocos2d::ParticleSystem::PositionType::FREE)
            , positionTypeTest(false)
            , positionTypeTestButton(nullptr)
        {

        }

        BackgroundController::~BackgroundController()
        {

        }

        void BackgroundController::setParticlesScene(ParticlesScene *scene)
        {
            this->scene = scene;

            positionType = scene->getParticleSystem()->getPositionType();
        }

        void BackgroundController::setChangeImageButton(QPushButton *button)
        {
            Q_ASSERT(!changeImageButton);
            changeImageButton = button;

            connect(changeImageButton, SIGNAL(clicked()), this, SLOT(onChangeImageButtonPressed()));
        }

        void BackgroundController::setImageNameLabel(QLabel *label)
        {
            imageNameLabel = label;
        }

        void BackgroundController::setColorButton(QPushButton* button)
        {
            backgroundColorButton = button;

            connect(button, SIGNAL(clicked()), this, SLOT(onColorButtonPressed()));
        }

        void BackgroundController::setPositionTypeOptions(QRadioButton* freeRadioButton, QRadioButton* relativeRadioButton, QRadioButton* groupedRadioButton)
        {
            positionTypeRadioButtons.free = freeRadioButton;
            positionTypeRadioButtons.relative = relativeRadioButton;
            positionTypeRadioButtons.grouped = groupedRadioButton;

            connect(freeRadioButton, SIGNAL(clicked()), this, SLOT(onPositionTypeRadioButtonClicked()));
            connect(relativeRadioButton, SIGNAL(clicked()), this, SLOT(onPositionTypeRadioButtonClicked()));
            connect(groupedRadioButton, SIGNAL(clicked()), this, SLOT(onPositionTypeRadioButtonClicked()));
        }

        void BackgroundController::setPositionTypeTest(QPushButton* button)
        {
            positionTypeTestButton = button;

            connect(button, SIGNAL(clicked()), this, SLOT(onPositionTypeTestButtonPressed()));

            update();
        }

        void BackgroundController::update()
        {
            Q_ASSERT(scene);
            Q_ASSERT(changeImageButton);
            Q_ASSERT(imageNameLabel);
            Q_ASSERT(backgroundColorButton);
            Q_ASSERT(positionTypeTestButton);

            changeImageButton->setText(hasBackgroundImage ? "Clear" : "Add");
            imageNameLabel->setText(hasBackgroundImage ? imageName : "");

            QColor colorQ(backgroundColor.r*255, backgroundColor.g*255, backgroundColor.b*255, backgroundColor.a*255);
            backgroundColorButton->setStyleSheet(QString("background-color: %1").arg(colorQ.name()));

            switch (positionType)
            {
                case cocos2d::ParticleSystem::PositionType::FREE:
                    positionTypeRadioButtons.free->setChecked(true);
                    break;
                case cocos2d::ParticleSystem::PositionType::GROUPED:
                    positionTypeRadioButtons.grouped->setChecked(true);
                    break;
                case cocos2d::ParticleSystem::PositionType::RELATIVE:
                    positionTypeRadioButtons.relative->setChecked(true);
                    break;
                default:
                    break;
            }

            positionTypeTestButton->setText(positionTypeTest ? "Stop" : "Test");
        }

        void BackgroundController::onChangeImageButtonPressed()
        {
            Q_ASSERT(scene);

            if (!hasBackgroundImage)
            {
                imageName = QFileDialog::getOpenFileName(nullptr, "Select image", "", "Images (*.png *.png *.webp");
            }
            else
            {
                imageName.clear();
            }

            hasBackgroundImage = !imageName.isEmpty();
            if (hasBackgroundImage)
            {
                qDebug() << "Selected image: " << imageName;
                changeImageButton->setText("Clear image");
                scene->setBackgroundImage(std::string(imageName.toUtf8().constData()));
            }
            else
            {
                scene->clearBackgroundImage();
            }

            update();
        }

        void BackgroundController::onColorButtonPressed()
        {
            Q_ASSERT(scene);

            QRgb startColor = qRgba(backgroundColor.r*255, backgroundColor.g*255, backgroundColor.b*255, backgroundColor.a*255);
            bool ok = true;
            QRgb rgba = QColorDialog::getRgba(startColor, &ok);
            if (ok)
            {
                QColor color(qRed(rgba), qGreen(rgba), qBlue(rgba), qAlpha(rgba));
                backgroundColor = cocos2d::Color4B(color.red(), color.green(), color.blue(), color.alpha());

                scene->getBackgroundLayer()->setColor(cocos2d::Color3B(backgroundColor.r, backgroundColor.g, backgroundColor.b));
                scene->getBackgroundLayer()->setOpacity(backgroundColor.a);

                update();
            }
        }

        void BackgroundController::onPositionTypeRadioButtonClicked()
        {
            cocos2d::ParticleSystem::PositionType positionType = cocos2d::ParticleSystem::PositionType::FREE;
            if (positionTypeRadioButtons.free->isChecked())
            {
                positionType = cocos2d::ParticleSystem::PositionType::FREE;
            }
            else if (positionTypeRadioButtons.grouped->isChecked())
            {
                positionType = cocos2d::ParticleSystem::PositionType::GROUPED;
            }
            else if (positionTypeRadioButtons.relative->isChecked())
            {
                positionType = cocos2d::ParticleSystem::PositionType::RELATIVE;
            }

            scene->getParticleSystem(cocos2d::ParticleSystem::Mode::GRAVITY)->setPositionType(positionType);
            scene->getParticleSystem(cocos2d::ParticleSystem::Mode::RADIUS)->setPositionType(positionType);
        }

        void BackgroundController::onPositionTypeTestButtonPressed()
        {
            positionTypeTest = !positionTypeTest;

            scene->animate(positionTypeTest);

            update();
        }

    } // namespace Particles
} // namespace MelonGames

