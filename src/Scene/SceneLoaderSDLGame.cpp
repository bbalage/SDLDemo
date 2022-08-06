#include "SceneLoader.hpp"

std::unique_ptr<Scene> SceneLoaderSDLGame::loadScene(std::string_view sceneName)
{
    std::string scenePath{sdldemo::descriptorsDir() + sdldemo::separator() + std::string(sceneName)};
    std::cout << "Path to scene descriptor: " << scenePath << std::endl;
    SceneDescriptor sceneDescriptor = m_parser.parseSceneDescriptor(scenePath);
    auto sprites = readRequiredSprites(sceneDescriptor);
    auto renderer = m_rendererCreator.createRenderer(std::move(sprites), SceneType::SDL_GAME);
    // std::unique_ptr<Player> player(new Player());

    // return std::unique_ptr<SceneSDLGame> scene{new SceneSDLGame(m_pWindow, renderer,)};
}