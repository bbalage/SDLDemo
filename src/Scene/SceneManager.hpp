#ifndef SDLDEMO_SCENE_SCENEMANAGER_H
#define SDLDEMO_SCENE_SCENEMANAGER_H

#include <memory>
#include <vector>

#include "Scene.hpp"

class SceneManager
{
public:
    SceneManager() {}
    virtual ~SceneManager() = default;

    virtual Scene *getScene() = 0;
    virtual void setScene(SceneType sceneType) = 0;
};

class SceneManagerSDL : public SceneManager
{
public:
    SceneManagerSDL(SDL_Window *in_pWindow, SDL_Renderer *in_pRenderer) : m_pWindow(in_pWindow), m_pRenderer(in_pRenderer) {}
    virtual ~SceneManagerSDL() {}

protected:
    SDL_Window *m_pWindow;
    SDL_Renderer *m_pRenderer;
};

class SceneManagerSDLSimple : public SceneManagerSDL
{
public:
    SceneManagerSDLSimple(SDL_Window *in_pWindow, SDL_Renderer *in_pRenderer) : SceneManagerSDL(in_pWindow, in_pRenderer) {}
    ~SceneManagerSDLSimple(){};

    Scene *getScene() override;
    void setScene(SceneType sceneType) override;

private:
    std::unique_ptr<Scene> currentScene;
};

#endif