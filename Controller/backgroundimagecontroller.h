#ifndef MELONGAMES_PARTICLES_BACKGROUNDIMAGE_H
#define MELONGAMES_PARTICLES_BACKGROUNDIMAGE_H

#include <QObject>
#include <QPushButton>
#include <QLabel>

namespace MelonGames {
namespace Particles {

class ParticlesScene;

class BackgroundImageController : public QObject
{
    Q_OBJECT
public:
    explicit BackgroundImageController(QObject* parent = nullptr);
    ~BackgroundImageController();

    void setParticlesScene(ParticlesScene* scene);
    void setChangeImageButton(QPushButton* button);
    void setImageNameLabel(QLabel* label);

    void update();

private slots:
    void onChangeImageButtonPressed();

private:
    ParticlesScene* scene;
    QPushButton* changeImageButton;
    QLabel* imageNameLabel;

    bool hasBackgroundImage;
    QString imageName;
};

} // namespace Particles
} // namespace MelonGames

#endif // MELONGAMES_PARTICLES_BACKGROUNDIMAGE_H
