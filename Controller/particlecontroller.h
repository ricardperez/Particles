#ifndef MELONGAMES_PARTICLES_PARTICLECONTROLLER_H
#define MELONGAMES_PARTICLES_PARTICLECONTROLLER_H

#include <QObject>
#include <QWidget>
#include <QSlider>
#include <QSpinBox>

namespace MelonGames {
namespace Particles {

class ParticlesScene;
class ParticleController : public QObject
{
    Q_OBJECT
public:
    explicit ParticleController(QObject* parent = nullptr);
    ~ParticleController();

    void setParticlesScene(ParticlesScene* scene);

    void setUIMaxParticles(QWidget* widget);
    void setUILifespan(QWidget* widget);

private slots:
    void maxParticlesChanged(int value);

private:
    struct EditorWidgets
    {
        QSlider* slider;
        QSpinBox* spinBox;
    };
    EditorWidgets getEditorWidgets(QWidget* parent) const;

private:
    ParticlesScene* scene;
};

} // namespace Particles
} // namespace MelonGames

#endif // MELONGAMES_PARTICLES_PARTICLECONTROLLER_H
