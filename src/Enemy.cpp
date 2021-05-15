#include "Enemy.h"

void Enemy::load(int x, int y, int width, int height, std::string textureID)
{
    GameObject::load(x, y, width, height, textureID);
}

void Enemy::draw(SDL_Renderer *renderer)
{
    GameObject::draw(renderer);
}

void Enemy::update()
{
    x += 1;
    y += 1;
    currentFrame = int((SDL_GetTicks() / 100) % 6);
}

void Enemy::clean()
{
    GameObject::clean();
}
