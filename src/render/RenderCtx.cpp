#include "RenderCtx.hpp"

Sprite *RenderCtx::sprite(uint spriteId)
{
    return &(sprites[spriteId]);
}

uint RenderCtx::addSprite(Sprite sprite)
{
    sprites.push_back(sprite);
    return static_cast<uint>(sprites.size() - 1);
}