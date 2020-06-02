//
// Created by kalenshi on 5/29/20.
//

#include "Particles.h"
#include <stdlib.h>


namespace sdl {

    Particles::Particles() {
        x_coord = ((2.0 * rand()) / RAND_MAX) - 1;
        y_coord = ((2.0 * rand()) / RAND_MAX) - 1;
    }

    void Particles::update() {
        this->x_coord += XSPEED;
        this->y_coord += YSPEED;

        if (this->x_coord < -1.0 || this->x_coord >= 1.0) {
            XSPEED = -XSPEED;
        }
        if (this->y_coord < -1.0 || this->y_coord >= 1.0) {
            YSPEED = -YSPEED;
        }
    }

    Particles::~Particles() {
        //TODO Auto-generated destructor stub
    }
}