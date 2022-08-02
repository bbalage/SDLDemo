#include "RendererCreator.hpp"
#include "../util/SDLUtils.hpp"

std::unique_ptr<Renderer> RendererCreatorSDL::createRenderer(std::vector<Sprite> sprites, SceneType sceneType)
{
    std::unique_ptr<Renderer> renderer = emptyRendererObject(sceneType);
    for (const auto &spriteFilePath : spriteFilePaths)
    {
        sdldemo::loadTexture(spriteFilePath, m_pSDLRenderer);
    }
}

std::unique_ptr<Renderer> RendererCreatorSDL::emptyRendererObject(SceneType sceneType)
{
    switch (sceneType)
    {
    case SceneType::SDL_GAME:
        return std::unique_ptr<Renderer>(new RendererSDLGame(m_pSDLRenderer));
    default:
        std::invalid_argument("Renderer for this type of Scene is not yet implemented!");
    }
}