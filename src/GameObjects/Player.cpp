#include "Player.hpp"

void Player::update()
{
}

const RenderInfo &Player::renderInfo() const
{
    return RenderInfo{
        m_spriteId,
        0,
        0,
        m_pos};
}