#include "RenderCtx.hpp"

SDL_Texture *SDLRenderCtx::texture(uint textureId)
{
    return textures[textureId];
}

uint SDLRenderCtx::addTexture(SDL_Texture *texture)
{
    textures.push_back(texture);
    return static_cast<uint>(textures.size() - 1);
}