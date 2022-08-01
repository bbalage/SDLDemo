#ifndef SDLDEMO_SCENE_SCENEMANAGER_H
#define SDLDEMO_SCENE_SCENEMANAGER_H

#include <memory>
#include <vector>
#include <string_view>
#include <unordered_map>
#include "Scene.hpp"
#include "SceneLoader.hpp"

class SceneManager
{
public:
    SceneManager() {}
    virtual ~SceneManager() = default;

    virtual Scene *getScene() = 0;
    virtual void setScene(SceneDescriptor sceneDescriptor) = 0;
};

class SceneManagerSDL : public SceneManager
{
public:
    SceneManagerSDL(SDL_Window *in_pWindow, SDL_Renderer *in_pRenderer) : m_pWindow(in_pWindow), m_pSDLRenderer(in_pRenderer) {}
    virtual ~SceneManagerSDL() {}

protected:
    SDL_Window *m_pWindow;
    SDL_Renderer *m_pSDLRenderer;
};

class SceneManagerSDLSimple : public SceneManagerSDL
{
public:
    SceneManagerSDLSimple(SDL_Window *in_pWindow, SDL_Renderer *in_pRenderer);
    ~SceneManagerSDLSimple(){};

    Scene *getScene() override;
    void setScene(SceneDescriptor sceneDescriptor) override;

private:
    std::unique_ptr<Renderer> m_renderer;
    std::unique_ptr<Scene> m_currentScene;
    std::unordered_map<SceneType, std::unique_ptr<SceneLoader>> m_sceneLoaders;

    void loadGameScene(std::string_view sceneName);
};

#endif