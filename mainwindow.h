#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace MelonGames
{
namespace Particles
{

class ParticlesScene;
class BackgroundImageController;
class ParticleController;
class EditorsFrameLayoutController;

}
}

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void onOpenGLReady();
    void on_expandEditorButton_clicked();

    void on_expandOptionsButton_clicked();

private:
    void updateScrollExpanded();
    void updateOptionsExpanded();
    void initBackgroundImageController();
    void initParticleController();

private:
    Ui::MainWindow *ui;
    bool scrollExpanded;
    bool optionsExpanded;

    MelonGames::Particles::ParticlesScene* scene;
    MelonGames::Particles::BackgroundImageController* backgroundImageController;
    MelonGames::Particles::ParticleController* particleController;

    MelonGames::Particles::EditorsFrameLayoutController* mainConfigFrameLayoutController;
    MelonGames::Particles::EditorsFrameLayoutController* colorsConfigFrameLayoutController;
    MelonGames::Particles::EditorsFrameLayoutController* blendFunctionConfigFrameLayoutController;
};

#endif // MAINWINDOW_H
