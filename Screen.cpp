//
// Created by kalenshi on 5/27/20.
//
#include<iostream>
#include "Screen.h"


namespace sdl {
    bool sdl::Screen::processEvents() {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                return false;
            }
        }

        return true;
    }

    sdl::Screen::Screen() : m_window(NULL), m_renderer(NULL), m_texture(NULL), m_surface(NULL),
                            m_buffer(NULL), m_buffer2(NULL) {

    }

    bool sdl::Screen::init() {
        const char *TITLE = "Particle Explosion";

        if (SDL_Init(SDL_INIT_VIDEO) < 0) {
            std::cout << "SDL init failed. " << std::endl;
            return EXIT_FAILURE;
        }
        this->m_window = SDL_CreateWindow(TITLE, SDL_WINDOWPOS_UNDEFINED,
                                          SDL_WINDOWPOS_UNDEFINED,
                                          Screen::SCREEN_WIDTH, Screen::SCREEN_HEIGHT, SDL_WINDOW_RESIZABLE);

        if (this->m_window == NULL) {
            return false;
        }
        this->m_renderer = SDL_CreateRenderer(this->m_window, -1,
                                              SDL_RENDERER_PRESENTVSYNC);
        this->m_texture = SDL_CreateTexture(this->m_renderer,
                                            SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET,
                                            Screen::SCREEN_WIDTH,
                                            Screen::SCREEN_HEIGHT);
        if (this->m_renderer == NULL || this->m_texture == NULL) {
            std::cout << "Could Not Create Renderer/Texture .." << SDL_GetError() << std::endl;
            SDL_DestroyWindow(this->m_window);
            SDL_Quit();
            return false;
        }

        this->m_buffer = new Uint32[Screen::SCREEN_WIDTH * Screen::SCREEN_HEIGHT];
        this->m_buffer2 = new Uint32[Screen::SCREEN_WIDTH * Screen::SCREEN_HEIGHT];

        memset(this->m_buffer, 0, SCREEN_WIDTH * SCREEN_HEIGHT * sizeof(Uint32));
        memset(this->m_buffer2, 0, SCREEN_WIDTH * SCREEN_HEIGHT * sizeof(Uint32));
        return true;
    }

    void sdl::Screen::close() {
        delete[] this->m_buffer;
        delete[] this->m_buffer2;
        SDL_DestroyRenderer(this->m_renderer);
        SDL_DestroyTexture(this->m_texture);
        SDL_DestroyWindow(this->m_window);
        SDL_Quit();
    }

    /**
     *  set the individual pixel on the screen
     *  with the appropriate rgb code
     * @param x - x position on the screen
     * @param y - y position on the screen
     * @param red - int to represent red component
     * @param green - int to represent the green component
     * @param blue - int to represent the blue component
     */
    void Screen::setPixel(int x, int y, Uint8 red, Uint8 green, Uint8 blue) {
        if (x < 0 || x >= SCREEN_WIDTH || y < 0 || y >= SCREEN_HEIGHT) {
            return;
        }
        Uint32 color = 0;
        color += red;
        color <<= 8;
        color += green;
        color <<= 8;
        color += blue;
        color <<= 8;
        color += 0xFF;

        this->m_buffer[(y * SCREEN_WIDTH) + x] = color;
    }

    void Screen::update() {
        SDL_UpdateTexture(this->m_texture, NULL, this->m_buffer, Screen::SCREEN_WIDTH * sizeof(Uint32));
        SDL_RenderClear(this->m_renderer);
        SDL_RenderCopy(this->m_renderer, this->m_texture, NULL, NULL);
        SDL_RenderPresent(this->m_renderer);
    }


    void Screen::boxBlur() {
        Uint32 *tmp = this->m_buffer;
        this->m_buffer = this->m_buffer2;
        this->m_buffer2 = tmp;

        for (int y = 0; y < Screen::SCREEN_HEIGHT; y++) {
            for (int x = 0; x < Screen::SCREEN_WIDTH; x++) {
                /*
                 * 0 0 0
                 * 0 1 0
                 * 0 0 0
                 */
                int redTotal = 0;
                int greenTotal = 0;
                int blueTotal = 0;

                for (int row = -1; row <= 1; row++) {
                    for (int col = -1; col <= 1; col++) {
                        int currentX = x + col;
                        int currentY = y + row;

                        if (currentX >= 0 && currentX < Screen::SCREEN_WIDTH && currentY >= 0 &&
                            currentY < Screen::SCREEN_HEIGHT) {
                            Uint32 color = this->m_buffer2[currentY * Screen::SCREEN_WIDTH + currentX];
                            Uint8 red = color >> 24;
                            Uint8 green = color >> 16;
                            Uint8 blue = color >> 8;

                            redTotal += red;
                            greenTotal += green;
                            blueTotal += blue;
                        }
                    }
                }
                Uint8 red = redTotal / 9;
                Uint8 green = greenTotal / 9;
                Uint8 blue = blueTotal / 9;

                this->setPixel(x, y, red, green, blue);
            }

        }

    }
}

