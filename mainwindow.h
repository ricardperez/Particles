#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace MelonGames
{
    namespace Particles
    {
        class ParticlesScene;
        class BackgroundController;
        class ParticleController;
        class EditorsFrameLayoutController;
        class TextureController;
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

    void onModeRadioButtonClicked();

    void onMenuFileNew();
    void onMenuFileOpen();
    void onMenuFileSave();
    void onMenuFileSaveAs();

private:
    void initBackgroundController();
    void initParticleController();
    void initTextureController();

    void save();
    void load();

    void updateEmitterMode();

private:
    Ui::MainWindow *ui;

    MelonGames::Particles::ParticlesScene* scene;
    MelonGames::Particles::BackgroundController* backgroundController;
    MelonGames::Particles::ParticleController* particleController;
    MelonGames::Particles::TextureController* textureController;

    QString path;
};

#endif // MAINWINDOW_H
