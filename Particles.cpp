//
// Created by kalenshi on 5/29/20.
//

#include "Particles.h"
#include <math.h>
#include <stdlib.h>


namespace sdl {

    Particles::Particles() : x_coord(0), y_coord(0) {
        direction = (2 * M_PI * rand()) / RAND_MAX;
        speed = (0.001 * rand()) / RAND_MAX;

    }

    void Particles::update(int interval) {
        double xspeed = speed * cos(direction);
        double yspeed = speed * sin(direction);

        this->x_coord += xspeed * interval;
        this->y_coord += yspeed * interval;
    }

    Particles::~Particles() {
        //TODO Auto-generated destructor stub
    }
}