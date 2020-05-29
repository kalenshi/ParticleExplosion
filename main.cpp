#include <iostream>
#include <iomanip>
#include <SDL2/SDL.h>
#include "Screen.h"

int main(int argc, char *argv[]) {
//    unsigned char alpha = 0xFF;
//    unsigned char red = 0x12;
//    unsigned char green = 0x34;
//    unsigned char blue = 0x56;
//
//    unsigned int color = 0;
//    color += alpha;
//    color <<= 8;
//    color += red;
//    color <<= 8;
//    color += green;
//    color <<= 8;
//    color += blue;
//
//    cout << setfill('0') << setw(8) << hex << color << endl;

    sdl::Screen screen;
    if (!screen.init()) {
        std::cout << "Error Initializing SDL. " << std::endl;
    }

    while (true) {
        //update particles

        //draw particles
        for (int y = 0; y < sdl::Screen::SCREEN_HEIGHT; y++) {
            for (int x = 0; x <sdl::Screen::SCREEN_WIDTH ; x++) {
                screen.setPixel(x, y, 128, 0, 255);
            }
        }
        screen.setPixel(400, 300, 255, 255, 255);
        //Draw the screen
        screen.update();
        if (!screen.processEvents()) {
            break;
        }
    }

    screen.close();
    return EXIT_SUCCESS;
}
