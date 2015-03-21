#include "particlesscene.h"

#include "base/CCDirector.h"
#include "2d/CCParticleSystemQuad.h"
#include "2d/CCParticleExamples.h"
#include "2d/CCSprite.h"
#include "renderer/CCTextureCache.h"
#include "renderer/CCTexture2D.h"

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
    : particleSystem(nullptr)
    , backgroundImage(nullptr)
{
}

ParticlesScene::~ParticlesScene()
{
}

bool ParticlesScene::init()
{
    if (Scene::init())
    {
        //particleSystem = cocos2d::ParticleSystemQuad::create();
        particleSystem = cocos2d::ParticleFire::create();
        particleSystem->setPosition(getContentSize()*0.5f);
        addChild(particleSystem);
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

}
}
