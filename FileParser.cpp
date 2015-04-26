#include "FileParser.h"
#include "platform/CCFileUtils.h"
#include "2d/CCParticleSystemQuad.h"

namespace MelonGames {
    namespace Particles {

        FileParser::FileParser(QObject *parent) : QObject(parent)
        {

        }

        FileParser::~FileParser()
        {

        }

        void FileParser::load(const QString& filePath, cocos2d::ParticleSystemQuad* particleSystem)
        {
            cocos2d::ValueMap valueMap = cocos2d::FileUtils::getInstance()->getValueMapFromFile(filePath.toUtf8().constData());

            particleSystem->setTotalParticles(valueMap["maxParticles"].asInt());
            particleSystem->setAngle(valueMap["angle"].asFloat());
            particleSystem->setAngleVar(valueMap["angleVariance"].asFloat());
            particleSystem->setDuration(valueMap["duration"].asFloat());

            cocos2d::BlendFunc blendFunc;
            blendFunc.src = valueMap["blendFuncSource"].asInt();
            blendFunc.dst = valueMap["blendFuncDestination"].asInt();
            particleSystem->setBlendFunc(blendFunc);

            cocos2d::Color4F startColor;
            startColor.r = valueMap["startColorRed"].asFloat();
            startColor.g = valueMap["startColorGreen"].asFloat();
            startColor.b = valueMap["startColorBlue"].asFloat();
            startColor.a = valueMap["startColorAlpha"].asFloat();
            particleSystem->setStartColor(startColor);

            cocos2d::Color4F startColorVar;
            startColorVar.r = valueMap["startColorVarianceRed"].asFloat();
            startColorVar.g = valueMap["startColorVarianceGreen"].asFloat();
            startColorVar.b = valueMap["startColorVarianceBlue"].asFloat();
            startColorVar.a = valueMap["startColorVarianceAlpha"].asFloat();
            particleSystem->setStartColorVar(startColorVar);

            cocos2d::Color4F endColor;
            endColor.r = valueMap["finishColorRed"].asFloat();
            endColor.g = valueMap["finishColorGreen"].asFloat();
            endColor.b = valueMap["finishColorBlue"].asFloat();
            endColor.a = valueMap["finishColorAlpha"].asFloat();
            particleSystem->setEndColor(endColor);

            cocos2d::Color4F endColorVar;
            endColorVar.r = valueMap["finishColorVarianceRed"].asFloat();
            endColorVar.g = valueMap["finishColorVarianceGreen"].asFloat();
            endColorVar.b = valueMap["finishColorVarianceBlue"].asFloat();
            endColorVar.a = valueMap["finishColorVarianceAlpha"].asFloat();
            particleSystem->setEndColorVar(endColorVar);

            particleSystem->setStartSize(valueMap["startParticleSize"].asFloat());
            particleSystem->setStartSizeVar(valueMap["startParticleSizeVariance"].asFloat());
            particleSystem->setEndSize(valueMap["finishParticleSize"].asFloat());
            particleSystem->setEndSizeVar(valueMap["finishParticleSizeVariance"].asFloat());

            cocos2d::Vec2 sourcePosition;
            sourcePosition.x = valueMap["sourcePositionX"].asFloat();
            sourcePosition.y = valueMap["sourcePositionY"].asFloat();
            particleSystem->setSourcePosition(sourcePosition);
            particleSystem->setPosition(sourcePosition);

            cocos2d::Vec2 sourcePositionVar;
            sourcePositionVar.x = valueMap["sourcePositionVariancex"].asFloat();
            sourcePositionVar.y = valueMap["sourcePositionVarianceY"].asFloat();
            particleSystem->setPosVar(sourcePositionVar);

            particleSystem->setStartSpin(valueMap["rotationStart"].asFloat());
            particleSystem->setStartSpinVar(valueMap["rotationStartVariance"].asFloat());
            particleSystem->setEndSpin(valueMap["rotationEnd"].asFloat());
            particleSystem->setEndSpinVar(valueMap["rotationEndVariance"].asFloat());

            particleSystem->setEmitterMode((cocos2d::ParticleSystem::Mode)valueMap["emitterType"].asInt());
            if (particleSystem->getEmitterMode() == cocos2d::ParticleSystem::Mode::GRAVITY)
            {
                cocos2d::Vec2 gravity;
                gravity.x = valueMap["gravityx"].asFloat();
                gravity.y = valueMap["gravityy"].asFloat();
                particleSystem->setGravity(gravity);
                particleSystem->setSpeed(valueMap["speed"].asFloat());
                particleSystem->setSpeedVar(valueMap["speedVariance"].asFloat());
                particleSystem->setRadialAccel(valueMap["radialAcceleration"].asFloat());
                particleSystem->setRadialAccelVar(valueMap["radialAccelVariance"].asFloat());
                particleSystem->setTangentialAccel(valueMap["tangentialAcceleration"].asFloat());
                particleSystem->setTangentialAccelVar(valueMap["tangentialAccelerationVariance"].asFloat());
                particleSystem->setRotationIsDir(valueMap["rotationIsDir"].asBool());
            }
            else
            {
                particleSystem->setStartRadius(valueMap["maxRadius"].asFloat());
                particleSystem->setStartRadiusVar(valueMap["maxRadiusVariance"].asFloat());
                particleSystem->setEndRadius(valueMap["minRadius"].asFloat());
                particleSystem->setEndRadiusVar(valueMap["minRadiusVariance"].asFloat());
                particleSystem->setRotatePerSecond(valueMap["rotatePerSecond"].asFloat());
                particleSystem->setRotatePerSecondVar(valueMap["rotatePerSecondVariance"].asFloat());
            }

            particleSystem->setLife(valueMap["particleLifespan"].asFloat());
            particleSystem->setLifeVar(valueMap["particleLifespanVariance"].asFloat());
        }

