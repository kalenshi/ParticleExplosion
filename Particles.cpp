//
// Created by kalenshi on 5/29/20.
//

#include "Particles.h"
#include <math.h>
#include <stdlib.h>


namespace sdl {

    Particles::Particles() {

        this->init();
    }

    void Particles::init() {
        this->x_coord = 0;
        this->y_coord = 0;

        direction = (2 * M_PI * rand()) / RAND_MAX;
        speed = (0.04 * rand()) / RAND_MAX;

        speed *= speed;
    }

    void Particles::update(int interval) {
        direction += interval * 0.0002;
        double xspeed = speed * cos(direction);
        double yspeed = speed * sin(direction);

        this->x_coord += xspeed * interval;
        this->y_coord += yspeed * interval;

        if (x_coord < -1 || x_coord > 1 || y_coord < -1 || y_coord > 1) {
            this->init();
        }
        if(rand() < RAND_MAX/100){
            this->init();
        }

    }

    Particles::~Particles() {
        //TODO Auto-generated destructor stub
    }
}