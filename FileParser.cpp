#include "FileParser.h"
#include "platform/CCFileUtils.h"
#include "2d/CCParticleSystemQuad.h"
#include <QImage>
#include <QByteArray>
#include <QBuffer>
#include <QStringList>
#include "base/base64.h"
#include "base/ZipUtils.h"
#include "platform/CCImage.h"
#include "base/CCDirector.h"
#include "renderer/CCTextureCache.h"
#include <QDebug>
#include <zlib.h>

namespace MelonGames {
    namespace Particles {

        void compress_data(const QByteArray& input, QByteArray& output)
        {
            const size_t BUFSIZE = 128 * 1024;
            uint8_t temp_buffer[BUFSIZE];

            z_stream strm;
            strm.zalloc = 0;
            strm.zfree = 0;
            strm.next_in = (Bytef*)input.data();
            strm.avail_in = input.length();
            strm.next_out = temp_buffer;
            strm.avail_out = BUFSIZE;

            deflateInit(&strm, Z_BEST_COMPRESSION);

            while (strm.avail_in != 0)
            {
                int res = deflate(&strm, Z_NO_FLUSH);
                assert(res == Z_OK);
                if (strm.avail_out == 0)
                {
                    output.append((const char*)temp_buffer, BUFSIZE);
                    strm.next_out = temp_buffer;
                    strm.avail_out = BUFSIZE;
                }
            }

            int deflate_res = Z_OK;
            while (deflate_res == Z_OK)
            {
                if (strm.avail_out == 0)
                {
                    output.append((const char*)temp_buffer, BUFSIZE);
                    strm.next_out = temp_buffer;
                    strm.avail_out = BUFSIZE;
                }
                deflate_res = deflate(&strm, Z_FINISH);
            }

            assert(deflate_res == Z_STREAM_END);
            output.append((const char*)temp_buffer, (BUFSIZE - strm.avail_out));
            deflateEnd(&strm);
        }

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
//                particleSystem->setSourcePosition(sourcePosition);
                particleSystem->getParent()->setPosition(sourcePosition);

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

            std::string textureName = valueMap["textureFileName"].asString();
            std::string textureData = valueMap.at("textureImageData").asString();
            auto dataLen = textureData.size();
            if (dataLen != 0)
            {
                unsigned char* buffer = nullptr;
                int decodeLen = cocos2d::base64Decode((unsigned char*)textureData.c_str(), (unsigned int)dataLen, &buffer);
                CCASSERT( buffer != nullptr, "CCParticleSystem: error decoding textureImageData");

                unsigned char* deflated = nullptr;
                ssize_t deflatedLen = cocos2d::ZipUtils::inflateMemory(buffer, decodeLen, &deflated);
                CCASSERT( deflated != nullptr, "CCParticleSystem: error ungzipping textureImageData");

                cocos2d::Image* image = new (std::nothrow) cocos2d::Image();
                bool isOK = image->initWithImageData(deflated, deflatedLen);
                CCASSERT(isOK, "CCParticleSystem: error init image with Data");

                cocos2d::Texture2D* texture = cocos2d::Director::getInstance()->getTextureCache()->addImage(image, textureName.c_str());
                particleSystemGravity->setTexture(texture);
                particleSystemRadius->setTexture(texture);

                image->release();
            }

            auto mode = (cocos2d::ParticleSystem::Mode)valueMap["emitterType"].asInt();

            return mode;
        }

        void FileParser::save(const QString& filePath, cocos2d::ParticleSystem::Mode mode, cocos2d::ParticleSystemQuad* particleSystemGravity, cocos2d::ParticleSystemQuad* particleSystemRadius, const std::string& textureFileName, const QImage* texture, bool embedTexture)
        {
            cocos2d::ValueMap valueMap;
            convertParticleSystemToValueMap(mode, particleSystemGravity, particleSystemRadius, textureFileName, texture, embedTexture, valueMap);

            cocos2d::FileUtils::getInstance()->writeToFile(valueMap, filePath.toUtf8().constData());

            if (!embedTexture)
            {
                QStringList pathParts = filePath.split(".");
                pathParts.removeLast();
                QString texturePath = (pathParts.join(".") + ".png");
                texture->save(texturePath, "PNG");
            }
        }

        void FileParser::convertParticleSystemToValueMap(cocos2d::ParticleSystem::Mode mode, cocos2d::ParticleSystemQuad* particleSystemGravity, cocos2d::ParticleSystemQuad* particleSystemRadius, const std::string& textureFileName, const QImage* texture, bool embedTexture, cocos2d::ValueMap &valueMap)
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

            //valueMap["sourcePositionX"] = particleSystemGravity->getPositionX();
            //valueMap["sourcePositionY"] = particleSystemGravity->getPositionY();
            valueMap["sourcePositionX"] = particleSystemGravity->getParent()->getPositionX();
            valueMap["sourcePositionY"] = particleSystemGravity->getParent()->getPositionY();
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

            if (embedTexture)
            {
                QByteArray byteArray;
                QBuffer buffer(&byteArray);
                texture->save(&buffer, "PNG");

                QByteArray compressedData;
                compress_data(byteArray, compressedData);

                valueMap["textureImageData"] = std::string(compressedData.toBase64().data());
            }
        }

    } // namespace Particles
} // namespace MelonGames

