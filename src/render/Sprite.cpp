#include "Sprite.hpp"

Sprite::Sprite(Sprite &&other)
{
    m_pTexture = other.m_pTexture;
    other.m_pTexture = nullptr;

    m_frameWidth = other.m_frameWidth;
    m_frameHeight = other.m_frameHeight;
}

Sprite &Sprite::operator=(Sprite &&other)
{
    m_pTexture = other.m_pTexture;
    other.m_pTexture = nullptr;

    m_frameWidth = other.m_frameWidth;
    m_frameHeight = other.m_frameHeight;
    return *this;
}