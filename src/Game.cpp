#include "Game.h"
#include <iostream>

bool Game::init(const char* title, int xpos, int ypos,
                int width, int height, bool fullscreen)
{
    int flags = 0;
    if(fullscreen)
    {
        flags = SDL_WINDOW_FULLSCREEN;
    }

    if(SDL_Init(SDL_INIT_EVERYTHING) == 0)
    {
        std::cout << "SDL init success\n";
        window = SDL_CreateWindow(title, xpos,  ypos, 
                                  width, height, flags);
        if(window != 0)
        {
            std::cout << "Window creation success!\n";
            renderer = SDL_CreateRenderer(window, -1, 0);

            if(renderer != 0)
            {
                std::cout << "Renderer creation success!\n";
                SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
            }
            else
            {
                std::cout << "Renderer init fail\n";
                return false;
            }
        }
        else {
            std::cout << "Window init fail\n";
            return false;
        }
    }
    else 
    {
        std::cout << "SDL init fail\n";   
        return false;
    }

    std::cout << "Init success\n";
    m_bRunning = true;

    SDL_Surface* tmpSurface = SDL_LoadBMP("assets/graphics/animate.bmp");
    texture = SDL_CreateTextureFromSurface(renderer, tmpSurface);
    SDL_FreeSurface(tmpSurface);

    sourceRectangle.w = 128;
    sourceRectangle.h = 82;
    destinationRectangle.x = sourceRectangle.x = 0;
    destinationRectangle.y = sourceRectangle.y = 0;

    destinationRectangle.w = sourceRectangle.w;
    destinationRectangle.h = sourceRectangle.h;

    return true;
}

void Game::update()
{
    sourceRectangle.x = 128 * int((SDL_GetTicks() / 100) % 6);
}

void Game::render()
{
    SDL_RenderClear(renderer);

    SDL_RenderCopyEx(renderer, texture, &sourceRectangle, &destinationRectangle,
                     0, 0, SDL_FLIP_HORIZONTAL);

    SDL_RenderPresent(renderer);
}

void Game::handleEvents()
{
    SDL_Event event;
    if(SDL_PollEvent(&event))
    {
        switch (event.type)
        {
            case SDL_QUIT:
                m_bRunning = false;
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
