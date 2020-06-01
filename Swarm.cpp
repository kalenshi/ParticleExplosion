//
// Created by kalenshi on 5/29/20.
//

#include "Swarm.h"

namespace sdl {
    Swarm::Swarm() {
        particles = new Particles[NPARTICLES];
    }

    Swarm::~Swarm() {
        delete [] particles;
    }
}
