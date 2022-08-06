#include "RendererCreator.hpp"
#include "../util/SDLUtils.hpp"

std::unique_ptr<Renderer> RendererCreatorSDL::createRenderer(std::vector<Sprite> &&sprites, SceneType sceneType) const
{
    switch (sceneType)
    {
    case SceneType::SDL_GAME:
        return std::unique_ptr<Renderer>(new RendererSDLGame(m_pSDLRenderer, std::move(sprites)));
    default:
        std::invalid_argument("Renderer for this type of Scene is not yet implemented!");
    }
}