#ifndef SDLDEMO_RENDER_RENDERCTX_H
#define SDLDEMO_RENDER_RENDERCTX_H

#include <SDL2/SDL.h>
#include <vector>
#include "renderUtils.hpp"

class RenderCtx
{
public:
    RenderCtx() {}

    Sprite *sprite(uint spriteId);
    /**
     * @brief Adds texture to context and returns the id of the texture.
     *
     * @param texture
     * @return uint
     */
    uint addSprite(Sprite sprite);

private:
    std::vector<Sprite> sprites;
};

#endif