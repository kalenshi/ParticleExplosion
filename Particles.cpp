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
}