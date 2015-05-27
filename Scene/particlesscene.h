#ifndef PARTICLESSCENE_H
#define PARTICLESSCENE_H

#include "2d/CCScene.h"
#include "2d/CCParticleSystem.h"
#include "2d/CCLayer.h"

namespace cocos2d
{
    class Sprite;
    class EventListenerTouchOneByOne;
    class ParticleSystemQuad;
    class DrawNode;
}

namespace MelonGames
{
    namespace Particles
    {
        class ParticlesScene : public cocos2d::Scene
        {
        public:
            static ParticlesScene* create();

            void reset();

            void clearBackgroundImage();
            void setBackgroundImage(const std::string& imagePath);

            cocos2d::LayerColor* getBackgroundLayer() const { return backgroundLayer; }

            cocos2d::ParticleSystemQuad* getParticleSystem();
            cocos2d::ParticleSystemQuad* getParticleSystem(cocos2d::ParticleSystem::Mode mode);

            void animate(bool truthiness);

        private:
            ParticlesScene();
            ~ParticlesScene();

            bool init();
            void updateParticleSystemPosition(cocos2d::Touch* touch);

        private:
            cocos2d::LayerColor* backgroundLayer;
            cocos2d::EventListenerTouchOneByOne* eventsListener;
            cocos2d::DrawNode* particlesParentNode;
            cocos2d::ParticleSystemQuad* particleSystems[2];
            cocos2d::Sprite* backgroundImage;
        };

    }
}

#endif // PARTICLESSCENE_H
