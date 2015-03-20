//
//  Created by Ricard Perez del Campo on 23/12/14.
//  Copyright (c) 2014 MelonGames. All rights reserved.
//

#include "CocosInterface.h"
#import <Foundation/Foundation.h>
#include <QDebug>
#include "cocos2d.h"
#include <string>
#include <vector>

using namespace cocos2d;

namespace MelonGames
{
    namespace Particles
    {
    class  AppDelegate : private cocos2d::Application
    {
    public:
        const static cocos2d::Size designResolutionSize;

        typedef struct tagResource
        {
            cocos2d::Size size;
            char directory[100];
        }Resource;
        const static Resource smallResource;
        const static Resource mediumResource;
        const static Resource largeResource;

        AppDelegate() {};
        virtual ~AppDelegate() {}

        virtual void initGLContextAttrs()
        {
            GLContextAttrs glContextAttrs = {8, 8, 8, 8, 24, 8};

            GLView::setGLContextAttrs(glContextAttrs);
        }

        /**
        @brief    Implement Director and Scene init code here.
        @return true    Initialize success, app continue.
        @return false   Initialize failed, app terminate.
        */
        virtual bool applicationDidFinishLaunching()
        {
            auto director = Director::getInstance();
                auto glview = director->getOpenGLView();
                if(!glview) {
                    glview = GLViewImpl::create("Cpp Empty Test");
                    director->setOpenGLView(glview);
                }

                director->setOpenGLView(glview);

                // Set the design resolution
            #if (CC_TARGET_PLATFORM == CC_PLATFORM_WP8)
                // a bug in DirectX 11 level9-x on the device prevents ResolutionPolicy::NO_BORDER from working correctly
                glview->setDesignResolutionSize(designResolutionSize.width, designResolutionSize.height, ResolutionPolicy::SHOW_ALL);
            #else
                glview->setDesignResolutionSize(designResolutionSize.width, designResolutionSize.height, ResolutionPolicy::NO_BORDER);
            #endif

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
        virtual void applicationDidEnterBackground()
        {
            Director::getInstance()->stopAnimation();
        }

        /**
        @brief  The function be called when the application enter foreground
        @param  the pointer of the application
        */
        virtual void applicationWillEnterForeground()
        {
            Director::getInstance()->startAnimation();
        }
    };

    const cocos2d::Size AppDelegate::designResolutionSize = cocos2d::Size(1920, 1080);
    const AppDelegate::Resource AppDelegate::smallResource  =  { cocos2d::Size(480, 320),   "iphone" };
    const AppDelegate::Resource AppDelegate::mediumResource =  { cocos2d::Size(1024, 768),  "ipad"   };
    const AppDelegate::Resource AppDelegate::largeResource  =  { cocos2d::Size(2048, 1536), "ipadhd" };
    }
}

@interface CocosManager : NSObject

- (void)link:(QOpenGLWidget*)widget;

@end

@implementation CocosManager

- (void)link:(QOpenGLWidget*)widget
{
    qDebug() << "From objective c++";

    auto appDelegate = new MelonGames::Particles::AppDelegate();
    cocos2d::Application::getInstance()->run();
//    auto director = cocos2d::Director::getInstance();
//    auto glview = director->getOpenGLView();
//    if(!glview)
//    {
//        qDebug() << "Instantiating the glView";
//        glview = cocos2d::GLViewImpl::create("Cpp Tests");
//        qDebug() << "Instantiated";
//        director->setOpenGLView(glview);
//    }
}

@end

namespace MelonGames
{
    namespace Particles
    {
        CocosInterface::CocosInterface()
        {
        }

        void CocosInterface::setup(QOpenGLWidget *openGL)
        {
            CocosManager *cocosManager = [[CocosManager alloc] init];
            [cocosManager link:openGL];
            [cocosManager release];
        }
        
    }
}
