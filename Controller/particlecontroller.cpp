#include "particlecontroller.h"
#include "../Scene/particlesscene.h"
#include "2d/CCParticleSystemQuad.h"

#include <QFile>
#include <QByteArray>
#include <QJsonDocument>
#include <QJsonValue>
#include <QDebug>

namespace MelonGames {
namespace Particles {

AttributeDescription::AttributeDescription(QObject* parent)
    : QObject(parent)
{
}

ParticleController::ParticleController(QObject* parent)
    : QObject(parent)
    , scene(nullptr)
{
    QFile file("://ParticleControllerAttributes.json");
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    QByteArray fileContents = file.readAll();
    file.close();

    attributesDescription = QJsonDocument::fromJson(fileContents).array();

    signalMapper = new QSignalMapper(this);
    connect(signalMapper, SIGNAL(mapped(QObject*)), this, SLOT(valueChanged(QObject*)));
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
    Q_ASSERT(scene);

    int value = scene->getParticleSystem()->getTotalParticles();
    auto setter = [this](int val)->void{
        scene->getParticleSystem()->setTotalParticles(val);
    };
    setUIElementInt(widget, "maxParticles", value, setter);
}

void ParticleController::setUILifespan(QWidget* widget)
{
    Q_ASSERT(scene);

    float value = scene->getParticleSystem()->getLife();
    auto setter = [this](int val)->void{
        scene->getParticleSystem()->setLife(val);
    };
    setUIElementFloat(widget, "lifespan", value, setter);
}

void ParticleController::setUILifespanVar(QWidget* widget)
{
    Q_ASSERT(scene);

    float value = scene->getParticleSystem()->getLifeVar();
    auto setter = [this](int val)->void{
        scene->getParticleSystem()->setLifeVar(val);
    };
    setUIElementFloat(widget, "lifespanVar", value, setter);
}

void ParticleController::setUIStartSize(QWidget* widget)
{
    Q_ASSERT(scene);

    int value = scene->getParticleSystem()->getStartSize();
    auto setter = [this](int val)->void{
        scene->getParticleSystem()->setStartSize(val);
    };
    setUIElementInt(widget, "startSize", value, setter);
}

void ParticleController::setUIStartSizeVar(QWidget* widget)
{
    Q_ASSERT(scene);

    int value = scene->getParticleSystem()->getStartSizeVar();
    auto setter = [this](int val)->void{
        scene->getParticleSystem()->setStartSizeVar(val);
    };
    setUIElementInt(widget, "startSizeVar", value, setter);
}

void ParticleController::setUIFinishSize(QWidget* widget)
{
    Q_ASSERT(scene);

    int value = scene->getParticleSystem()->getEndSize();
    auto setter = [this](int val)->void{
        scene->getParticleSystem()->setEndSize(val);
    };
    setUIElementInt(widget, "endSize", value, setter);
}

void ParticleController::setUIFinishSizeVar(QWidget* widget)
{
    Q_ASSERT(scene);

    int value = scene->getParticleSystem()->getEndSizeVar();
    auto setter = [this](int val)->void{
        scene->getParticleSystem()->setEndSizeVar(val);
    };
    setUIElementInt(widget, "endSizeVar", value, setter);
}

void ParticleController::setUIEmitionAngle(QWidget* widget)
{
    Q_ASSERT(scene);

    float value = scene->getParticleSystem()->getAngle();
    auto setter = [this](int val)->void{
        scene->getParticleSystem()->setAngle(val);
    };
    setUIElementFloat(widget, "angleEmiton", value, setter);
}

void ParticleController::setUIEmitionAngleVar(QWidget* widget)
{
    Q_ASSERT(scene);

    float value = scene->getParticleSystem()->getAngleVar();
    auto setter = [this](int val)->void{
        scene->getParticleSystem()->setAngleVar(val);
    };
    setUIElementFloat(widget, "angleEmitonVar", value, setter);
}

void ParticleController::setUIRotationStart(QWidget* widget)
{
    Q_ASSERT(scene);

    int value = scene->getParticleSystem()->getStartSpin();
    auto setter = [this](int val)->void{
        scene->getParticleSystem()->setStartSpin(val);
    };
    setUIElementInt(widget, "rotationStart", value, setter);
}

void ParticleController::setUIRotationStartVar(QWidget* widget)
{
    Q_ASSERT(scene);

    int value = scene->getParticleSystem()->getStartSpinVar();
    auto setter = [this](int val)->void{
        scene->getParticleSystem()->setStartSpinVar(val);
    };
    setUIElementInt(widget, "rotationStartVar", value, setter);
}

void ParticleController::setUIRotationEnd(QWidget* widget)
{
    Q_ASSERT(scene);

    int value = scene->getParticleSystem()->getEndSpin();
    auto setter = [this](int val)->void{
        scene->getParticleSystem()->setEndSpin(val);
    };
    setUIElementInt(widget, "rotationEnd", value, setter);
}

void ParticleController::setUIRotationEndVar(QWidget* widget)
{
    Q_ASSERT(scene);

    int value = scene->getParticleSystem()->getEndSpinVar();
    auto setter = [this](int val)->void{
        scene->getParticleSystem()->setEndSpinVar(val);
    };
    setUIElementInt(widget, "rotationEndVar", value, setter);
}

ParticleController::EditorWidgets ParticleController::getEditorWidgets(QWidget* widget) const
{
    EditorWidgets result;

    QList<QSlider*> sliders = widget->findChildren<QSlider*>(QRegularExpression("horizontalSlider"), Qt::FindDirectChildrenOnly);
    result.slider = (sliders.empty() ? nullptr : sliders.first());

    QList<QSpinBox*> spinBoxes = widget->findChildren<QSpinBox*>(QRegularExpression("spinBox"), Qt::FindDirectChildrenOnly);
    result.spinBox = (spinBoxes.empty() ? nullptr : spinBoxes.first());

    QList<QDoubleSpinBox*> doubleSpinBoxes = widget->findChildren<QDoubleSpinBox*>(QRegularExpression("doubleSpinBox"), Qt::FindDirectChildrenOnly);
    result.doubleSpinBox = (doubleSpinBoxes.empty() ? nullptr : doubleSpinBoxes.first());

    return result;
}

QJsonObject ParticleController::getAttributeDescription(const QString& key) const
{
    for (const QJsonValue& value : attributesDescription)
    {
        QJsonObject object = value.toObject();
        if (object["id"].toString() == key)
        {
            return object;
        }
    }

    return QJsonObject();
}

void ParticleController::setUIElementInt(QWidget* widget, const QString& key, int value, std::function<void(int)> setter)
{
    EditorWidgets editors = getEditorWidgets(widget);

    QJsonObject json = getAttributeDescription(key);

    const int min = json["min"].toInt();
    const int max = json["max"].toInt();

    editors.slider->setMinimum(min);
    editors.slider->setMaximum(max);
    editors.spinBox->setMinimum(min);
    editors.spinBox->setMaximum(max);

    editors.slider->setValue(value);
    editors.spinBox->setValue(value);

    AttributeDescription* attributeDescriptionSlider = new AttributeDescription(signalMapper);
    attributeDescriptionSlider->source = AttributeDescription::Source::eSlider;
    attributeDescriptionSlider->type = AttributeDescription::Type::eInt;
    attributeDescriptionSlider->callback.typeInt = [editors, setter]() -> void {
        int value = editors.slider->value();
        setter(value);
        editors.spinBox->setValue(value);
    };

    AttributeDescription* attributeDescriptionSpinBox = new AttributeDescription(signalMapper);
    attributeDescriptionSpinBox->source = AttributeDescription::Source::eSpinBox;
    attributeDescriptionSpinBox->type = AttributeDescription::Type::eInt;
    attributeDescriptionSpinBox->callback.typeInt = [editors, setter]() -> void {
        int value = editors.spinBox->value();
        setter(value);
        editors.slider->setValue(value);
    };

    signalMapper->setMapping(editors.slider, attributeDescriptionSlider);
    signalMapper->setMapping(editors.spinBox, attributeDescriptionSpinBox);

    connect(editors.slider, SIGNAL(sliderMoved(int)), signalMapper, SLOT(map()));
    connect(editors.spinBox, SIGNAL(valueChanged(int)), signalMapper, SLOT(map()));
}

void ParticleController::setUIElementFloat(QWidget* widget, const QString& key, float value, std::function<void(float)> setter)
{
    EditorWidgets editors = getEditorWidgets(widget);
    QJsonObject json = getAttributeDescription(key);

    const double min = json["min"].toDouble();
    const double max = json["max"].toDouble();
    const double sliderScale = json["sliderScale"].toDouble();

    editors.slider->setMinimum(min);
    editors.slider->setMaximum(max*sliderScale);
    editors.doubleSpinBox->setMinimum(min);
    editors.doubleSpinBox->setMaximum(max);
    editors.doubleSpinBox->setDecimals(std::log10(sliderScale));

    editors.slider->setValue(value * sliderScale);
    editors.doubleSpinBox->setValue(value);

    AttributeDescription* attributeDescriptionSlider = new AttributeDescription(signalMapper);
    attributeDescriptionSlider->source = AttributeDescription::Source::eSlider;
    attributeDescriptionSlider->type = AttributeDescription::Type::eFloat;
    attributeDescriptionSlider->callback.typeFloat = [editors, sliderScale, setter]() -> void {
        float value = editors.slider->value() / sliderScale;
        setter(value);
        editors.doubleSpinBox->setValue(value);
    };

    AttributeDescription* attributeDescriptionSpinBox = new AttributeDescription(signalMapper);
    attributeDescriptionSpinBox->source = AttributeDescription::Source::eSpinBox;
    attributeDescriptionSpinBox->type = AttributeDescription::Type::eFloat;
    attributeDescriptionSpinBox->callback.typeFloat = [editors, sliderScale, setter]() -> void {
        float value = editors.doubleSpinBox->value();
        setter(value);
        editors.slider->setValue(value * sliderScale);
    };

    signalMapper->setMapping(editors.slider, attributeDescriptionSlider);
    signalMapper->setMapping(editors.doubleSpinBox, attributeDescriptionSpinBox);

    connect(editors.slider, SIGNAL(sliderMoved(int)), signalMapper, SLOT(map()));
    connect(editors.doubleSpinBox, SIGNAL(valueChanged(double)), signalMapper, SLOT(map()));
}

void ParticleController::valueChanged(QObject* object)
{
    AttributeDescription* attributeDescription = static_cast<AttributeDescription*>(object);

    if (attributeDescription->type == AttributeDescription::Type::eFloat)
    {
        attributeDescription->callback.typeFloat();
    }
    else
    {
        attributeDescription->callback.typeInt();
    }
}

} // namespace Particles
} // namespace MelonGames

