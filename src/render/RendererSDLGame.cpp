#include "Renderer.hpp"

RendererSDLGame::RendererSDLGame(SDL_Renderer *in_pRenderer, std::vector<Sprite> &&sprites) : m_pRenderer(in_pRenderer),
                                                                                              m_sprites(sprites)
{
    SDL_SetRenderDrawColor(m_pRenderer, 255, 255, 255, 255);
}

void RendererSDLGame::startRendering()
{
    SDL_RenderClear(m_pRenderer);
}

void RendererSDLGame::render(const RenderInfo &renderInfo)
{
    Sprite *pSprite = &(m_sprites[renderInfo.spriteId]);
    SDL_Rect sourceRect = pSprite->frameRect(renderInfo.spriteRow, renderInfo.spriteCol);
    SDL_Rect destRect{
        renderInfo.target.x,
        renderInfo.target.y,
        pSprite->frameWidth(),
        pSprite->frameHeight()};

    // TODO: Do something with error code returned by SDL_RenderCopy! (use custom exception to handle the error)
    SDL_RenderCopy(m_pRenderer, pSprite->texture(), &sourceRect, &destRect);
}

void RendererSDLGame::finishRendering()
{
    SDL_RenderPresent(m_pRenderer);
}