//
// Created by kalenshi on 5/27/20.
//

#ifndef SDLBASIC_SCREEN_H
#define SDLBASIC_SCREEN_H


#include <SDL2/SDL.h>

namespace sdl {
    class Screen {
    public:
        const static int SCREEN_WIDTH = 1500;
        const static int SCREEN_HEIGHT = 900;

    private:
        SDL_Window *m_window;
        SDL_Renderer *m_renderer;
        SDL_Texture *m_texture;
        SDL_Surface *m_surface;
        Uint32 *m_buffer;
        Uint32 *m_buffer2;
    public:
        Screen();

        bool init();

        void close();

        void update();

        bool processEvents();

        void setPixel(int x, int y, Uint8 red, Uint8 green, Uint8 blue);


        void boxBlur();
    };
}


#endif //SDLBASIC_SCREEN_H
