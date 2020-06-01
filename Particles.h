//
// Created by kalenshi on 5/29/20.
//

#ifndef SDLBASIC_PARTICLES_H
#define SDLBASIC_PARTICLES_H

#include <iostream>

namespace sdl {
    struct Particles {
    private:
        double x_coord;
        double y_coord;
    public:
        Particles(double x, double y);

        virtual ~Particles() {};

    };
}


#endif //SDLBASIC_PARTICLES_H
