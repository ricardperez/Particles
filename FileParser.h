#ifndef MELONGAMES_PARTICLES_FILEPARSER_H
#define MELONGAMES_PARTICLES_FILEPARSER_H

#include <QObject>
#include <string>
#include "base/CCValue.h"
#include "2d/CCParticleSystem.h"

namespace cocos2d
{
    class ParticleSystemQuad;
}

namespace MelonGames {
    namespace Particles {

        class FileParser : public QObject
        {
            Q_OBJECT
        public:
            explicit FileParser(QObject *parent = 0);
            ~FileParser();

            cocos2d::ParticleSystem::Mode load(const QString& filePath, cocos2d::ParticleSystemQuad* particleSystemGravity, cocos2d::ParticleSystemQuad* particleSystemRadius);
            void save(const QString& filePath, cocos2d::ParticleSystem::Mode mode, cocos2d::ParticleSystemQuad* particleSystemGravity, cocos2d::ParticleSystemQuad* particleSystemRadius, const std::string& textureFileName, const QImage* texture);

        signals:

        public slots:

        private:
            void convertParticleSystemToValueMap(cocos2d::ParticleSystem::Mode mode, cocos2d::ParticleSystemQuad* particleSystemGravity, cocos2d::ParticleSystemQuad* particleSystemRadius, const std::string& textureFileName, const QImage* texture, cocos2d::ValueMap& valueMap);
        };

    } // namespace Particles
} // namespace MelonGames

#endif // MELONGAMES_PARTICLES_FILEPARSER_H
