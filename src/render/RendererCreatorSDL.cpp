#include "RendererCreator.hpp"
#include "../util/SDLUtils.hpp"

std::unique_ptr<Renderer> RendererCreatorSDL::createRenderer(const std::unordered_set<std::string> &requiredSpriteNames,
                                                             SceneType sceneType) const
{
    switch (sceneType)
    {
    case SceneType::SDL_GAME:
        return std::unique_ptr<Renderer>(new RendererSDLGamePreloadSprites(m_pSDLRenderer, std::move(requiredSpriteNames)));
    default:
        std::invalid_argument("Renderer for this type of Scene is not yet implemented!");
    }
}