#include "Game.h"

bool Game::init(const char *title, int xpos, int ypos,
                int width, int height, bool fullscreen)
{
    int flags = 0;
    if (fullscreen)
    {
        flags = SDL_WINDOW_FULLSCREEN;
    }
    else
    {
        flags = SDL_WINDOW_RESIZABLE;
    }

    if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
    {
        std::cout << "SDL init success\n";
        window = SDL_CreateWindow(title, xpos, ypos,
                                  width, height, flags);
        if (window != 0)
        {
            std::cout << "Window creation success!\n";
            renderer = SDL_CreateRenderer(window, -1, 0);

            if (renderer != 0)
            {
                std::cout << "Renderer creation success!\n";
                SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
            }
            else
            {
                std::cout << "Renderer init fail\n";
                return false;
            }
        }
        else
        {
            std::cout << "Window init fail\n";
            return false;
        }
    }
    else
    {
        std::cout << "SDL init fail\n";
        return false;
    }
    
    if (!TheTextureManager::Instance()->load("assets/graphics/animate-alpha.png", "animate", renderer))
    {
        std::cout << "Failed to load texture!\n";
        return false;
    }

    go = new GameObject();
    player = new Player();
    enemy = new Enemy();

    go->load(100, 100, 128, 82, "animate");
    player->load(300, 300, 128, 82, "animate");
    enemy->load(0, 0, 128, 82, "animate");

    gameObjects.push_back(go);
    gameObjects.push_back(player);
    gameObjects.push_back(enemy);

    std::cout << "Init success\n";
    running = true;

    return true;
}

void Game::update()
{
    for(std::vector<GameObject*>::size_type i = 0;
    i != gameObjects.size(); i++)
    {
        gameObjects[i]->update();
    }
}

void Game::render()
{
    SDL_RenderClear(renderer);
    
    for(std::vector<GameObject*>::size_type i = 0;
    i != gameObjects.size(); i++)
    {
        gameObjects[i]->draw(renderer);
    }

    SDL_RenderPresent(renderer);
}

void Game::handleEvents()
{
    SDL_Event event;
    if (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
        case SDL_QUIT:
            running = false;
            break;

        default:
            break;
        }
    }
}

void Game::clean()
{
    std::cout << "cleaning game\n";
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
}
