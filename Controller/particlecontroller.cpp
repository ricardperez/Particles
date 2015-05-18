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
            , blendFunctionBuiltInWidget(nullptr)
            , blendFunctionSourceWidget(nullptr)
            , blendFunctionDestinationWidget(nullptr)
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

        void ParticleController::reload()
        {
            for (auto& reloadFunction : reloadFunctions)
            {
                reloadFunction();
            }
        }

        void ParticleController::setUIMaxParticles(QWidget* widget)
        {
            Q_ASSERT(scene);

            auto getter = [this]()->int {
                    return scene->getParticleSystem()->getTotalParticles();
            };
            auto setter = [this](int val)->void{
                scene->getParticleSystem(cocos2d::ParticleSystem::Mode::GRAVITY)->setTotalParticles(val);
                scene->getParticleSystem(cocos2d::ParticleSystem::Mode::RADIUS)->setTotalParticles(val);
            };
            setUIElementInt(widget, "maxParticles", getter, setter);
        }

        void ParticleController::setUILifespan(QWidget* widget)
        {
            Q_ASSERT(scene);

            auto getter = [this]()->float {
                    return scene->getParticleSystem()->getLife();
            };
            auto setter = [this](int val)->void{
                scene->getParticleSystem(cocos2d::ParticleSystem::Mode::GRAVITY)->setLife(val);
                scene->getParticleSystem(cocos2d::ParticleSystem::Mode::RADIUS)->setLife(val);
            };
            setUIElementFloat(widget, "lifespan", getter, setter);
        }

        void ParticleController::setUILifespanVar(QWidget* widget)
        {
            Q_ASSERT(scene);

            auto getter = [this]()->float {
                    return scene->getParticleSystem()->getLifeVar();
            };
            auto setter = [this](int val)->void{
                scene->getParticleSystem(cocos2d::ParticleSystem::Mode::GRAVITY)->setLifeVar(val);
                scene->getParticleSystem(cocos2d::ParticleSystem::Mode::RADIUS)->setLifeVar(val);
            };
            setUIElementFloat(widget, "lifespanVar", getter, setter);
        }

        void ParticleController::setUIStartSize(QWidget* widget)
        {
            Q_ASSERT(scene);

            auto getter = [this]()->int {
                    return scene->getParticleSystem()->getStartSize();
            };
            auto setter = [this](int val)->void{
                scene->getParticleSystem(cocos2d::ParticleSystem::Mode::GRAVITY)->setStartSize(val);
                scene->getParticleSystem(cocos2d::ParticleSystem::Mode::RADIUS)->setStartSize(val);
            };
            setUIElementInt(widget, "startSize", getter, setter);
        }

        void ParticleController::setUIStartSizeVar(QWidget* widget)
        {
            Q_ASSERT(scene);

            auto getter = [this]()->int {
                    return scene->getParticleSystem()->getStartSizeVar();
            };
            auto setter = [this](int val)->void{
                scene->getParticleSystem(cocos2d::ParticleSystem::Mode::GRAVITY)->setStartSizeVar(val);
                scene->getParticleSystem(cocos2d::ParticleSystem::Mode::RADIUS)->setStartSizeVar(val);
            };
            setUIElementInt(widget, "startSizeVar", getter, setter);
        }

        void ParticleController::setUIFinishSize(QWidget* widget)
        {
            Q_ASSERT(scene);

            auto getter = [this]()->int {
                    return scene->getParticleSystem()->getEndSize();
            };
            auto setter = [this](int val)->void{
                scene->getParticleSystem(cocos2d::ParticleSystem::Mode::GRAVITY)->setEndSize(val);
                scene->getParticleSystem(cocos2d::ParticleSystem::Mode::RADIUS)->setEndSize(val);
            };
            setUIElementInt(widget, "endSize", getter, setter);
        }

        void ParticleController::setUIFinishSizeVar(QWidget* widget)
        {
            Q_ASSERT(scene);

            auto getter = [this]()->int {
                    return scene->getParticleSystem()->getEndSizeVar();
            };
            auto setter = [this](int val)->void{
                scene->getParticleSystem(cocos2d::ParticleSystem::Mode::GRAVITY)->setEndSizeVar(val);
                scene->getParticleSystem(cocos2d::ParticleSystem::Mode::RADIUS)->setEndSizeVar(val);
            };
            setUIElementInt(widget, "endSizeVar", getter, setter);
        }

        void ParticleController::setUIEmitionAngle(QWidget* widget)
        {
            Q_ASSERT(scene);

            auto getter = [this]()->float {
                    return scene->getParticleSystem()->getAngle();
            };
            auto setter = [this](int val)->void{
                scene->getParticleSystem(cocos2d::ParticleSystem::Mode::GRAVITY)->setAngle(val);
                scene->getParticleSystem(cocos2d::ParticleSystem::Mode::RADIUS)->setAngle(val);
            };
            setUIElementFloat(widget, "angleEmiton", getter, setter);
        }

        void ParticleController::setUIEmitionAngleVar(QWidget* widget)
        {
            Q_ASSERT(scene);

            auto getter = [this]()->float {
                    return scene->getParticleSystem()->getAngleVar();
            };
            auto setter = [this](int val)->void{
                scene->getParticleSystem(cocos2d::ParticleSystem::Mode::GRAVITY)->setAngleVar(val);
                scene->getParticleSystem(cocos2d::ParticleSystem::Mode::RADIUS)->setAngleVar(val);
            };
            setUIElementFloat(widget, "angleEmitonVar", getter, setter);
        }

        void ParticleController::setUIRotationStart(QWidget* widget)
        {
            Q_ASSERT(scene);

            auto getter = [this]()->int {
                    return scene->getParticleSystem()->getStartSpin();
            };
            auto setter = [this](int val)->void{
                scene->getParticleSystem(cocos2d::ParticleSystem::Mode::GRAVITY)->setStartSpin(val);
                scene->getParticleSystem(cocos2d::ParticleSystem::Mode::RADIUS)->setStartSpin(val);
            };
            setUIElementInt(widget, "rotationStart", getter, setter);
        }

        void ParticleController::setUIRotationStartVar(QWidget* widget)
        {
            Q_ASSERT(scene);

            auto getter = [this]()->int {
                    return scene->getParticleSystem()->getStartSpinVar();
            };
            auto setter = [this](int val)->void{
                scene->getParticleSystem(cocos2d::ParticleSystem::Mode::GRAVITY)->setStartSpinVar(val);
                scene->getParticleSystem(cocos2d::ParticleSystem::Mode::RADIUS)->setStartSpinVar(val);
            };
            setUIElementInt(widget, "rotationStartVar", getter, setter);
        }

        void ParticleController::setUIRotationEnd(QWidget* widget)
        {
            Q_ASSERT(scene);

            auto getter = [this]()->int {
                    return scene->getParticleSystem()->getEndSpin();;
            };
            auto setter = [this](int val)->void{
                scene->getParticleSystem(cocos2d::ParticleSystem::Mode::GRAVITY)->setEndSpin(val);
                scene->getParticleSystem(cocos2d::ParticleSystem::Mode::RADIUS)->setEndSpin(val);
            };
            setUIElementInt(widget, "rotationEnd", getter, setter);
        }

        void ParticleController::setUIRotationEndVar(QWidget* widget)
        {
            Q_ASSERT(scene);

            auto getter = [this]()->int {
                    return scene->getParticleSystem()->getEndSpinVar();
            };
            auto setter = [this](int val)->void{
                scene->getParticleSystem(cocos2d::ParticleSystem::Mode::GRAVITY)->setEndSpinVar(val);
                scene->getParticleSystem(cocos2d::ParticleSystem::Mode::RADIUS)->setEndSpinVar(val);
            };
            setUIElementInt(widget, "rotationEndVar", getter, setter);
        }

        void ParticleController::setUIStartColor(QWidget* widget)
        {
            Q_ASSERT(scene);

            auto getter = [this]() -> const cocos2d::Color4F& {
                    return scene->getParticleSystem()->getStartColor();
        };
            auto setter = [this](const cocos2d::Color4F& value) -> void {
                scene->getParticleSystem(cocos2d::ParticleSystem::Mode::GRAVITY)->setStartColor(value);
                scene->getParticleSystem(cocos2d::ParticleSystem::Mode::RADIUS)->setStartColor(value);
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
                scene->getParticleSystem(cocos2d::ParticleSystem::Mode::GRAVITY)->setStartColorVar(value);
                scene->getParticleSystem(cocos2d::ParticleSystem::Mode::RADIUS)->setStartColorVar(value);
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
                scene->getParticleSystem(cocos2d::ParticleSystem::Mode::GRAVITY)->setEndColor(value);
                scene->getParticleSystem(cocos2d::ParticleSystem::Mode::RADIUS)->setEndColor(value);
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
                scene->getParticleSystem(cocos2d::ParticleSystem::Mode::GRAVITY)->setEndColorVar(value);
                scene->getParticleSystem(cocos2d::ParticleSystem::Mode::RADIUS)->setEndColorVar(value);
            };

            setUIElementColor(widget, getter, setter);
        }

        void ParticleController::setUIBlendFunctionBuiltIn(QWidget* widget)
        {
            blendFunctionBuiltInWidget = widget;

            EditorWidgets editors = getEditorWidgets(widget);
            QComboBox* comboBox = editors.comboBox;
            comboBox->clear();

            const cocos2d::BlendFunc& blendFunc = scene->getParticleSystem()->getBlendFunc();

            comboBox->addItem("CUSTOM");
            int selectedIndex = 0;
            int i = 1;

            QJsonObject json = getAttributeDescription("blendFunction");
            for (const QJsonValue& jsonValue : json["values"].toArray())
            {
                QJsonObject valueObj = jsonValue.toObject();
                QString text = valueObj["name"].toString();
                int srcValue = valueObj["src"].toInt();
                int dstValue = valueObj["dst"].toInt();

                QList<QVariant> list;
                list << QVariant(srcValue) << QVariant(dstValue);
                comboBox->addItem(text, list);

                if (srcValue == blendFunc.src && dstValue == blendFunc.src)
                {
                    selectedIndex = i;
                }
                ++i;
            }

            comboBox->setCurrentIndex(selectedIndex);

            auto setter = [this, comboBox](int val) -> void {
                int srcValue = 0;
                int dstValue = 0;

                EditorWidgets srcEditors = getEditorWidgets(blendFunctionSourceWidget);
                EditorWidgets dstEditors = getEditorWidgets(blendFunctionDestinationWidget);
                QJsonObject json = getAttributeDescription("blendFunctionCustom");

                if (val != 0)
                {
                    QVariant data = comboBox->itemData(val);
                    QList<QVariant> list = data.toList();
                    srcValue = list.at(0).toInt();
                    dstValue = list.at(1).toInt();

                    auto indexGetter = [json](int value) -> int
                    {
                        int i = 0;
                        for (const QJsonValue& jsonValue : json["values"].toArray())
                        {
                            int intValue = jsonValue.toObject()["value"].toInt();
                            if (intValue == value)
                            {
                                return i;
                            }
                            ++i;
                        }

                        return 0;
                    };

                    srcEditors.comboBox->setCurrentIndex(indexGetter(srcValue));
                    dstEditors.comboBox->setCurrentIndex(indexGetter(dstValue));
                }
                else
                {
                    int srcIndex = srcEditors.comboBox->currentIndex();
                    srcValue = json["values"].toArray().at(srcIndex).toObject()["value"].toInt();

                    int dstIndex = dstEditors.comboBox->currentIndex();
                    dstValue = json["values"].toArray().at(dstIndex).toObject()["value"].toInt();
                }

                cocos2d::BlendFunc blendFunc;
                blendFunc.src = srcValue;
                blendFunc.dst = dstValue;
                scene->getParticleSystem(cocos2d::ParticleSystem::Mode::GRAVITY)->setBlendFunc(blendFunc);
                scene->getParticleSystem(cocos2d::ParticleSystem::Mode::RADIUS)->setBlendFunc(blendFunc);
                updateBlendFunctionWidgets();
            };

            updateBlendFunctionWidgets();

            AttributeDescription* attributeDescription = new AttributeDescription(this);
            attributeDescription->callback = [comboBox, setter]() -> void {
                int index = comboBox->currentIndex();
                setter(index);
            };
            signalMapper->setMapping(comboBox, attributeDescription);
            connect(comboBox, SIGNAL(currentIndexChanged(int)), signalMapper, SLOT(map()));
        }

        void ParticleController::setUIBlendFunctionSource(QWidget* widget)
        {
            Q_ASSERT(scene);

            blendFunctionSourceWidget = widget;

            auto getter = [this]() -> int {
                    return (int)scene->getParticleSystem()->getBlendFunc().src;
            };
            auto setter = [this](int val)->void{
                cocos2d::BlendFunc blendFunc = scene->getParticleSystem()->getBlendFunc();
                blendFunc.src = val;
                scene->getParticleSystem(cocos2d::ParticleSystem::Mode::GRAVITY)->setBlendFunc(blendFunc);
                scene->getParticleSystem(cocos2d::ParticleSystem::Mode::RADIUS)->setBlendFunc(blendFunc);
            };
            setUIElementComboBox(widget, "blendFunctionCustom", getter, setter);

            updateBlendFunctionWidgets();
        }

        void ParticleController::setUIBlendFunctionDestination(QWidget* widget)
        {
            Q_ASSERT(scene);

            blendFunctionDestinationWidget = widget;

            auto getter = [this]() -> int {
                    return (int)scene->getParticleSystem()->getBlendFunc().dst;
            };
            auto setter = [this](int val)->void{
                cocos2d::BlendFunc blendFunc = scene->getParticleSystem()->getBlendFunc();
                blendFunc.dst = val;
                scene->getParticleSystem(cocos2d::ParticleSystem::Mode::GRAVITY)->setBlendFunc(blendFunc);
                scene->getParticleSystem(cocos2d::ParticleSystem::Mode::RADIUS)->setBlendFunc(blendFunc);
            };
            setUIElementComboBox(widget, "blendFunctionCustom", getter, setter);

            updateBlendFunctionWidgets();
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

            QList<QComboBox*> comboBoxes = widget->findChildren<QComboBox*>(QRegularExpression("comboBox"), Qt::FindDirectChildrenOnly);
            result.comboBox = (comboBoxes.empty() ? nullptr : comboBoxes.first());

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

        void ParticleController::setUIElementInt(QWidget* widget, const QString& key, std::function<int(void)> getter, std::function<void(int)> setter)
        {
            EditorWidgets editors = getEditorWidgets(widget);

            QJsonObject json = getAttributeDescription(key);

            const int min = json["min"].toInt();
            const int max = json["max"].toInt();

            editors.slider->setMinimum(min);
            editors.slider->setMaximum(max);
            editors.spinBox->setMinimum(min);
            editors.spinBox->setMaximum(max);

            auto reloader = [getter, editors]()->void {
                int value = getter();
                editors.slider->setValue(value);
                editors.spinBox->setValue(value);
            };
            reloadFunctions.push_back(reloader);
            reloader();

            AttributeDescription* attributeDescriptionSlider = new AttributeDescription(this);
            attributeDescriptionSlider->callback = [editors, setter]() -> void {
                int value = editors.slider->value();
                setter(value);
                editors.spinBox->setValue(value);
            };

            AttributeDescription* attributeDescriptionSpinBox = new AttributeDescription(this);
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

        void ParticleController::setUIElementFloat(QWidget* widget, const QString& key, std::function<float(void)> getter, std::function<void(float)> setter)
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

            auto reloader = [getter, editors, sliderScale]()->void {
                float value = getter();
                editors.slider->setValue(value * sliderScale);
                editors.doubleSpinBox->setValue(value);
            };
            reloadFunctions.push_back(reloader);
            reloader();

            AttributeDescription* attributeDescriptionSlider = new AttributeDescription(this);
            attributeDescriptionSlider->callback = [editors, sliderScale, setter]() -> void {
                float value = editors.slider->value() / sliderScale;
                setter(value);
                editors.doubleSpinBox->setValue(value);
            };

            AttributeDescription* attributeDescriptionSpinBox = new AttributeDescription(this);
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

            auto reloader = [getter, editors]()->void{
                const cocos2d::Color4F& value = getter();
                QColor colorQ(value.r*255, value.g*255, value.b*255, value.a*255);
                editors.colorButton->setStyleSheet(QString("background-color: %1").arg(colorQ.name()));
            };
            reloadFunctions.push_back(reloader);
            reloader();

            AttributeDescription* attributeDescription = new AttributeDescription(this);
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


        void ParticleController::setUIElementComboBox(QWidget* widget, const QString& key, std::function<int(void)> getter, std::function<void(int)> setter)
        {
            EditorWidgets editors = getEditorWidgets(widget);
            editors.comboBox->clear();

            QJsonObject json = getAttributeDescription(key);
            for (const QJsonValue& jsonValue : json["values"].toArray())
            {
                QJsonObject valueObj = jsonValue.toObject();
                QString text = valueObj["name"].toString();
                int intValue = jsonValue.toObject()["value"].toInt();
                editors.comboBox->addItem(text, QVariant(intValue));
            }

            auto reloader = [this, key, getter, editors]() -> void {
                int value = getter();
                int selectedIndex = 0;
                int i = 0;
                QJsonObject json = getAttributeDescription(key);
                for (const QJsonValue& jsonValue : json["values"].toArray())
                {
                    int intValue = jsonValue.toObject()["value"].toInt();
                    if (intValue == value)
                    {
                        selectedIndex = i;
                        break;
                    }
                    ++i;
                }

                editors.comboBox->setCurrentIndex(selectedIndex);
            };
            reloader();
            reloadFunctions.push_back(reloader);

            AttributeDescription* attributeDescription = new AttributeDescription(this);
            attributeDescription->callback = [editors, setter, this, key]() -> void {
                int index = editors.comboBox->currentIndex();
                QJsonObject json = getAttributeDescription(key);
                int value = json["values"].toArray().at(index).toObject()["value"].toInt();
                setter(value);
            };
            signalMapper->setMapping(editors.comboBox, attributeDescription);
            connect(editors.comboBox, SIGNAL(currentIndexChanged(int)), signalMapper, SLOT(map()));
        }

        void ParticleController::valueChanged(QObject* object)
        {
            AttributeDescription* attributeDescription = static_cast<AttributeDescription*>(object);
            attributeDescription->callback();
        }

        void ParticleController::updateBlendFunctionWidgets()
        {
            if (scene && blendFunctionBuiltInWidget && blendFunctionSourceWidget && blendFunctionDestinationWidget)
            {
                EditorWidgets builtInEditors = getEditorWidgets(blendFunctionBuiltInWidget);
                bool customBlendFunc = (builtInEditors.comboBox->currentIndex() == 0);

                QString stylesheet = (customBlendFunc ? "" : "color:gray");
                blendFunctionSourceWidget->setStyleSheet(stylesheet);
                blendFunctionDestinationWidget->setStyleSheet(stylesheet);

                blendFunctionSourceWidget->setEnabled(customBlendFunc);
                blendFunctionDestinationWidget->setEnabled(customBlendFunc);
            }
        }

    } // namespace Particles
} // namespace MelonGames

