#include "SceneManager.hpp"

SceneManagerSDLSimple::SceneManagerSDLSimple(
    SDL_Window *in_pWindow,
    SDL_Renderer *in_pRenderer) : SceneManagerSDL(in_pWindow, in_pRenderer)
{
    m_sceneLoaders[SceneType::SDL_GAME] = std::unique_ptr<SceneLoader>(new SceneLoaderSDLGame(m_pWindow, m_pSDLRenderer));
    m_sceneLoaders[SceneType::SDL_EXIT] = std::unique_ptr<SceneLoader>(new SceneLoaderSDLExit);
}

Scene *SceneManagerSDLSimple::getScene()
{
    return m_currentScene.get();
}

void SceneManagerSDLSimple::setScene(SceneDescriptor sceneDescriptor)
{
    switch (sceneDescriptor.sceneType)
    {
    case SceneType::SDL_GAME:
        loadGameScene(sceneDescriptor.sceneName);
        break;
    case SceneType::SDL_EXIT:
        m_currentScene.reset(nullptr);
        break;
    default:
        std::invalid_argument("SceneType switch not yet implemented.");
        break;
    }
}

void SceneManagerSDLSimple::loadGameScene(std::string_view sceneName)
{
    // TODO: This should be more sophisticated!
    if (m_currentScene)
        return;
    // SDL_Surface *pTempSurface = IMG_Load("assets/test_texture.png");
    // SDL_Surface *pTempSurface = IMG_Load("/bbalage/cpp/SDLDemo/assets/textures/test_pair.png"); // Debug purpose (tmp)
    SDL_Rect textureRect;
    SDL_QueryTexture(pTexture, NULL, NULL, &textureRect.w, &textureRect.h);
    Sprite sprite(pTexture, textureRect.w, textureRect.h);
    m_renderer.reset(new RendererSDLGame(m_pSDLRenderer));
    uint spriteId = m_renderer->addSprite(std::move(sprite));

    SceneSDLGame *scene = new SceneSDLGame(m_pWindow, *m_renderer);
    scene->addPlayer(std::unique_ptr<Player>(new Player(spriteId)));
    m_currentScene.reset(scene);
}