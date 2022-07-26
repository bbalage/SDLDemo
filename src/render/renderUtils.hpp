#ifndef SDLDEMO_RENDER_RENDERUTILS_H
#define SDLDEMO_RENDER_RENDERUTILS_H

#include "../util/Vector.hpp"
#include <SDL2/SDL.h>

class Sprite
{
public:
    Sprite(SDL_Texture *pTexture, int frameWidth, int frameHeight) : m_pTexture(pTexture),
                                                                     m_frameWidth(frameWidth),
                                                                     m_frameHeight(frameHeight) {}
    ~Sprite() { SDL_DestroyTexture(m_pTexture); }
    Sprite(const Sprite &) = delete;
    Sprite &operator=(const Sprite &) = delete;
    Sprite(Sprite &&) = default;
    Sprite &operator=(Sprite &&) = default;

    SDL_Texture *texture() { return m_pTexture; }
    SDL_Rect frameRect(int spriteRow, int spriteCol) const
    {
        return SDL_Rect(spriteRow * m_frameHeight, spriteCol * m_frameWidth, m_frameWidth, m_frameHeight);
    }
    int frameWidth() const { return m_frameWidth; }
    int frameHeight() const { return m_frameHeight; }

private:
    SDL_Texture *const m_pTexture;
    int m_frameWidth;
    int m_frameHeight;
};

struct RenderInfo
{
    uint spriteId;
    uint spriteRow;
    uint spriteCol;
    Vec2 target;
};

#endif