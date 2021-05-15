#include "GameObject.h"
#include "TextureManager.h"

void GameObject::load(int x_, int y_, int width_, int height_, 
                      std::string textureID_)
{
    x = x_;
    y = y_;
    width = width_;
    height = height_;
    textureID = textureID_;

    currentFrame = 1;
    currentRow = 1;
}

void GameObject::draw(SDL_Renderer *renderer)
{
    TextureManager::Instance()->drawFrame(textureID, x, y, width,
                                          height, currentRow,
                                          currentFrame, renderer);
}

void GameObject::update()
{
    x += 1;
}

void GameObject::clean()
{
    std::cout << "Game Object cleaned!\n";
}
