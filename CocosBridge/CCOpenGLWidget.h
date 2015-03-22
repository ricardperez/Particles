#ifndef CCOPENGLWIDGET_H
#define CCOPENGLWIDGET_H

#include <QOpenGLWidget>
#include "math/Vec2.h"

namespace MelonGames
{
namespace Particles
{

class GLViewImpl;
class CCOpenGLWidget : public QOpenGLWidget
{
    Q_OBJECT
public:
    explicit CCOpenGLWidget(QWidget *parent = 0);
    ~CCOpenGLWidget();

signals:
    void signalInitialized();

protected:
    void initializeGL() override;
    void paintGL() override;
    void resizeGL(int width, int height) override;

private:
    void draw();
    void timerEvent(QTimerEvent* event) override;
    void mousePressEvent(QMouseEvent* event) override;
    void mouseReleaseEvent(QMouseEvent* event) override;
    void mouseMoveEvent(QMouseEvent* event) override;

    cocos2d::Vec2 getMouseEventPosition(QMouseEvent* event) const;

private:
    GLViewImpl* glView;
    bool mouseButtonCaptured;
};

}
}

#endif // CCOPENGLWIDGET_H
