//
// Created by kalenshi on 5/29/20.
//

#include "Swarm.h"

namespace sdl {
    Swarm::Swarm() {
        particles = new Particles[NPARTICLES];
    }

    Swarm::~Swarm() {
        delete[] particles;
    }

    void Swarm::update() {
        //loop through all the particles
        for (int i = 0; i < Swarm::NPARTICLES; i++) {
            this->particles[i].update();
        }
    }
}
