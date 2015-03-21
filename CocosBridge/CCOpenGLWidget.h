#ifndef CCOPENGLWIDGET_H
#define CCOPENGLWIDGET_H

#include <QOpenGLWidget>

namespace MelonGames
{
namespace Particles
{
class CCOpenGLWidget : public QOpenGLWidget
{
    Q_OBJECT
    public:
        explicit CCOpenGLWidget(QWidget *parent = 0);
        ~CCOpenGLWidget();

    protected:
        void initializeGL() override;
        void paintGL() override;
        void resizeGL(int width, int height) override;

    private:
        void draw();
        void timerEvent(QTimerEvent* timerEvent);
};
}
}

#endif // CCOPENGLWIDGET_H
