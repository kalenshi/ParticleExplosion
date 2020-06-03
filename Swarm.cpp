//
// Created by kalenshi on 5/29/20.
//

#include "Swarm.h"

namespace sdl {
    Swarm::Swarm() : lastTime(0) {
        particles = new Particles[NPARTICLES];
    }

    Swarm::~Swarm() {
        delete[] particles;
    }

    void Swarm::update(int elapsed) {
        int interval = elapsed - this->lastTime;
        for (int i = 0; i < Swarm::NPARTICLES; i++) {
            this->particles[i].update(interval);
        }
        this->lastTime = elapsed;
    }
}
