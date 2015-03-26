#ifndef MELONGAMES_PARTICLES_PARTICLECONTROLLER_H
#define MELONGAMES_PARTICLES_PARTICLECONTROLLER_H

#include <QObject>
#include <QWidget>
#include <QSlider>
#include <QSpinBox>
#include <QDoubleSpinBox>
#include <QJsonArray>
#include <QJsonObject>
#include <QSignalMapper>
#include <functional>

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

private slots:
    void valueChanged(QObject* object);

private:
    struct EditorWidgets
    {
        QSlider* slider;
        QSpinBox* spinBox;
        QDoubleSpinBox* doubleSpinBox;
    };
    EditorWidgets getEditorWidgets(QWidget* parent) const;
    QJsonObject getAttributeDescription(const QString& key) const;

    void setUIElementInt(QWidget* widget, const QString& key, int value, std::function<void(int)> setter);
    void setUIElementFloat(QWidget* widget, const QString& key, float value, std::function<void(float)> setter);

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

    enum class Type
    {
        eInt,
        eFloat
    };
    Type type;

    enum class Source
    {
        eSlider,
        eSpinBox
    };
    Source source;

    struct
    {
        std::function<void(void)> typeInt;
        std::function<void(void)> typeFloat;
    } callback;
};

} // namespace Particles
} // namespace MelonGames

#endif // MELONGAMES_PARTICLES_PARTICLECONTROLLER_H
