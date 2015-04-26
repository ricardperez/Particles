#ifndef MELONGAMES_PARTICLES_FILEPARSER_H
#define MELONGAMES_PARTICLES_FILEPARSER_H

#include <QObject>
#include <string>
#include "base/CCValue.h"

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

            void load(const QString& filePath, cocos2d::ParticleSystemQuad* particleSystem);
            void save(const QString& filePath, const cocos2d::ParticleSystemQuad* particleSystem, const std::string& textureFileName);

        signals:

        public slots:

        private:
            void convertParticleSystemToValueMap(const cocos2d::ParticleSystemQuad* particleSystem, const std::string& textureFileName, cocos2d::ValueMap& valueMap);
        };

    } // namespace Particles
} // namespace MelonGames

#endif // MELONGAMES_PARTICLES_FILEPARSER_H
