#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
  , scrollExpanded(true)
{
    ui->setupUi(this);

    updateExpanded();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_expandEditorButton_clicked()
{
    scrollExpanded = !scrollExpanded;
    updateExpanded();
}

void MainWindow::updateExpanded()
{
    ui->editorVerticalSpacer->changeSize(0, 0, (scrollExpanded ? QSizePolicy::Ignored : QSizePolicy::MinimumExpanding), (scrollExpanded ? QSizePolicy::Ignored : QSizePolicy::MinimumExpanding));
    ui->scrollArea->setVisible(scrollExpanded);
    ui->editorFrame->setMinimumWidth(scrollExpanded ? 400.0f : 120.0f);
    ui->editorFrame->setMaximumWidth(scrollExpanded ? 400.0f : 120.0f);

    ui->expandEditorButton->setText(scrollExpanded ? "Close" : "Expand");
}
