#ifndef MELONGAMES_PARTICLES_TEXTURECONTROLLER_H
#define MELONGAMES_PARTICLES_TEXTURECONTROLLER_H

#include <QObject>
#include <QRadioButton>
#include <QLabel>
#include <QVector>
#include <QPixmap>

namespace MelonGames {
    namespace Particles {

        class TextureSelectorUI;
        class ParticlesScene;
        class TextureController : public QObject
        {
            Q_OBJECT
        public:
            explicit TextureController(QObject *parent = 0);
            ~TextureController();

            void setUIWidgets(QLabel* imageLabel, QRadioButton* embeddedRadioButton, QRadioButton* externalRadioButton);

            bool eventFilter(QObject *, QEvent *) override;

            void registerParticlesScene(ParticlesScene* scene);

            bool isTextureEmbedded() const;
            const QImage* getTextureImage(QString& outPath) const;

            void closeUI();

        private slots:
            void onSelectedTextureChanged(TextureSelectorUI* textureSelector);

        private:
            QLabel* imageLabel;
            QRadioButton* embeddedRadioButton;
            QRadioButton* externalRadioButton;

            TextureSelectorUI* textureSelector;

            ParticlesScene* scene;
        };

    } // namespace Particles
} // namespace MelonGames

#endif // MELONGAMES_PARTICLES_TEXTURECONTROLLER_H
