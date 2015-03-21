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
};

#endif // MAINWINDOW_H
