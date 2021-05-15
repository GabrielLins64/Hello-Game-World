// Example program:
// Using SDL2 to create an application window

#include "Game.h"

Game *game = 0;

int main(int argc, char *argv[])
{

    game = new Game();

    if (!game->init("Chapter 1", 100, 100, 640, 480, false))
    {
        std::cout << "Game initialization failed!\n";
        return 1;
    }

    while (game->isRunning())
    {
        game->handleEvents();
        game->update();
        game->render();

        SDL_Delay(10);
    }
    game->clean();

    return 0;
}
