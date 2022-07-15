#include "SceneManager.hpp"

Scene *SceneManagerSDLSimple::getScene()
{
    return currentScene.get();
}

void SceneManagerSDLSimple::setScene(SceneType sceneType)
{
    switch (sceneType)
    {
    case SceneType::SDL_GAME:
        if (!currentScene)
        {
            currentScene.reset(new SceneSDLGame(m_pWindow, m_pRenderer));
        }
        break;
    case SceneType::SDL_EXIT:
        currentScene.reset(nullptr);
        break;
    default:
        std::invalid_argument("SceneType switch not yet implemented.");
        break;
    }
}