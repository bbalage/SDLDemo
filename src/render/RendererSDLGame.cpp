#include "Renderer.hpp"

void RendererSDLGame::startRendering()
{
    SDL_RenderClear(m_pRenderer);
}

void RendererSDLGame::render(const RenderInfo &renderInfo)
{
    Sprite *pSprite = ctx.sprite(renderInfo.spriteId);
    SDL_Rect sourceRect = pSprite->frameRect(renderInfo.spriteRow, renderInfo.spriteCol);
    SDL_Rect destRect{
        renderInfo.target.x,
        renderInfo.target.y,
        pSprite->frameWidth(),
        pSprite->frameHeight()};

    SDL_RenderCopy(m_pRenderer, pSprite->texture(), &sourceRect, &destRect);
}

void RendererSDLGame::finishRendering()
{
    SDL_RenderPresent(m_pRenderer);
}