//
//  Created by Ricard Perez del Campo on 23/12/14.
//  Copyright (c) 2014 MelonGames. All rights reserved.
//

#ifndef __Particles__CocosInterface__
#define __Particles__CocosInterface__

#include <QOpenGLWidget>

namespace MelonGames
{
    namespace Particles
    {
        class CocosInterface
        {
        public:
            CocosInterface();

            void setup(QOpenGLWidget* openGL);
        };
    }
}

#endif /* defined(__Particles__CocosInterface__) */
