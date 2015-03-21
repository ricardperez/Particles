#ifndef PARTICLESSCENE_H
#define PARTICLESSCENE_H

#include "2d/CCScene.h"

namespace cocos2d
{
class ParticleSystemQuad;
class Sprite;
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

private:
    ParticlesScene();
    ~ParticlesScene();

    bool init();

private:
    cocos2d::ParticleSystemQuad* particleSystem;
    cocos2d::Sprite* backgroundImage;
};

}
}

#endif // PARTICLESSCENE_H
