#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "Scene/particlesscene.h"
#include "Controller/BackgroundController.h"
#include "Controller/particlecontroller.h"
#include "Controller/TextureController.h"
#include "editorsframelayoutcontroller.h"
#include "base/CCDirector.h"
#include "2d/CCParticleSystemQuad.h"
#include "FileParser.h"
#include <QFileDialog>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
  , scene(nullptr)
  , backgroundController(nullptr)
  , particleController(nullptr)
  , textureController(nullptr)
{
    ui->setupUi(this);

    connect(ui->openGLWidget, SIGNAL(signalInitialized()), this, SLOT(onOpenGLReady()));

    new MelonGames::Particles::EditorsFrameLayoutController(ui->particlesMainConfigFrame, this);
    new MelonGames::Particles::EditorsFrameLayoutController(ui->particlesColorsConfigFrame, this);
    new MelonGames::Particles::EditorsFrameLayoutController(ui->particlesBlendFunctionConfigFrame, this);
    new MelonGames::Particles::EditorsFrameLayoutController(ui->particlesGravityConfigFrame, this);
    new MelonGames::Particles::EditorsFrameLayoutController(ui->particlesRadiusConfigFrame, this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onOpenGLReady()
{
    scene = MelonGames::Particles::ParticlesScene::create();
    cocos2d::Director::getInstance()->runWithScene(scene);

    updateEmitterMode();

    initBackgroundController();
    initParticleController();
    initTextureController();
}

void MainWindow::initBackgroundController()
{
    backgroundController = new MelonGames::Particles::BackgroundController(this);
    backgroundController->setParticlesScene(scene);

    backgroundController->setChangeImageButton(ui->backgroundImageSelectButton);
    backgroundController->setImageNameLabel(ui->backgroundImageNameLabel);

    backgroundController->setColorButton(ui->backgroundColorButton);

    backgroundController->setPositionTypeOptions(ui->positionTypeFreeRadioButton, ui->positionTypeRelativeRadioButton, ui->positionTypeGroupedRadioButton);
    backgroundController->setPositionTypeTest(ui->positionTypeTestButton);

    backgroundController->update();
}

void MainWindow::initParticleController()
{
    particleController = new MelonGames::Particles::ParticleController(this);

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

    particleController->setUIGravityX(ui->gravityXFrame);
    particleController->setUIGravityY(ui->gravityYFrame);
    particleController->setUISpeed(ui->speedFrame);
    particleController->setUISpeedVar(ui->speedVarFrame);
    particleController->setUITangentialAcceleration(ui->tangentialAccelFrame);
    particleController->setUITangentialAccelerationVar(ui->tangentialAccelVarFrame);
    particleController->setUIRadialAcceleration(ui->radialAccelFrame);
    particleController->setUIRadialAccelerationVar(ui->radialAccelVarFrame);
    particleController->setUIRotationIsDir(ui->rotationIsDirFrame);

    particleController->setUIStartRadius(ui->startRadiusFrame);
    particleController->setUIStartRadiusVar(ui->startRadiusVarFrame);
    particleController->setUIEndRadius(ui->endRadiusFrame);
    particleController->setUIEndRadiusVar(ui->endRadiusVarFrame);
    particleController->setUIRotatePerSecond(ui->rotatePerSecondFrame);
    particleController->setUIRotatePerSecondVar(ui->rotatePerSecondVarFrame);
}

void MainWindow::initTextureController()
{
    textureController = new MelonGames::Particles::TextureController(this);

    textureController->setUIWidgets(ui->textureImage, ui->textureEmbeddedRadioButton, ui->textureExternalRadioButton);
}

void MainWindow::save()
{
    if (scene)
    {
        MelonGames::Particles::FileParser fileParser;

        auto selectedMode = (ui->modeGravityRadioButton->isChecked() ? cocos2d::ParticleSystem::Mode::GRAVITY : cocos2d::ParticleSystem::Mode::RADIUS);
        fileParser.save(path, selectedMode, scene->getParticleSystem(cocos2d::ParticleSystem::Mode::GRAVITY), scene->getParticleSystem(cocos2d::ParticleSystem::Mode::RADIUS), "");
    }
}

void MainWindow::load()
{
    if (scene)
    {
        MelonGames::Particles::FileParser fileParser;
        auto selectedMode = fileParser.load(path, scene->getParticleSystem(cocos2d::ParticleSystem::Mode::GRAVITY), scene->getParticleSystem(cocos2d::ParticleSystem::Mode::RADIUS));

        bool isGravity = (selectedMode == cocos2d::ParticleSystem::Mode::GRAVITY);
        ui->modeGravityRadioButton->setChecked(isGravity);
        ui->modeRadiusRadioButton->setChecked(!isGravity);

        updateEmitterMode();

        particleController->reload();
    }
}

void MainWindow::updateEmitterMode()
{
    if (scene)
    {
        auto selectedMode = (ui->modeGravityRadioButton->isChecked() ? cocos2d::ParticleSystem::Mode::GRAVITY : cocos2d::ParticleSystem::Mode::RADIUS);
        bool isGravity = (selectedMode == cocos2d::ParticleSystem::Mode::GRAVITY);

        scene->getParticleSystem(cocos2d::ParticleSystem::Mode::GRAVITY)->setVisible(isGravity);
        scene->getParticleSystem(cocos2d::ParticleSystem::Mode::RADIUS)->setVisible(!isGravity);

        ui->particlesGravityConfigFrame->setVisible(isGravity);
        ui->particlesRadiusConfigFrame->setVisible(!isGravity);
    }
}

void MainWindow::onModeRadioButtonClicked()
{
    updateEmitterMode();
}

void MainWindow::onMenuFileNew()
{
    if (scene)
    {
        scene->reset();
        updateEmitterMode();
        particleController->reload();
    }
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
