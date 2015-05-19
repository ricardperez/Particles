#include "particlesscene.h"

#include "base/CCDirector.h"
#include "2d/CCParticleSystemQuad.h"
#include "2d/CCParticleExamples.h"
#include "2d/CCSprite.h"
#include "renderer/CCTextureCache.h"
#include "renderer/CCTexture2D.h"
#include "base/CCEventListenerTouch.h"
#include "base/CCEventDispatcher.h"
#include "base/CCEvent.h"
#include <QDebug>

namespace MelonGames
{
    namespace Particles
    {

        ParticlesScene* ParticlesScene::create()
        {
            auto result = new ParticlesScene();
            if (result && result->init())
            {
                result->autorelease();
                return result;
            }

            delete result;
            return nullptr;
        }

        ParticlesScene::ParticlesScene()
            : eventsListener(nullptr)
            , backgroundImage(nullptr)
        {
            particleSystems[0] = nullptr;
            particleSystems[1] = nullptr;
        }

        ParticlesScene::~ParticlesScene()
        {
            if (eventsListener)
            {
                cocos2d::Director::getInstance()->getEventDispatcher()->removeEventListener(eventsListener);
            }
        }

        bool ParticlesScene::init()
        {
            class ParticleFireRadius : public cocos2d::ParticleFire
            {
            public:
                static ParticleFireRadius* create()
                {
                    ParticleFireRadius* result = new ParticleFireRadius();
                    if (result && result->init())
                    {
                        result->_emitterMode = cocos2d::ParticleSystem::Mode::RADIUS;
                        result->autorelease();
                        return result;
                    }

                    delete result;
                    return nullptr;
                }
            };

            if (Scene::init())
            {
                particleSystems[(int)cocos2d::ParticleSystem::Mode::GRAVITY] = cocos2d::ParticleFire::create();
                particleSystems[(int)cocos2d::ParticleSystem::Mode::RADIUS] = ParticleFireRadius::create();

                for (auto particleSystem : particleSystems)
                {
                    particleSystem->setPosition(getContentSize()*0.5f);
                    addChild(particleSystem);
                }

                eventsListener = cocos2d::EventListenerTouchOneByOne::create();

                eventsListener->onTouchBegan = [this](cocos2d::Touch* touch, cocos2d::Event* event) -> bool {
                    updateParticleSystemPosition(touch);
                    return true;
                };

                eventsListener->onTouchEnded = [this](cocos2d::Touch* touch, cocos2d::Event* event) -> void {
                    updateParticleSystemPosition(touch);
                };

                eventsListener->onTouchCancelled = [this](cocos2d::Touch* touch, cocos2d::Event* event) -> void {
                    updateParticleSystemPosition(touch);
                };

                eventsListener->onTouchMoved = [this](cocos2d::Touch* touch, cocos2d::Event* event) -> void {
                    updateParticleSystemPosition(touch);
                };

                cocos2d::Director::getInstance()->getEventDispatcher()->addEventListenerWithFixedPriority(eventsListener, 1);

                return true;
            }

            return false;
        }

        void ParticlesScene::clearBackgroundImage()
        {
            if (backgroundImage)
            {
                backgroundImage->removeFromParent();
                backgroundImage = nullptr;
            }
        }

        void ParticlesScene::setBackgroundImage(const std::string& imagePath)
        {
            clearBackgroundImage();
            if (cocos2d::Texture2D* texture = cocos2d::Director::getInstance()->getTextureCache()->addImage(imagePath))
            {
                backgroundImage = cocos2d::Sprite::createWithTexture(texture);
                addChild(backgroundImage, -1);
                backgroundImage->setPosition(getContentSize()*0.5f);
            }
        }

        cocos2d::ParticleSystemQuad* ParticlesScene::getParticleSystem()
        {
            return particleSystems[(int)cocos2d::ParticleSystem::Mode::GRAVITY];
        }

        cocos2d::ParticleSystemQuad* ParticlesScene::getParticleSystem(cocos2d::ParticleSystem::Mode mode)
        {
            return particleSystems[(int)mode];
        }

        void ParticlesScene::updateParticleSystemPosition(cocos2d::Touch* touch)
        {
            for (auto particleSystem : particleSystems)
            {
                if (particleSystem)
                {
                    particleSystem->setPosition(touch->getLocation());
                }
            }
        }

    }
}
