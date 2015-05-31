#ifndef MELONGAMES_PARTICLES_TEXTURESELECTORUI_H
#define MELONGAMES_PARTICLES_TEXTURESELECTORUI_H

#include <QWidget>
#include <QLabel>

namespace MelonGames {
    namespace Particles {

        namespace Ui {
            class TextureSelectorUI;
        }

        class TextureSelectorUI : public QWidget
        {
            Q_OBJECT

        public:
            explicit TextureSelectorUI(QWidget *parent = 0);
            ~TextureSelectorUI();

            bool eventFilter(QObject *, QEvent *) override;

            struct Texture
            {
                QImage image;
                QPixmap pixmap;
                QString path;
            };

            const Texture* getSelectedTexture() const;

        signals:
            void onSelectedTextureChanged(TextureSelectorUI* textureSelector);

        private slots:
            void on_pushButton_clicked();

        private:
            void loadTextures();
            void addTexture(const QString& imageName);

        private:
            Ui::TextureSelectorUI *ui;

            const QSize pixmapsSize;
            QVector<Texture> textures;
            int selectedTexture;

            QVector<QLabel*> images;
        };


    } // namespace Particles
} // namespace MelonGames
#endif // MELONGAMES_PARTICLES_TEXTURESELECTORUI_H
