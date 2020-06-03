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
    private:
        double speed;
        double direction;

    public:
        Particles();

        void update(int interval);

        virtual ~Particles();

    private:
        void init();
    };
}


#endif //SDLBASIC_PARTICLES_H
