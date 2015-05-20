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

    void on_expandOptionsButton_clicked();
    void onModeRadioButtonClicked();

    void onMenuFileOpen();
    void onMenuFileSave();
    void onMenuFileSaveAs();

private:
    void updateOptionsExpanded();
    void initBackgroundImageController();
    void initParticleController();

    void save();
    void load();

    void updateEmitterMode();

private:
    Ui::MainWindow *ui;
    bool optionsExpanded;

    MelonGames::Particles::ParticlesScene* scene;
    MelonGames::Particles::BackgroundImageController* backgroundImageController;
    MelonGames::Particles::ParticleController* particleController;

    QString path;
};

#endif // MAINWINDOW_H
