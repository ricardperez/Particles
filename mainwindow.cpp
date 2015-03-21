#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "Scene/particlesscene.h"
#include "Controller/backgroundimagecontroller.h"
#include "base/CCDirector.h"

#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
  , scrollExpanded(true)
  , scene(nullptr)
  , optionsExpanded(false)
{
    ui->setupUi(this);

    updateScrollExpanded();
    updateOptionsExpanded();

    connect(ui->openGLWidget, SIGNAL(signalInitialized()), this, SLOT(onOpenGLReady()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onOpenGLReady()
{
    scene = MelonGames::Particles::ParticlesScene::create();
    cocos2d::Director::getInstance()->runWithScene(scene);

    initBackgroundImageController();
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

void MainWindow::on_expandOptionsButton_clicked()
{
    optionsExpanded = !optionsExpanded;
    updateOptionsExpanded();
}
