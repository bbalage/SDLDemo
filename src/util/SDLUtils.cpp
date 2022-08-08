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

std::unique_ptr<SDL_Texture, SDLTextureDeleter> sdldemo::loadTexture(std::string_view filePath, SDL_Renderer *pSDLRenderer)
{
    SDL_Surface *pTempSurface = IMG_Load(filePath.data());
    if (pTempSurface == NULL)
    {
        std::runtime_error(std::string("Could not load image!"));
    }
    SDL_Texture *pTexture = SDL_CreateTextureFromSurface(pSDLRenderer, pTempSurface);
    SDL_FreeSurface(pTempSurface);
    return std::unique_ptr<SDL_Texture, SDLTextureDeleter>(pTexture, SDLTextureDeleter{});
}