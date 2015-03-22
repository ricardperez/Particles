#ifndef MELONGAMES_PARTICLE_APPDELEGATE_H
#define MELONGAMES_PARTICLE_APPDELEGATE_H

#include "math/CCGeometry.h"
#include "platform/CCApplication.h"

namespace MelonGames {
namespace Particles {

class  ApplicationQt : private cocos2d::Application
{
public:
    explicit ApplicationQt();
    virtual ~ApplicationQt();

    /**
    @brief    Implement Director and Scene init code here.
    @return true    Initialize success, app continue.
    @return false   Initialize failed, app terminate.
    */
    virtual bool applicationDidFinishLaunching();

    /**
    @brief  The function be called when the application enter background
    @param  the pointer of the application
    */
    virtual void applicationDidEnterBackground();

    /**
    @brief  The function be called when the application enter foreground
    @param  the pointer of the application
    */
    virtual void applicationWillEnterForeground();
};

} // namespace Particle
} // namespace MelonGames

#endif // MELONGAMES_PARTICLE_APPDELEGATE_H
