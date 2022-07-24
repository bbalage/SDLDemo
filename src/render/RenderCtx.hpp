#ifndef SDLDEMO_RENDER_RENDERCTX_H
#define SDLDEMO_RENDER_RENDERCTX_H

#include <SDL2/SDL.h>
#include <vector>

class SDLRenderCtx
{
public:
    SDLRenderCtx() {}

    SDL_Texture *texture(uint textureId);
    /**
     * @brief Adds texture to context and returns the id of the texture.
     *
     * @param texture
     * @return uint
     */
    uint addTexture(SDL_Texture *texture);

private:
    // TODO: Express that RenderCtx has ownership over textures!
    std::vector<SDL_Texture *> textures;
};

#endif