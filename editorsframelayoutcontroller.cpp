#include "editorsframelayoutcontroller.h"

#include <QPushButton>
#include <QRegularExpression>

namespace MelonGames {
namespace Particles {

EditorsFrameLayoutController::EditorsFrameLayoutController(QWidget* frame, QObject *parent)
    : QObject(parent)
    , deployed(true)
{
    deployButton = frame->findChildren<QPushButton*>(QRegularExpression("deployButton")).first();
    connect(deployButton, SIGNAL(clicked()), this, SLOT(onDeployButtonPressed()));

    attributesFrame = frame->findChildren<QWidget*>(QRegularExpression("attributesFrame")).first();

    update();
}

EditorsFrameLayoutController::~EditorsFrameLayoutController()
{

}

void EditorsFrameLayoutController::onDeployButtonPressed()
{
    deployed = !deployed;
    update();
}

void EditorsFrameLayoutController::update()
{
    attributesFrame->setVisible(deployed);
    deployButton->setText(deployed ? "-" : "+");
}

} // namespace Particles
} // namespace MelonGames

