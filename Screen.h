//
// Created by kalenshi on 5/27/20.
//

#ifndef SDLBASIC_SCREEN_H
#define SDLBASIC_SCREEN_H


#include <SDL2/SDL.h>

namespace sdl {
    class Screen {
    public:
        const static int SCREEN_WIDTH = 600;
        const static int SCREEN_HEIGHT = 800;

    private:
        SDL_Window *m_window;
        SDL_Renderer *m_renderer;
        SDL_Texture *m_texture;
        SDL_Surface *m_surface;
        Uint32 *m_buffer;
    public:
        Screen();

        bool init();

        void close();

        void update();

        bool processEvents();

        void setPixel(int x, int y, Uint8 red, Uint8 green, Uint8 blue);


    };
}


#endif //SDLBASIC_SCREEN_H
