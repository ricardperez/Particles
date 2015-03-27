#include "particlecontroller.h"
#include "../Scene/particlesscene.h"
#include "2d/CCParticleSystemQuad.h"

#include <QFile>
#include <QByteArray>
#include <QJsonDocument>
#include <QJsonValue>
#include <QColorDialog>
#include <QRgb>
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

void ParticleController::setUIStartColor(QWidget* widget)
{
    Q_ASSERT(scene);

    auto getter = [this]() -> const cocos2d::Color4F& {
            return scene->getParticleSystem()->getStartColor();
};
    auto setter = [this](const cocos2d::Color4F& value) -> void {
        scene->getParticleSystem()->setStartColor(value);
    };

    setUIElementColor(widget, getter, setter);
}

void ParticleController::setUIStartColorVar(QWidget* widget)
{
    Q_ASSERT(scene);

    auto getter = [this]() -> const cocos2d::Color4F& {
            return scene->getParticleSystem()->getStartColorVar();
};
    auto setter = [this](const cocos2d::Color4F& value) -> void {
        scene->getParticleSystem()->setStartColorVar(value);
    };

    setUIElementColor(widget, getter, setter);
}

void ParticleController::setUIEndColor(QWidget* widget)
{
    Q_ASSERT(scene);

    auto getter = [this]() -> const cocos2d::Color4F& {
            return scene->getParticleSystem()->getEndColor();
};
    auto setter = [this](const cocos2d::Color4F& value) -> void {
        scene->getParticleSystem()->setEndColor(value);
    };

    setUIElementColor(widget, getter, setter);
}

void ParticleController::setUIEndColorVar(QWidget* widget)
{
    Q_ASSERT(scene);

    auto getter = [this]() -> const cocos2d::Color4F& {
            return scene->getParticleSystem()->getEndColorVar();
};
    auto setter = [this](const cocos2d::Color4F& value) -> void {
        scene->getParticleSystem()->setEndColorVar(value);
    };

    setUIElementColor(widget, getter, setter);
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

    QList<QPushButton*> pushButtons = widget->findChildren<QPushButton*>(QRegularExpression("pushButton"), Qt::FindDirectChildrenOnly);
    result.colorButton = (pushButtons.empty() ? nullptr : pushButtons.first());

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
    attributeDescriptionSlider->callback = [editors, setter]() -> void {
        int value = editors.slider->value();
        setter(value);
        editors.spinBox->setValue(value);
    };

    AttributeDescription* attributeDescriptionSpinBox = new AttributeDescription(signalMapper);
    attributeDescriptionSpinBox->callback = [editors, setter]() -> void {
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
    attributeDescriptionSlider->callback = [editors, sliderScale, setter]() -> void {
        float value = editors.slider->value() / sliderScale;
        setter(value);
        editors.doubleSpinBox->setValue(value);
    };

    AttributeDescription* attributeDescriptionSpinBox = new AttributeDescription(signalMapper);
    attributeDescriptionSpinBox->callback = [editors, sliderScale, setter]() -> void {
        float value = editors.doubleSpinBox->value();
        setter(value);
        editors.slider->setValue(value * sliderScale);
    };

    signalMapper->setMapping(editors.slider, attributeDescriptionSlider);
    signalMapper->setMapping(editors.doubleSpinBox, attributeDescriptionSpinBox);

    connect(editors.slider, SIGNAL(sliderMoved(int)), signalMapper, SLOT(map()));
    connect(editors.doubleSpinBox, SIGNAL(valueChanged(double)), signalMapper, SLOT(map()));
}

void ParticleController::setUIElementColor(QWidget *widget, std::function<const cocos2d::Color4F&()> getter, std::function<void(const cocos2d::Color4F&)> setter)
{
    EditorWidgets editors = getEditorWidgets(widget);

    const cocos2d::Color4F& value = getter();
    QColor colorQ(value.r*255, value.g*255, value.b*255, value.a*255);
    editors.colorButton->setStyleSheet(QString("background-color: %1").arg(colorQ.name()));

    AttributeDescription* attributeDescription = new AttributeDescription(signalMapper);
    attributeDescription->callback = [getter, setter, editors]() -> void {
        const cocos2d::Color4F& value = getter();
        QRgb startColor = qRgba(value.r*255, value.g*255, value.b*255, value.a*255);
        bool ok = true;
        QRgb rgba = QColorDialog::getRgba(startColor, &ok);
        if (ok)
        {
            QColor color(qRed(rgba), qGreen(rgba), qBlue(rgba), qAlpha(rgba));
            editors.colorButton->setStyleSheet(QString("background-color: %1").arg(color.name()));
            cocos2d::Color4F endColor(color.red()/255.0f, color.green()/255.0f, color.blue()/255.0f, color.alpha()/255.0f);
            setter(endColor);
        }
    };

    signalMapper->setMapping(editors.colorButton, attributeDescription);

    connect(editors.colorButton, SIGNAL(clicked()), signalMapper, SLOT(map()));
}

void ParticleController::valueChanged(QObject* object)
{
    AttributeDescription* attributeDescription = static_cast<AttributeDescription*>(object);
    attributeDescription->callback();
}

} // namespace Particles
} // namespace MelonGames

