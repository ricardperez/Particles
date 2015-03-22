#include "backgroundimagecontroller.h"
#include "../Scene/particlesscene.h"
#include <QFileDialog>
#include <QDebug>

namespace MelonGames {
namespace Particles {

BackgroundImageController::BackgroundImageController(QObject* parent)
    : QObject(parent)
    , scene(nullptr)
    , changeImageButton(nullptr)
    , imageNameLabel(nullptr)
    , hasBackgroundImage(false)
{

}

BackgroundImageController::~BackgroundImageController()
{

}

void BackgroundImageController::setParticlesScene(ParticlesScene *scene)
{
    this->scene = scene;
}

void BackgroundImageController::setChangeImageButton(QPushButton *button)
{
    Q_ASSERT(!changeImageButton);
    changeImageButton = button;

    connect(changeImageButton, SIGNAL(clicked()), this, SLOT(onChangeImageButtonPressed()));
}

void BackgroundImageController::setImageNameLabel(QLabel *label)
{
    imageNameLabel = label;
}

void BackgroundImageController::update()
{
    Q_ASSERT(scene);
    Q_ASSERT(changeImageButton);
    Q_ASSERT(imageNameLabel);

    changeImageButton->setText(hasBackgroundImage ? "Clear" : "Add");
    imageNameLabel->setText(hasBackgroundImage ? imageName : "");
}

void BackgroundImageController::onChangeImageButtonPressed()
{
    Q_ASSERT(scene);

    if (!hasBackgroundImage)
    {
        imageName = QFileDialog::getOpenFileName(nullptr, "Select image", "", "Images (*.png *.png *.webp");
    }
    else
    {
        imageName.clear();
    }

    hasBackgroundImage = !imageName.isEmpty();
    if (hasBackgroundImage)
    {
        qDebug() << "Selected image: " << imageName;
        changeImageButton->setText("Clear image");
        scene->setBackgroundImage(std::string(imageName.toUtf8().constData()));
    }
    else
    {
        scene->clearBackgroundImage();
    }

    update();
}

} // namespace Particles
} // namespace MelonGames

