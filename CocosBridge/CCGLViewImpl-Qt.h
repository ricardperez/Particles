#ifndef MELONGAMES_PARTICLES_CCGLVIEWIMPL_H
#define MELONGAMES_PARTICLES_CCGLVIEWIMPL_H

#include "base/CCRef.h"
#include "platform/CCCommon.h"
#include "platform/CCGLView.h"

#include "CCOpenGLWidget.h"

namespace MelonGames {
namespace Particles {

class GLViewImpl : public cocos2d::GLView
{
public:
    static GLViewImpl* create(CCOpenGLWidget* widget);

    /* override functions */
    virtual bool isOpenGLReady() override;
    virtual void end() override;
    virtual void swapBuffers() override;
    virtual void setIMEKeyboardState(bool bOpen) override;

#if (CC_TARGET_PLATFORM == CC_PLATFORM_MAC)
    id getCocoaWindow();
#endif // #if (CC_TARGET_PLATFORM == CC_PLATFORM_MAC)

private:
    GLViewImpl();
    ~GLViewImpl();
    bool init(CCOpenGLWidget* widget);

private:
    CCOpenGLWidget* openGLWidget;
};

} // namespace Particles
} // namespace MelonGames

#endif // MELONGAMES_PARTICLES_CCGLVIEWIMPL_H
