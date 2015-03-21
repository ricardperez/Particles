#ifndef MELONGAMES_PARTICLES_EDITORSFRAMELAYOUTCONTROLLER_H
#define MELONGAMES_PARTICLES_EDITORSFRAMELAYOUTCONTROLLER_H

#include <QObject>
#include <QWidget>
#include <QPushButton>

namespace MelonGames {
namespace Particles {

class EditorsFrameLayoutController : public QObject
{
    Q_OBJECT
public:
    explicit EditorsFrameLayoutController(QWidget* frame, QObject *parent = 0);
    ~EditorsFrameLayoutController();

signals:

private slots:
    void onDeployButtonPressed();

private:
    void update();

private:
    bool deployed;
    QPushButton* deployButton;
    QWidget* attributesFrame;

};

} // namespace Particles
} // namespace MelonGames

#endif // MELONGAMES_PARTICLES_EDITORSFRAMELAYOUTCONTROLLER_H
