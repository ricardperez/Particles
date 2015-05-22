#ifndef MELONGAMES_PARTICLES_BACKGROUNDCONTROLLER_H
#define MELONGAMES_PARTICLES_BACKGROUNDCONTROLLER_H

#include <QObject>
#include <QPushButton>
#include <QLabel>
#include <QRadioButton>
#include "base/ccTypes.h"
#include "2d/CCParticleSystem.h"

namespace MelonGames {
    namespace Particles {

        class ParticlesScene;

        class BackgroundController : public QObject
        {
            Q_OBJECT
        public:
            explicit BackgroundController(QObject *parent = 0);
            ~BackgroundController();

            void setParticlesScene(ParticlesScene* scene);

            void setChangeImageButton(QPushButton* button);
            void setImageNameLabel(QLabel* label);

            void setColorButton(QPushButton* button);

            void setPositionTypeOptions(QRadioButton* freeRadioButton, QRadioButton* relativeRadioButton, QRadioButton* groupedRadioButton);
            void setPositionTypeTest(QPushButton* button);

            void update();

        private slots:
            void onChangeImageButtonPressed();
            void onColorButtonPressed();
            void onPositionTypeRadioButtonClicked();
            void onPositionTypeTestButtonPressed();

        private:
            ParticlesScene* scene;
            QPushButton* changeImageButton;
            QLabel* imageNameLabel;

            bool hasBackgroundImage;
            QString imageName;

            QPushButton* backgroundColorButton;
            cocos2d::Color4B backgroundColor;

            struct PositionTypeRadioButtons
            {
                QRadioButton* free;
                QRadioButton* relative;
                QRadioButton* grouped;

                PositionTypeRadioButtons() : free(nullptr), relative(nullptr), grouped(nullptr) {}
            } positionTypeRadioButtons;
            cocos2d::ParticleSystem::PositionType positionType;

            QPushButton* positionTypeTestButton;
            bool positionTypeTest;
        };

    } // namespace Particles
} // namespace MelonGames

#endif // MELONGAMES_PARTICLES_BACKGROUNDCONTROLLER_H
