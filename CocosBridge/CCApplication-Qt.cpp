#include "CCApplication-Qt.h"
#include "cocos2d.h"
#include <QDebug>

using namespace cocos2d;

namespace MelonGames {
namespace Particles {

ApplicationQt::ApplicationQt()
{
}

ApplicationQt::~ApplicationQt()
{

}

/**
@brief    Implement Director and Scene init code here.
@return true    Initialize success, app continue.
@return false   Initialize failed, app terminate.
*/
bool ApplicationQt::applicationDidFinishLaunching()
{
    auto director = Director::getInstance();

    std::vector<std::string> searchPath;
    FileUtils::getInstance()->setSearchPaths(searchPath);

    // turn on display FPS
    director->setDisplayStats(true);

    // set FPS. the default value is 1.0/60 if you don't call this
    director->setAnimationInterval(1.0 / 60);

    return true;
}

/**
@brief  The function be called when the application enter background
@param  the pointer of the application
*/
void ApplicationQt::applicationDidEnterBackground()
{
    Director::getInstance()->stopAnimation();
}

/**
@brief  The function be called when the application enter foreground
@param  the pointer of the application
*/
void ApplicationQt::applicationWillEnterForeground()
{
    Director::getInstance()->startAnimation();
}

} // namespace Particle
} // namespace MelonGames

