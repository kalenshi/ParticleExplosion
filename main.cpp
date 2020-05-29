#include <iostream>
#include <math.h>
#include "Screen.h"

using namespace std;

int main(int argc, char *argv[]) {
    sdl::Screen screen;
    if (!screen.init()) {
        std::cout << "Error Initializing SDL. " << std::endl;
    }

    while (true) {
        //update particles
        //draw particles
        int elapsed = SDL_GetTicks();
        unsigned char red = (unsigned char) (1 + sin(elapsed * 0.0001)) * 128;
        unsigned char green = (unsigned char) (1 + sin(elapsed * 0.0002)) * 128;
        unsigned char blue = (unsigned char) (1 + sin(elapsed * 0.0003)) * 128;
        for (int y = 0; y < sdl::Screen::SCREEN_HEIGHT; y++) {
            for (int x = 0; x < sdl::Screen::SCREEN_WIDTH; x++) {
                screen.setPixel(x, y, red, green, blue);
            }
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
