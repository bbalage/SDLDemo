#include "SceneManager.hpp"

Scene *SceneManagerSDLSimple::getScene()
{
    return currentScene.get();
}

void SceneManagerSDLSimple::setScene(SceneDescriptor sceneDescriptor)
{
    switch (sceneDescriptor.sceneType)
    {
    case SceneType::SDL_GAME:
        loadGameScene(sceneDescriptor.sceneName);
        break;
    case SceneType::SDL_EXIT:
        currentScene.reset(nullptr);
        break;
    default:
        std::invalid_argument("SceneType switch not yet implemented.");
        break;
    }
}

void SceneManagerSDLSimple::loadGameScene(std::string_view sceneName)
{
    // TODO: This should be more sophisticated!
    if (currentScene)
        return;
    // SDL_Surface *pTempSurface = IMG_Load("assets/test_texture.png");
    SDL_Surface *pTempSurface = IMG_Load("/home/bbalage/cpp/SDLDemo/assets/textures/test_pair.png");
    if (pTempSurface == NULL)
    {
        std::runtime_error(std::string("Could not load image!"));
    }
    SDL_Texture *pTexture = SDL_CreateTextureFromSurface(m_pSDLRenderer, pTempSurface);
    SDL_FreeSurface(pTempSurface);
    SDL_Rect textureRect;
    SDL_QueryTexture(pTexture, NULL, NULL, &textureRect.w, &textureRect.h);
    Sprite sprite(pTexture, textureRect.w, textureRect.h);
    m_renderer.reset(new RendererSDLGame(m_pSDLRenderer));
    uint spriteId = m_renderer->addSprite(std::move(sprite));

    SceneSDLGame *scene = new SceneSDLGame(m_pWindow, *m_renderer);
    scene->addGameObject(std::unique_ptr<GameObject>(new Player(spriteId)));
    currentScene.reset(scene);
}