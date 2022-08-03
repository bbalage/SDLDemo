#ifndef SDLDEMO_RENDER_RENDERUTILS_H
#define SDLDEMO_RENDER_RENDERUTILS_H

#include "../util/Vector.hpp"
#include <SDL2/SDL.h>

struct RenderInfo
{
    uint spriteId;
    uint spriteRow;
    uint spriteCol;
    Vec2 target;
};



#endif