#include "Renderer.hpp"

#include "../Parser/parseUtils.hpp"
#include "../Game/GameData.hpp"

RendererSDLGamePreloadSprites::RendererSDLGamePreloadSprites(
    SDL_Renderer *in_pRenderer,
    const std::unordered_set<std::string> &requiredSpriteNames) : m_pRenderer(in_pRenderer)
{
    for (const std::string &spriteName : requiredSpriteNames)
    {
        const SpriteDescriptor &spriteDescriptor = GameData::instance().spriteDescriptors().at(spriteName);
        Sprite sprite{
            sdldemo::loadTexture(spriteDescriptor.spritePath, m_pRenderer),
            spriteDescriptor.frameWidth,
            spriteDescriptor.frameHeight};
        m_spriteNameMap[spriteName] = static_cast<uint>(m_sprites.size());
        m_sprites.push_back(std::move(sprite));
    }
    SDL_SetRenderDrawColor(m_pRenderer, 255, 255, 255, 255);
}

void RendererSDLGamePreloadSprites::startRendering()
{
    SDL_RenderClear(m_pRenderer);
}

void RendererSDLGamePreloadSprites::render(const RenderInfo &renderInfo)
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

void RendererSDLGamePreloadSprites::finishRendering()
{
    SDL_RenderPresent(m_pRenderer);
}

uint RendererSDLGamePreloadSprites::idForName(const std::string &spriteName) const
{
    return m_spriteNameMap.at(spriteName);
}