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
    auto glview = director->getOpenGLView();
    glview->setDesignResolutionSize(designResolutionSize.width, designResolutionSize.height, ResolutionPolicy::NO_BORDER);

        cocos2d::Size frameSize = glview->getFrameSize();

        std::vector<std::string> searchPath;

        // In this demo, we select resource according to the frame's height.
        // If the resource size is different from design resolution size, you need to set contentScaleFactor.
        // We use the ratio of resource's height to the height of design resolution,
        // this can make sure that the resource's height could fit for the height of design resolution.

        // if the frame's height is larger than the height of medium resource size, select large resource.
        if (frameSize.height > mediumResource.size.height)
        {
            searchPath.push_back(largeResource.directory);

            director->setContentScaleFactor(MIN(largeResource.size.height/designResolutionSize.height, largeResource.size.width/designResolutionSize.width));
        }
        // if the frame's height is larger than the height of small resource size, select medium resource.
        else if (frameSize.height > smallResource.size.height)
        {
            searchPath.push_back(mediumResource.directory);

            director->setContentScaleFactor(MIN(mediumResource.size.height/designResolutionSize.height, mediumResource.size.width/designResolutionSize.width));
        }
        // if the frame's height is smaller than the height of medium resource size, select small resource.
        else
        {
            searchPath.push_back(smallResource.directory);

            director->setContentScaleFactor(MIN(smallResource.size.height/designResolutionSize.height, smallResource.size.width/designResolutionSize.width));
        }

        // set searching path
        FileUtils::getInstance()->setSearchPaths(searchPath);

        // turn on display FPS
        director->setDisplayStats(true);

        // set FPS. the default value is 1.0/60 if you don't call this
        director->setAnimationInterval(1.0 / 60);

        // create a scene. it's an autorelease object
        auto scene = Scene::create();
        auto label = Label::createWithSystemFont("", "Helvetica", 120);
        label->setString("Hello World");
        label->setPosition(scene->getContentSize()*0.5f);
        scene->addChild(label);

        // run
        director->runWithScene(scene);

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

const cocos2d::Size ApplicationQt::designResolutionSize = cocos2d::Size(1920, 1080);
const ApplicationQt::Resource ApplicationQt::smallResource  =  { cocos2d::Size(480, 320),   "iphone" };
const ApplicationQt::Resource ApplicationQt::mediumResource =  { cocos2d::Size(1024, 768),  "ipad"   };
const ApplicationQt::Resource ApplicationQt::largeResource  =  { cocos2d::Size(2048, 1536), "ipadhd" };

} // namespace Particle
} // namespace MelonGames

