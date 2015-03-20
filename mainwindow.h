#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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
    void on_expandEditorButton_clicked();

private:
    void updateExpanded();

private:
    Ui::MainWindow *ui;
    bool scrollExpanded;
};

#endif // MAINWINDOW_H
