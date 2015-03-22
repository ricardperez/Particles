#ifndef PARTICLESSCENE_H
#define PARTICLESSCENE_H

#include "2d/CCScene.h"

namespace cocos2d
{
class ParticleSystemQuad;
class Sprite;
class EventListenerTouchOneByOne;
}

namespace MelonGames
{
namespace Particles
{

class ParticlesScene : public cocos2d::Scene
{
public:
    static ParticlesScene* create();

    void clearBackgroundImage();
    void setBackgroundImage(const std::string& imagePath);

    cocos2d::ParticleSystemQuad* getParticleSystem();

private:
    ParticlesScene();
    ~ParticlesScene();

    bool init();
    void updateParticleSystemPosition(cocos2d::Touch* touch);

private:
    cocos2d::EventListenerTouchOneByOne* eventsListener;
    cocos2d::ParticleSystemQuad* particleSystem;
    cocos2d::Sprite* backgroundImage;
};

}
}

#endif // PARTICLESSCENE_H
