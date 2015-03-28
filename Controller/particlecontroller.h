#ifndef MELONGAMES_PARTICLES_PARTICLECONTROLLER_H
#define MELONGAMES_PARTICLES_PARTICLECONTROLLER_H

#include <QObject>
#include <QWidget>
#include <QSlider>
#include <QSpinBox>
#include <QDoubleSpinBox>
#include <QPushButton>
#include <QJsonArray>
#include <QJsonObject>
#include <QSignalMapper>
#include <QComboBox>
#include <functional>

namespace cocos2d
{
class Color4F;
}

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
    void setUILifespanVar(QWidget* widget);
    void setUIStartSize(QWidget* widget);
    void setUIStartSizeVar(QWidget* widget);
    void setUIFinishSize(QWidget* widget);
    void setUIFinishSizeVar(QWidget* widget);
    void setUIEmitionAngle(QWidget* widget);
    void setUIEmitionAngleVar(QWidget* widget);
    void setUIRotationStart(QWidget* widget);
    void setUIRotationStartVar(QWidget* widget);
    void setUIRotationEnd(QWidget* widget);
    void setUIRotationEndVar(QWidget* widget);

    void setUIStartColor(QWidget* widget);
    void setUIStartColorVar(QWidget* widget);
    void setUIEndColor(QWidget* widget);
    void setUIEndColorVar(QWidget* widget);

    void setUIBlendFunctionBuiltIn(QWidget* widget);
    void setUIBlendFunctionSource(QWidget* widget);
    void setUIBlendFunctionDestination(QWidget* widget);

private slots:
    void valueChanged(QObject* object);

private:
    struct EditorWidgets
    {
        QSlider* slider;
        QSpinBox* spinBox;
        QDoubleSpinBox* doubleSpinBox;
        QPushButton* colorButton;
        QComboBox* comboBox;
    };
    EditorWidgets getEditorWidgets(QWidget* parent) const;
    QJsonObject getAttributeDescription(const QString& key) const;

    void setUIElementInt(QWidget* widget, const QString& key, int value, std::function<void(int)> setter);
    void setUIElementFloat(QWidget* widget, const QString& key, float value, std::function<void(float)> setter);
    void setUIElementColor(QWidget* widget, std::function<const cocos2d::Color4F&()> getter, std::function<void(const cocos2d::Color4F&)> setter);
    void setUIElementComboBox(QWidget* widget, const QString& key, int value, std::function<void(int)> setter);

private:
    ParticlesScene* scene;
    QJsonArray attributesDescription;
    QSignalMapper* signalMapper;
};


class AttributeDescription : public QObject
{
    Q_OBJECT
public:
    explicit AttributeDescription(QObject* parent = 0);
    std::function<void(void)> callback;
};

} // namespace Particles
} // namespace MelonGames

#endif // MELONGAMES_PARTICLES_PARTICLECONTROLLER_H
