#include "particlecontroller.h"
#include "../Scene/particlesscene.h"
#include "2d/CCParticleSystemQuad.h"

#include <QDebug>

namespace MelonGames {
namespace Particles {

ParticleController::ParticleController(QObject* parent)
    : QObject(parent)
    , scene(nullptr)
{

}

ParticleController::~ParticleController()
{

}

void ParticleController::setParticlesScene(ParticlesScene *scene)
{
    this->scene = scene;
}

void ParticleController::setUIMaxParticles(QWidget* widget)
{
    EditorWidgets editors = getEditorWidgets(widget);
    connect(editors.slider, SIGNAL(sliderMoved(int)), this, SLOT(maxParticlesChanged(int)));
    connect(editors.slider, SIGNAL(sliderMoved(int)), editors.spinBox, SLOT(setValue(int)));
    connect(editors.spinBox, SIGNAL(valueChanged(int)), this, SLOT(maxParticlesChanged(int)));
    connect(editors.spinBox, SIGNAL(valueChanged(int)), editors.slider, SLOT(setValue(int)));
}

void ParticleController::maxParticlesChanged(int value)
{
    qDebug() << "ParticleController::maxParticlesChanged(" << value << ")";
    Q_ASSERT(scene);

    scene->getParticleSystem()->setTotalParticles(value);
}

void ParticleController::setUILifespan(QWidget* widget)
{
    EditorWidgets editors = getEditorWidgets(widget);

}

ParticleController::EditorWidgets ParticleController::getEditorWidgets(QWidget* widget) const
{
    EditorWidgets result;
    result.slider = widget->findChildren<QSlider*>(QRegularExpression("horizontalSlider"), Qt::FindDirectChildrenOnly).first();
    result.spinBox = widget->findChildren<QSpinBox*>(QRegularExpression("spinBox"), Qt::FindDirectChildrenOnly).first();
    return result;
}

} // namespace Particles
} // namespace MelonGames

