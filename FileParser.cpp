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

        cocos2d::ParticleSystem::Mode FileParser::load(const QString& filePath, cocos2d::ParticleSystemQuad* particleSystemGravity, cocos2d::ParticleSystemQuad* particleSystemRadius)
        {
            cocos2d::ValueMap valueMap = cocos2d::FileUtils::getInstance()->getValueMapFromFile(filePath.toUtf8().constData());

            auto loadParticleLambda = [&valueMap](cocos2d::ParticleSystemQuad* particleSystem, cocos2d::ParticleSystem::Mode mode) -> void
            {
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

                particleSystem->setLife(valueMap["particleLifespan"].asFloat());
                particleSystem->setLifeVar(valueMap["particleLifespanVariance"].asFloat());

                if (mode == cocos2d::ParticleSystem::Mode::GRAVITY)
                {
                    particleSystem->setEmitterMode(cocos2d::ParticleSystem::Mode::GRAVITY);

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
                    particleSystem->setEmitterMode(cocos2d::ParticleSystem::Mode::RADIUS);

                    particleSystem->setStartRadius(valueMap["maxRadius"].asFloat());
                    particleSystem->setStartRadiusVar(valueMap["maxRadiusVariance"].asFloat());
                    particleSystem->setEndRadius(valueMap["minRadius"].asFloat());
                    particleSystem->setEndRadiusVar(valueMap["minRadiusVariance"].asFloat());
                    particleSystem->setRotatePerSecond(valueMap["rotatePerSecond"].asFloat());
                    particleSystem->setRotatePerSecondVar(valueMap["rotatePerSecondVariance"].asFloat());
                }
            };

            loadParticleLambda(particleSystemGravity, cocos2d::ParticleSystem::Mode::GRAVITY);
            loadParticleLambda(particleSystemRadius, cocos2d::ParticleSystem::Mode::RADIUS);

            auto mode = (cocos2d::ParticleSystem::Mode)valueMap["emitterType"].asInt();

            return mode;
        }

        void FileParser::save(const QString& filePath, cocos2d::ParticleSystem::Mode mode, cocos2d::ParticleSystemQuad* particleSystemGravity, cocos2d::ParticleSystemQuad* particleSystemRadius, const std::string& textureFileName)
        {
            cocos2d::ValueMap valueMap;
            convertParticleSystemToValueMap(mode, particleSystemGravity, particleSystemRadius, textureFileName, valueMap);

            cocos2d::FileUtils::getInstance()->writeToFile(valueMap, filePath.toUtf8().constData());
        }

        void FileParser::convertParticleSystemToValueMap(cocos2d::ParticleSystem::Mode mode, cocos2d::ParticleSystemQuad* particleSystemGravity, cocos2d::ParticleSystemQuad* particleSystemRadius, const std::string& textureFileName, cocos2d::ValueMap &valueMap)
        {
            valueMap["maxParticles"] = particleSystemGravity->getTotalParticles();
            valueMap["angle"] = particleSystemGravity->getAngle();
            valueMap["angleVariance"] = particleSystemGravity->getAngleVar();
            valueMap["duration"] = particleSystemGravity->getDuration();

            valueMap["blendFuncSource"] = (int)particleSystemGravity->getBlendFunc().src;
            valueMap["blendFuncDestination"] = (int)particleSystemGravity->getBlendFunc().dst;

            valueMap["startColorRed"] = particleSystemGravity->getStartColor().r;
            valueMap["startColorGreen"] = particleSystemGravity->getStartColor().g;
            valueMap["startColorBlue"] = particleSystemGravity->getStartColor().b;
            valueMap["startColorAlpha"] = particleSystemGravity->getStartColor().a;
            valueMap["startColorVarianceRed"] = particleSystemGravity->getStartColorVar().r;
            valueMap["startColorVarianceGreen"] = particleSystemGravity->getStartColorVar().g;
            valueMap["startColorVarianceBlue"] = particleSystemGravity->getStartColorVar().b;
            valueMap["startColorVarianceAlpha"] = particleSystemGravity->getStartColorVar().a;

            valueMap["finishColorRed"] = particleSystemGravity->getEndColor().r;
            valueMap["finishColorGreen"] = particleSystemGravity->getEndColor().g;
            valueMap["finishColorBlue"] = particleSystemGravity->getEndColor().b;
            valueMap["finishColorAlpha"] = particleSystemGravity->getEndColor().a;
            valueMap["finishColorVarianceRed"] = particleSystemGravity->getEndColorVar().r;
            valueMap["finishColorVarianceGreen"] = particleSystemGravity->getEndColorVar().g;
            valueMap["finishColorVarianceBlue"] = particleSystemGravity->getEndColorVar().b;
            valueMap["finishColorVarianceAlpha"] = particleSystemGravity->getEndColorVar().a;

            valueMap["startParticleSize"] = particleSystemGravity->getStartSize();
            valueMap["startParticleSizeVariance"] = particleSystemGravity->getStartSizeVar();
            valueMap["finishParticleSize"] = particleSystemGravity->getEndSize();
            valueMap["finishParticleSizeVariance"] = particleSystemGravity->getEndSizeVar();

            valueMap["sourcePositionX"] = particleSystemGravity->getPositionX();
            valueMap["sourcePositiony"] = particleSystemGravity->getPositionY();
            valueMap["sourcePositionVariancex"] = particleSystemGravity->getPosVar().x;
            valueMap["sourcePositionVariancey"] = particleSystemGravity->getPosVar().y;

            valueMap["rotationStart"] = particleSystemGravity->getStartSpin();
            valueMap["rotationStartVariance"] = particleSystemGravity->getStartSpinVar();
            valueMap["rotationEnd"] = particleSystemGravity->getEndSpin();
            valueMap["rotationEndVariance"] = particleSystemGravity->getEndSpin();

            valueMap["emitterType"] = (int)mode;

            valueMap["gravityx"] = particleSystemGravity->getGravity().x;
            valueMap["gravityy"] = particleSystemGravity->getGravity().y;
            valueMap["speed"] = particleSystemGravity->getSpeed();
            valueMap["speedVariance"] = particleSystemGravity->getSpeedVar();
            valueMap["radialAcceleration"] = particleSystemGravity->getRadialAccel();
            valueMap["radialAccelVariance"] = particleSystemGravity->getRadialAccelVar();
            valueMap["tangentialAcceleration"] = particleSystemGravity->getTangentialAccel();
            valueMap["tangentialAccelVariance"] = particleSystemGravity->getTangentialAccelVar();
            valueMap["rotationIsDir"] = particleSystemGravity->getRotationIsDir();

            valueMap["maxRadius"] = particleSystemRadius->getStartRadius();
            valueMap["maxRadiusVariance"] = particleSystemRadius->getStartRadiusVar();
            valueMap["minRadius"] = particleSystemRadius->getEndRadius();
            valueMap["minRadiusVariance"] = particleSystemRadius->getEndRadiusVar();
            valueMap["rotatePerSecond"] = particleSystemRadius->getRotatePerSecond();
            valueMap["rotatePerSecondVariance"] = particleSystemRadius->getRotatePerSecondVar();

            valueMap["particleLifespan"] = particleSystemGravity->getLife();
            valueMap["particleLifespanVariance"] = particleSystemGravity->getLifeVar();

            valueMap["textureFileName"] = textureFileName;
            valueMap["textureImageData"] = "";

            valueMap["yCoordFlipped"] = 1;
        }

    } // namespace Particles
} // namespace MelonGames

