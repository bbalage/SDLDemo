#include "SceneLoader.hpp"

std::unique_ptr<Scene> SceneLoaderSDLGame::loadScene(std::string_view sceneName)
{
    std::string scenePath{sdldemo::descriptorsDir() + sdldemo::separator() + std::string(sceneName)};
    std::cout << "Path to scene descriptor: " << scenePath << std::endl;
    SceneDescriptor sceneDescriptor = m_parser.parseSceneDescriptor(scenePath);

    // Load scene descriptor

    // std::unique_ptr<SceneSDLGame> scene{new SceneSDLGame(m_pWindow, m_Renderer)};
}