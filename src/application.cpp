#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "application.h"

Application::Application()
{
    window = SDL_CreateWindow("4 in a Row", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 700, 600, 0);;
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    
    SDL_Init(SDL_INIT_VIDEO);
    IMG_Init(IMG_INIT_PNG);
}

Application::~Application()
{
    IMG_Quit();
    SDL_Quit();
}

void Application::renderObj(SDL_Rect rect, char *path)
{
    SDL_Surface *surface = IMG_Load(path);
    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
    SDL_RenderCopy(renderer, texture, NULL, &rect);
    SDL_RenderPresent(renderer);
}