#include "Renderer.hpp"

void RendererSDLGame::startRendering()
{
    SDL_RenderClear(m_pRenderer);
}

void RendererSDLGame::render(const RenderInfo &renderInfo)
{
    SDL_RenderCopy(m_pRenderer, m_pTexture, &m_sourceRectangle, &m_destinationRectangle);
}

void RendererSDLGame::finishRendering()
{
    SDL_RenderPresent(m_pRenderer);
}