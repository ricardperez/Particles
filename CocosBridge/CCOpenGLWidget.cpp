#include "CCOpenGLWidget.h"
#include <QDebug>
#include "base/CCDirector.h"
#include "CCApplication-Qt.h"
#include "CCGLViewImpl-Qt.h"
#include "platform/CCGLView.h"

namespace MelonGames
{
namespace Particles
{
CCOpenGLWidget::CCOpenGLWidget(QWidget *parent)
    : QOpenGLWidget(parent)
{
    qDebug() << "Instantiated a CCOpenGLWidget";
}

CCOpenGLWidget::~CCOpenGLWidget()
{

}

void CCOpenGLWidget::initializeGL()
{
    auto director = cocos2d::Director::getInstance();
    auto glview = director->getOpenGLView();
    Q_ASSERT(!glview); //only one OpenGL widget is supported.
    if(!glview) {
        glview = GLViewImpl::create(this);
        director->setOpenGLView(glview);

        GLContextAttrs glContextAttrs = {8, 8, 8, 8, 24, 8};
        cocos2d::GLView::setGLContextAttrs(glContextAttrs);
    }

    ApplicationQt* application = new ApplicationQt();
    application->applicationDidFinishLaunching();

    emit signalInitialized();

    startTimer(16.6, Qt::CoarseTimer);
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
    if (auto glview = cocos2d::Director::getInstance()->getOpenGLView())
    {
        glview->setFrameSize((float)width, (float)height);
    }
}

void CCOpenGLWidget::timerEvent(QTimerEvent *timerEvent)
{
    Q_UNUSED(timerEvent);
    update();
}

}
}

