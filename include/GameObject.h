#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class GameObject
{
public:
    void load(int x, int y, int width, int height, std::string textureID);
    void draw(SDL_Renderer *renderer);
    void update();
    void clean();

protected:
    std::string textureID;

    int currentFrame;
    int currentRow;

    int x;
    int y;

    int width;
    int height;
};
