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
    , particleSystem(nullptr)
    , backgroundImage(nullptr)
{
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
    if (Scene::init())
    {
        //particleSystem = cocos2d::ParticleSystemQuad::create();
        particleSystem = cocos2d::ParticleFire::create();
        qDebug() << "Content size: (" << getContentSize().width << ", " << getContentSize().height << ")";
        particleSystem->setPosition(getContentSize()*0.5f);
        addChild(particleSystem);

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
    return particleSystem;
}

void ParticlesScene::updateParticleSystemPosition(cocos2d::Touch* touch)
{
    if (particleSystem)
    {
        particleSystem->setPosition(touch->getLocation());
    }
}

}
}
