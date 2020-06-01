//
// Created by kalenshi on 5/29/20.
//

#ifndef SDLBASIC_SWARM_H
#define SDLBASIC_SWARM_H

#include "Particles.h"

namespace sdl {
    class Swarm {
    public:
        const static int NPARTICLES = 5000;
    private:
        Particles*  particles;
    public:
        Swarm();
        const Particles* const getParticles(){return particles;}
        virtual ~Swarm();
    };
}


#endif //SDLBASIC_SWARM_H
