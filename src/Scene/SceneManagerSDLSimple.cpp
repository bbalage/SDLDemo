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
    m_renderer.reset(new RendererSDLGame(m_pSDLRenderer));
    RenderCtx renderCtx;
    SDL_Surface *pTempSurface = IMG_Load("assets/test_texture.png");
    if (pTempSurface == NULL)
    {
        std::runtime_error(std::string("Could not load image!"));
    }
    SDL_Texture *pTexture = SDL_CreateTextureFromSurface(m_pSDLRenderer, pTempSurface);
    SDL_FreeSurface(pTempSurface);
    SDL_Rect textureRect;
    SDL_QueryTexture(pTexture, NULL, NULL, &textureRect.w, &textureRect.h);
    Sprite sprite(pTexture, textureRect.w, textureRect.h);
    renderCtx.addSprite(std::move(sprite));
    // TODO: Add contect to renderer!
    SDL_SetRenderDrawColor(m_pRenderer, 255, 255, 255, 255);
    renderCtx.addSprite(Sprite())
        Scene *scene = new SceneSDLGame(m_pWindow);
    currentScene.reset();
}