//
// Created by kalenshi on 5/29/20.
//

#ifndef SDLBASIC_PARTICLES_H
#define SDLBASIC_PARTICLES_H

#include <iostream>

namespace sdl {
    struct Particles {
        double x_coord;
        double y_coord;

        double XSPEED = 0.001 * (((2.0 * rand()) / RAND_MAX) - 1);
        double YSPEED= 0.001 * (((2.0 * rand()) / RAND_MAX) - 1);

    public:
        Particles();
        void update();
        virtual ~Particles() ;

    };
}


#endif //SDLBASIC_PARTICLES_H
