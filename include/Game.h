#ifndef __Game__
#define __Game__

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include "TextureManager.h"

class Game
{
public:
    Game(){};
    ~Game(){};

    bool init(const char *title, int xpos, int ypos,
              int width, int height, bool fullscreen);

    void render();
    void update();
    void handleEvents();
    void clean();

    bool isRunning() { return running; }

private:
    SDL_Window *window;
    SDL_Renderer *renderer;

    int currentFrame;
    bool running;
};

#endif
