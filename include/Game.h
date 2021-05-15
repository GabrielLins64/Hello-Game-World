#ifndef __Game__
#define __Game__

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <vector>
#include "TextureManager.h"

#include "GameObject.h"
#include "Player.h"
#include "Enemy.h"

class Game
{
public:
    Game(){};
    ~Game(){};

    bool init(const char *title, int xpos, int ypos,
              int width, int height, bool fullscreen);

    inline void draw();
    void render();
    void update();
    void handleEvents();
    void clean();

    bool isRunning() { return running; }

private:
    SDL_Window *window;
    SDL_Renderer *renderer;

    std::vector<GameObject*> gameObjects;

    GameObject* go;
    GameObject* player;
    GameObject* enemy;

    int currentFrame;
    bool running;
};

#endif
