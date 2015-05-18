#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "Scene/particlesscene.h"
#include "Controller/backgroundimagecontroller.h"
#include "Controller/particlecontroller.h"
#include "editorsframelayoutcontroller.h"
#include "base/CCDirector.h"
#include "FileParser.h"
#include <QFileDialog>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
  , scrollExpanded(true)
  , scene(nullptr)
  , optionsExpanded(false)
  , backgroundImageController(nullptr)
  , particleController(nullptr)
{
    ui->setupUi(this);

    updateScrollExpanded();
    updateOptionsExpanded();

    connect(ui->openGLWidget, SIGNAL(signalInitialized()), this, SLOT(onOpenGLReady()));

    mainConfigFrameLayoutController = new MelonGames::Particles::EditorsFrameLayoutController(ui->particlesMainConfigFrame, this);
    colorsConfigFrameLayoutController = new MelonGames::Particles::EditorsFrameLayoutController(ui->particlesColorsConfigFrame, this);
    blendFunctionConfigFrameLayoutController = new MelonGames::Particles::EditorsFrameLayoutController(ui->particlesBlendFunctionConfigFrame, this);
}

MainWindow::~MainWindow()
{
    delete ui;

    delete particleController;
    delete backgroundImageController;
}

void MainWindow::onOpenGLReady()
{
    scene = MelonGames::Particles::ParticlesScene::create();
    cocos2d::Director::getInstance()->runWithScene(scene);

    initBackgroundImageController();
    initParticleController();
}

void MainWindow::on_expandEditorButton_clicked()
{
    scrollExpanded = !scrollExpanded;
    updateScrollExpanded();
}

void MainWindow::updateScrollExpanded()
{
    QSizePolicy::Policy spacerPolicy = (scrollExpanded ? QSizePolicy::Ignored : QSizePolicy::MinimumExpanding);
    ui->editorVerticalSpacer->changeSize(0, 0, spacerPolicy, spacerPolicy);

    ui->scrollArea->setVisible(scrollExpanded);
    ui->editorFrame->setMinimumWidth(scrollExpanded ? 400.0f : 120.0f);
    ui->editorFrame->setMaximumWidth(scrollExpanded ? 400.0f : 120.0f);

    ui->expandEditorButton->setText(scrollExpanded ? "Hide editor" : "Show editor");
}

void MainWindow::updateOptionsExpanded()
{
    ui->optionsFrame->setVisible(optionsExpanded);
    ui->expandOptionsButton->setText(optionsExpanded ? "Hide options" : "Show options");
}

void MainWindow::initBackgroundImageController()
{
    backgroundImageController = new MelonGames::Particles::BackgroundImageController();
    backgroundImageController->setParticlesScene(scene);
    backgroundImageController->setChangeImageButton(ui->backgroundImageSelectButton);
    backgroundImageController->setImageNameLabel(ui->backgroundImageNameLabel);
    backgroundImageController->update();
}

void MainWindow::initParticleController()
{
    particleController = new MelonGames::Particles::ParticleController();

    particleController->setParticlesScene(scene);
    particleController->setUIMaxParticles(ui->maxParticlesFrame);
    particleController->setUILifespan(ui->lifespanFrame);
    particleController->setUILifespanVar(ui->lifespanVarFrame);
    particleController->setUIStartSize(ui->startSizeFrame);
    particleController->setUIStartSizeVar(ui->startSizeVarFrame);
    particleController->setUIFinishSize(ui->finishSizeFrame);
    particleController->setUIFinishSizeVar(ui->finishSizeVarFrame);
    particleController->setUIEmitionAngle(ui->emitionAngleFrame);
    particleController->setUIEmitionAngleVar(ui->emitionAngleVarFrame);
    particleController->setUIRotationStart(ui->rotationStartFrame);
    particleController->setUIRotationStartVar(ui->rotationStartVarFrame);
    particleController->setUIRotationEnd(ui->rotationEndFrame);
    particleController->setUIRotationEndVar(ui->rotationEndVarFrame);

    particleController->setUIStartColor(ui->startColorFrame);
    particleController->setUIStartColorVar(ui->startColorVarFrame);
    particleController->setUIEndColor(ui->endColorFrame);
    particleController->setUIEndColorVar(ui->endColorVarFrame);

    particleController->setUIBlendFunctionBuiltIn(ui->blendFunctionFrame);
    particleController->setUIBlendFunctionSource(ui->blendFunctionSourceFrame);
    particleController->setUIBlendFunctionDestination(ui->blendFunctionDestFrame);
}

void MainWindow::save()
{
    if (scene)
    {
        MelonGames::Particles::FileParser fileParser;
        fileParser.save(path, scene->getParticleSystem(cocos2d::ParticleSystem::Mode::GRAVITY), "");
    }
}

void MainWindow::load()
{
    if (scene)
    {
        MelonGames::Particles::FileParser fileParser;
        fileParser.load(path, scene->getParticleSystem(cocos2d::ParticleSystem::Mode::GRAVITY));

        particleController->reload();
    }
}

void MainWindow::on_expandOptionsButton_clicked()
{
    optionsExpanded = !optionsExpanded;
    updateOptionsExpanded();
}

void MainWindow::onMenuFileOpen()
{
    QString path = QFileDialog::getOpenFileName(this, "Open particle system", "", "PLIST (*.plist)");
    if (!path.isEmpty())
    {
        this->path = path;
        load();
    }
}

void MainWindow::onMenuFileSave()
{
    if (path.isEmpty())
    {
        onMenuFileSaveAs();
    }
    else
    {
        save();
    }
}

void MainWindow::onMenuFileSaveAs()
{
    QString path = QFileDialog::getSaveFileName(this, "Save particle system", "", "PLIST (*.plist)");
    if (!path.isEmpty())
    {
        this->path = path;

        save();
    }
}
