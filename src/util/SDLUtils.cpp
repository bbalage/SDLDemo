#include "SDLUtils.hpp"

void SDLWindowDeleter::operator()(SDL_Window *window)
{
    std::cout << "Destroying window." << std::endl;
    SDL_DestroyWindow(window);
}

void SDLRendererDeleter::operator()(SDL_Renderer *renderer)
{
    std::cout << "Destroying renderer." << std::endl;
    SDL_DestroyRenderer(renderer);
}

void SDLTextureDeleter::operator()(SDL_Texture *texture)
{
    std::cout << "Destroying texture." << std::endl;
    SDL_DestroyTexture(texture);
}