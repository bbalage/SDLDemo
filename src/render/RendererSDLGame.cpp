#include "Renderer.hpp"

RendererSDLGame::RendererSDLGame(SDL_Renderer *in_pRenderer) : m_pRenderer(in_pRenderer)
{
    SDL_SetRenderDrawColor(m_pRenderer, 255, 255, 255, 255);
}

void RendererSDLGame::startRendering()
{
    SDL_RenderClear(m_pRenderer);
}

void RendererSDLGame::render(const RenderInfo &renderInfo)
{
    Sprite *pSprite = &(sprites[renderInfo.spriteId]);
    SDL_Rect sourceRect = pSprite->frameRect(renderInfo.spriteRow, renderInfo.spriteCol);
    SDL_Rect destRect{
        renderInfo.target.x,
        renderInfo.target.y,
        pSprite->frameWidth(),
        pSprite->frameHeight()};

    int code = SDL_RenderCopy(m_pRenderer, pSprite->texture(), &sourceRect, &destRect);
    if (code == -1)
        std::cout << "Error: " << SDL_GetError() << std::endl;
}

void RendererSDLGame::finishRendering()
{
    SDL_RenderPresent(m_pRenderer);
}

uint RendererSDLGame::addSprite(Sprite &&sprite)
{
    sprites.push_back(std::move(sprite));
    return static_cast<uint>(sprites.size() - 1);
}