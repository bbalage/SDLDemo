#ifndef SDLDEMO_UTIL_SDLUTILS_H
#define SDLDEMO_UTIL_SDLUTILS_H

#include <SDL2/SDL.h>
#include <iostream>

struct SDLWindowDeleter
{
    void operator()(SDL_Window *window);
};

struct SDLRendererDeleter
{
    void operator()(SDL_Renderer *renderer);
};

struct SDLTextureDeleter
{
    void operator()(SDL_Texture *texture);
};
#endif