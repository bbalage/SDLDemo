#ifndef SDLDEMO_RENDER_SPRITE_H
#define SDLDEMO_RENDER_SPRITE_H

#include "../util/SDLUtils.hpp"
#include "renderUtils.hpp"
#include <memory>

class Sprite
{
public:
    Sprite(
        std::unique_ptr<SDL_Texture, SDLTextureDeleter> pTexture,
        int frameWidth,
        int frameHeight) : m_pTexture(std::move(pTexture)),
                           m_frameWidth(frameWidth),
                           m_frameHeight(frameHeight) {}
    ~Sprite() {}
    Sprite(const Sprite &) = delete;
    Sprite &operator=(const Sprite &) = delete;
    Sprite(Sprite &&) = default;
    Sprite &operator=(Sprite &&) = default;

    SDL_Texture *texture() { return m_pTexture.get(); }
    SDL_Rect frameRect(int spriteRow, int spriteCol) const
    {
        return SDL_Rect(spriteRow * m_frameHeight, spriteCol * m_frameWidth, m_frameWidth, m_frameHeight);
    }
    int frameWidth() const { return m_frameWidth; }
    int frameHeight() const { return m_frameHeight; }

private:
    std::unique_ptr<SDL_Texture, SDLTextureDeleter> m_pTexture;
    int m_frameWidth;
    int m_frameHeight;
};

#endif