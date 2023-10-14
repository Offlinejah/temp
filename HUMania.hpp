#include<SDL2/SDL.h> //Changing this to #include<SDL.h> might make it work on your machine


void drawObjects(SDL_Renderer* gRnderer, SDL_Texture* assets);
void createObject(int x, int y);

struct Unit{
SDL_Rect srcRect, moverRect;
};
