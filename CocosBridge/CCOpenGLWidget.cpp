#include "CCOpenGLWidget.h"
#include "base/CCDirector.h"
#include "CCApplication-Qt.h"
#include "CCGLViewImpl-Qt.h"
#include "platform/CCGLView.h"
#include "base/CCEventMouse.h"
#include "base/CCEventDispatcher.h"

#include <QDebug>
#include <QMouseEvent>

namespace MelonGames
{
namespace Particles
{
CCOpenGLWidget::CCOpenGLWidget(QWidget *parent)
    : QOpenGLWidget(parent)
    , glView(nullptr)
    , mouseButtonCaptured(false)
{
    qDebug() << "Instantiated a CCOpenGLWidget";
}

CCOpenGLWidget::~CCOpenGLWidget()
{
    
}

void CCOpenGLWidget::initializeGL()
{
    if(!glView) {
        auto director = cocos2d::Director::getInstance();
        glView = GLViewImpl::create(this);
        resizeGL(width(), height());
        
        director->setOpenGLView(glView);
        
        GLContextAttrs glContextAttrs = {8, 8, 8, 8, 24, 8};
        cocos2d::GLView::setGLContextAttrs(glContextAttrs);
        
        glEnable(GL_VERTEX_PROGRAM_POINT_SIZE);
    }
    
    ApplicationQt* application = new ApplicationQt();
    application->applicationDidFinishLaunching();
    
    emit signalInitialized();
    
    startTimer(16, Qt::CoarseTimer);
}

void CCOpenGLWidget::paintGL()
{
    auto director = cocos2d::Director::getInstance();
    if (director->getOpenGLView() != nullptr)
    {
        director->mainLoop();
    }
}

void CCOpenGLWidget::resizeGL(int width, int height)
{
    auto director = cocos2d::Director::getInstance();
    if (glView)
    {
        glView->setDesignResolutionSize((float)width, (float)height, ResolutionPolicy::NO_BORDER);
        glView->setFrameSize((float)width, (float)height);
    }
}

void CCOpenGLWidget::timerEvent(QTimerEvent *event)
{
    Q_UNUSED(event);
    update();
}

void CCOpenGLWidget::mousePressEvent(QMouseEvent* event)
{
    QOpenGLWidget::mousePressEvent(event);

    if (!glView)
    {
        return;
    }

    cocos2d::Vec2 position = getMouseEventPosition(event);
    if (event->button() == Qt::MouseButton::LeftButton)
    {
        mouseButtonCaptured = true;
        if (true /*this->getViewPortRect().equals(Rect::ZERO) || this->getViewPortRect().containsPoint(Vec2(_mouseX,_mouseY))*/)
        {
            intptr_t id = 0;
            glView->handleTouchesBegin(1, &id, &position.x, &position.y);
        }
    }

    cocos2d::EventMouse cocosEvent(cocos2d::EventMouse::MouseEventType::MOUSE_DOWN);
    cocosEvent.setCursorPosition(position.x, position.y);
    cocosEvent.setMouseButton(event->button());
    cocos2d::Director::getInstance()->getEventDispatcher()->dispatchEvent(&cocosEvent);
}

void CCOpenGLWidget::mouseReleaseEvent(QMouseEvent* event)
{
    QOpenGLWidget::mouseReleaseEvent(event);

    if (!glView)
    {
        return;
    }

    cocos2d::Vec2 position = getMouseEventPosition(event);
    if (event->button() == Qt::MouseButton::LeftButton)
    {
        if (mouseButtonCaptured)
        {
            mouseButtonCaptured = false;
            intptr_t id = 0;
            glView->handleTouchesEnd(1, &id, &position.x, &position.y);
        }
    }

    cocos2d::EventMouse cocosEvent(cocos2d::EventMouse::MouseEventType::MOUSE_UP);
    cocosEvent.setCursorPosition(position.x, position.y);
    cocosEvent.setMouseButton(event->button());
    cocos2d::Director::getInstance()->getEventDispatcher()->dispatchEvent(&cocosEvent);
}

void CCOpenGLWidget::mouseMoveEvent(QMouseEvent* event)
{
    QOpenGLWidget::mouseMoveEvent(event);

    if (!glView)
    {
        return;
    }

    cocos2d::Vec2 position = getMouseEventPosition(event);
    if (mouseButtonCaptured)
    {
        intptr_t id = 0;
        glView->handleTouchesMove(1, &id, &position.x, &position.y);
    }


    cocos2d::EventMouse cocosEvent(cocos2d::EventMouse::MouseEventType::MOUSE_MOVE);
    cocosEvent.setMouseButton(event->button());
    cocosEvent.setCursorPosition(position.x, position.y);
    cocos2d::Director::getInstance()->getEventDispatcher()->dispatchEvent(&cocosEvent);
}

cocos2d::Vec2 CCOpenGLWidget::getMouseEventPosition(QMouseEvent* event) const
{
    QPoint point = event->pos();
    cocos2d::Vec2 result((float)point.x(), (float)point.y());
    return result;
}

}
}

