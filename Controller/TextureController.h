#ifndef MELONGAMES_PARTICLES_TEXTURECONTROLLER_H
#define MELONGAMES_PARTICLES_TEXTURECONTROLLER_H

#include <QObject>
#include <QRadioButton>
#include <QLabel>
#include <QVector>
#include <QPixmap>

namespace MelonGames {
    namespace Particles {

        class TextureController : public QObject
        {
            Q_OBJECT
        public:
            explicit TextureController(QObject *parent = 0);
            ~TextureController();

            void setUIWidgets(QLabel* imageLabel, QRadioButton* embeddedRadioButton, QRadioButton* externalRadioButton);

        signals:

        public slots:
            void onRadioButtonClicked();

        private:
            void loadPixmaps();
            void reload();

        private:
            QLabel* imageLabel;
            QRadioButton* embeddedRadioButton;
            QRadioButton* externalRadioButton;

            QVector<QPixmap> pixmaps;
        };

    } // namespace Particles
} // namespace MelonGames

#endif // MELONGAMES_PARTICLES_TEXTURECONTROLLER_H