        void FileParser::save(const QString& filePath, const cocos2d::ParticleSystemQuad* particleSystem, const std::string& textureFileName)
        {
            cocos2d::ValueMap valueMap;
            convertParticleSystemToValueMap(particleSystem, textureFileName, valueMap);

            cocos2d::FileUtils::getInstance()->writeToFile(valueMap, filePath.toUtf8().constData());
        }

        void FileParser::convertParticleSystemToValueMap(const cocos2d::ParticleSystemQuad *particleSystem, const std::string& textureFileName, cocos2d::ValueMap &valueMap)
        {
            valueMap["maxParticles"] = particleSystem->getTotalParticles();
            valueMap["angle"] = particleSystem->getAngle();
            valueMap["angleVariance"] = particleSystem->getAngleVar();
            valueMap["duration"] = particleSystem->getDuration();

            valueMap["blendFuncSource"] = (int)particleSystem->getBlendFunc().src;
            valueMap["blendFuncDestination"] = (int)particleSystem->getBlendFunc().dst;

            valueMap["startColorRed"] = particleSystem->getStartColor().r;
            valueMap["startColorGreen"] = particleSystem->getStartColor().g;
            valueMap["startColorBlue"] = particleSystem->getStartColor().b;
            valueMap["startColorAlpha"] = particleSystem->getStartColor().a;
            valueMap["startColorVarianceRed"] = particleSystem->getStartColorVar().r;
            valueMap["startColorVarianceGreen"] = particleSystem->getStartColorVar().g;
            valueMap["startColorVarianceBlue"] = particleSystem->getStartColorVar().b;
            valueMap["startColorVarianceAlpha"] = particleSystem->getStartColorVar().a;

            valueMap["finishColorRed"] = particleSystem->getEndColor().r;
            valueMap["finishColorGreen"] = particleSystem->getEndColor().g;
            valueMap["finishColorBlue"] = particleSystem->getEndColor().b;
            valueMap["finishColorAlpha"] = particleSystem->getEndColor().a;
            valueMap["finishColorVarianceRed"] = particleSystem->getEndColorVar().r;
            valueMap["finishColorVarianceGreen"] = particleSystem->getEndColorVar().g;
            valueMap["finishColorVarianceBlue"] = particleSystem->getEndColorVar().b;
            valueMap["finishColorVarianceAlpha"] = particleSystem->getEndColorVar().a;

            valueMap["startParticleSize"] = particleSystem->getStartSize();
            valueMap["startParticleSizeVariance"] = particleSystem->getStartSizeVar();
            valueMap["finishParticleSize"] = particleSystem->getEndSize();
            valueMap["finishParticleSizeVariance"] = particleSystem->getEndSizeVar();

            valueMap["sourcePositionX"] = particleSystem->getPositionX();
            valueMap["sourcePositiony"] = particleSystem->getPositionY();
            valueMap["sourcePositionVariancex"] = particleSystem->getPosVar().x;
            valueMap["sourcePositionVariancey"] = particleSystem->getPosVar().y;

            valueMap["rotationStart"] = particleSystem->getStartSpin();
            valueMap["rotationStartVariance"] = particleSystem->getStartSpinVar();
            valueMap["rotationEnd"] = particleSystem->getEndSpin();
            valueMap["rotationEndVariance"] = particleSystem->getEndSpin();

            valueMap["emitterType"] = (int)particleSystem->getEmitterMode();

            valueMap["gravityx"] = particleSystem->getGravity().x;
            valueMap["gravityy"] = particleSystem->getGravity().y;
            valueMap["speed"] = particleSystem->getSpeed();
            valueMap["speedVariance"] = particleSystem->getSpeedVar();
            valueMap["radialAcceleration"] = particleSystem->getRadialAccel();
            valueMap["radialAccelVariance"] = particleSystem->getRadialAccelVar();
            valueMap["tangentialAcceleration"] = particleSystem->getTangentialAccel();
            valueMap["tangentialAccelVariance"] = particleSystem->getTangentialAccelVar();
            valueMap["rotationIsDir"] = particleSystem->getRotationIsDir();

            /*valueMap["maxRadius"] = particleSystem->getStartRadius();
            valueMap["maxRadiusVariance"] = particleSystem->getStartRadiusVar();
            valueMap["minRadius"] = particleSystem->getEndRadius();
            valueMap["minRadiusVariance"] = particleSystem->getEndRadiusVar();
            valueMap["rotatePerSecond"] = particleSystem->getRotatePerSecond();
            valueMap["rotatePerSecondVariance"] = particleSystem->getRotatePerSecondVar();*/

            valueMap["particleLifespan"] = particleSystem->getLife();
            valueMap["particleLifespanVariance"] = particleSystem->getLifeVar();

            valueMap["textureFileName"] = textureFileName;
            valueMap["textureImageData"] = "";

            valueMap["yCoordFlipped"] = 1;
        }

    } // namespace Particles
} // namespace MelonGames

