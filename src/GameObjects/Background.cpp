#include "Background.hpp"

void Background::update()
{
    // TODO: In case of background damage, RenderInfo update could be needed.
}

RenderInfo Background::renderInfo() const
{
    return RenderInfo{
        m_spriteId,
        0,
        0,
        m_pos};
}