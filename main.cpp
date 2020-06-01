#include <iostream>
#include <math.h>
#include "Screen.h"
#include "Swarm.h"


using namespace std;

int main(int argc, char *argv[]) {

    srand(time(NULL));

    sdl::Screen screen;
    if (!screen.init()) {
        cout << "Error Initializing SDL. " << endl;
    }
    sdl::Swarm swarm;

    while (true) {
        //update particles
        //draw particles
        int elapsed = SDL_GetTicks();
        unsigned char red = (unsigned char) (1 + sin(elapsed * 0.0001)) * 128;
        unsigned char green = (unsigned char) (1 + sin(elapsed * 0.0002)) * 128;
        unsigned char blue = (unsigned char) (1 + sin(elapsed * 0.0003)) * 128;

        const sdl::Particles *particles = swarm.getParticles();

        for (int i = 0; i < sdl::Swarm::NPARTICLES; i++) {
            sdl::Particles particle = particles[i];
            int x = (particle.x_coord + 1) * sdl::Screen::SCREEN_WIDTH / 2;
            int y = (particle.y_coord + 1) * sdl::Screen::SCREEN_HEIGHT / 2;
            screen.setPixel(x, y, red, green, blue);
        }

        //Draw the screen
        screen.update();
        if (!screen.processEvents()) {
            break;
        }
    }
    screen.close();
    return EXIT_SUCCESS;
}
