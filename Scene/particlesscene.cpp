#include "particlesscene.h"

#include "base/CCDirector.h"
#include "2d/CCParticleSystemQuad.h"
#include "2d/CCParticleExamples.h"
#include "2d/CCSprite.h"
#include "2d/CCDrawNode.h"
#include "2d/CCActionInterval.h"
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
            : backgroundLayer(nullptr)
            , eventsListener(nullptr)
            , backgroundImage(nullptr)
            , particlesParentNode(nullptr)
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
                backgroundLayer = cocos2d::LayerColor::create(cocos2d::Color4B::BLACK);
                addChild(backgroundLayer);

                particleSystems[(int)cocos2d::ParticleSystem::Mode::GRAVITY] = cocos2d::ParticleFire::create();
                particleSystems[(int)cocos2d::ParticleSystem::Mode::RADIUS] = ParticleFireRadius::create();

                particlesParentNode = cocos2d::DrawNode::create();
                particlesParentNode->setPosition(getContentSize()*0.5f);
                backgroundLayer->addChild(particlesParentNode);

                for (auto particleSystem : particleSystems)
                {
                    particleSystem->setPosition(cocos2d::Vec2::ZERO);
                    particlesParentNode->addChild(particleSystem);
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
            if (particlesParentNode)
            {
                particlesParentNode->setPosition(touch->getLocation());
            }
        }

        void ParticlesScene::animate(bool truthiness)
        {
            if (truthiness)
            {
                particlesParentNode->drawRect(cocos2d::Vec2(-100.0f, -100.0f), cocos2d::Vec2(100.0f, 100.0f), cocos2d::Color4F::GRAY);
                float movement = getContentSize().width * 0.5f;
                float speed = 200.0f;
                float time = movement / speed;
                particlesParentNode->runAction(cocos2d::RepeatForever::create(cocos2d::Sequence::create(cocos2d::MoveBy::create(time, cocos2d::Vec2(movement, 0.0f)),
                                                                                           cocos2d::MoveBy::create(time, cocos2d::Vec2(-movement, 0.0f)),
                                                                                           nullptr)));
            }
            else
            {
                particlesParentNode->clear();
                particlesParentNode->stopAllActions();
            }
        }

    }
}
