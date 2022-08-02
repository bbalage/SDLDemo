#ifndef SDLDEMO_UTIL_SDLUTILS_H
#define SDLDEMO_UTIL_SDLUTILS_H

#include <SDL2/SDL.h>
#include <iostream>
#include <memory>
#include <SDL2/SDL_image.h>

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

namespace sdldemo
{
    std::unique_ptr<SDL_Texture, SDLTextureDeleter> loadTexture(std::string_view filePath, SDL_Renderer *pSDLRenderer);
}
#endif