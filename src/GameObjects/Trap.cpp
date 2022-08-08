#include "Trap.hpp"

void Trap::update()
{
    // TODO: This is needed! Implement!
}

RenderInfo Trap::renderInfo() const
{
    return RenderInfo{
        m_spriteId,
        0,
        0,
        m_pos};
}