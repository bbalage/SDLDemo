#ifndef SDLDEMO_RENDER_RENDERUTILS_H
#define SDLDEMO_RENDER_RENDERUTILS_H

#include "../util/Vector.hpp"

struct RenderInfo
{
    uint textureId;
    uint spriteRow;
    uint spriteCol;
    Vector2D target;
};

#endif