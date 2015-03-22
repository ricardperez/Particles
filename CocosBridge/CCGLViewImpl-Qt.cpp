#include "CCGLViewImpl-Qt.h"
#include <QDebug>
#include "cocos2d.h"

namespace MelonGames {
namespace Particles {

GLViewImpl::GLViewImpl()
    : openGLWidget(nullptr)
{

}

GLViewImpl::~GLViewImpl()
{

}

GLViewImpl* GLViewImpl::create(CCOpenGLWidget *widget)
{
    GLViewImpl* result = new GLViewImpl();
    if (result && result->init(widget))
    {
        result->autorelease();
        return result;
    }

    delete result;
    return nullptr;
}

bool GLViewImpl::init(CCOpenGLWidget *widget)
{
    if (!widget)
    {
        return false;
    }

    //we need to delay the creation of the GLView until the QOpenGLWidget is ready.
    if (!widget->isValid())
    {
        return false;
    }

    const GLubyte* glVersion = glGetString(GL_VERSION);
    if ( cocos2d::utils::atof((const char*)glVersion) < 1.5 )
    {
        qDebug() << "OpenGL 1.5 or higher is required (your version is %s). Please upgrade the driver of your video card.";
        return false;
    }

    openGLWidget = widget;

    return true;
}

bool GLViewImpl::isOpenGLReady()
{
    return (openGLWidget && openGLWidget->isValid());
}

void GLViewImpl::end()
{
}

void GLViewImpl::swapBuffers()
{
}

void GLViewImpl::setIMEKeyboardState(bool bOpen)
{

}

#if (CC_TARGET_PLATFORM == CC_PLATFORM_MAC)
    id GLViewImpl::getCocoaWindow()
    {
        return nullptr;
    }

#endif // #if (CC_TARGET_PLATFORM == CC_PLATFORM_MAC)

} // namespace Particles
} // namespace MelonGames

