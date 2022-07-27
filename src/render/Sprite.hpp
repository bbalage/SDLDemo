#ifndef SDLDEMO_RENDER_SPRITE_H
#define SDLDEMO_RENDER_SPRITE_H

#include "renderUtils.hpp"

class Sprite
{
public:
    Sprite(SDL_Texture *pTexture, int frameWidth, int frameHeight) : m_pTexture(pTexture),
                                                                     m_frameWidth(frameWidth),
                                                                     m_frameHeight(frameHeight) {}
    ~Sprite() { SDL_DestroyTexture(m_pTexture); }
    Sprite(const Sprite &) = delete;
    Sprite &operator=(const Sprite &) = delete;
    Sprite(Sprite &&);
    Sprite &operator=(Sprite &&);

    SDL_Texture *texture() { return m_pTexture; }
    SDL_Rect frameRect(int spriteRow, int spriteCol) const
    {
        return SDL_Rect(spriteRow * m_frameHeight, spriteCol * m_frameWidth, m_frameWidth, m_frameHeight);
    }
    int frameWidth() const { return m_frameWidth; }
    int frameHeight() const { return m_frameHeight; }

private:
    // TODO: Make sprite visibly own texture! (unique_ptr)
    SDL_Texture *m_pTexture;
    int m_frameWidth;
    int m_frameHeight;
};

#endif