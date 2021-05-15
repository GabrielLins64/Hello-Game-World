#ifndef __GameObject__
#define __GameObject__

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class GameObject
{
public:
    virtual void load(int x, int y, int width, int height, std::string textureID);
    virtual void draw(SDL_Renderer *renderer);
    virtual void update();
    virtual void clean();

protected:
    std::string textureID;

    int currentFrame;
    int currentRow;

    int x;
    int y;

    int width;
    int height;
};

#endif
