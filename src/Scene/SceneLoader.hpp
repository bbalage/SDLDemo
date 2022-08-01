#ifndef SDLDEMO_SCENE_SCENELOADER_H
#define SDLDEMO_SCENE_SCENELOADER_H

#include <SDL2/SDL.h>
#include "Scene.hpp"
#include "../util/FileUtils.hpp"

class SceneLoader
{
public:
    SceneLoader() {}
    virtual ~SceneLoader() {}

    virtual std::unique_ptr<Scene> loadScene(std::string_view sceneName) = 0;
};

class SceneLoaderSDLGame : public SceneLoader
{
public:
    SceneLoaderSDLGame(SDL_Window *in_pWindow, SDL_Renderer *in_pRenderer) {}
    std::unique_ptr<Scene> loadScene(std::string_view sceneName) override;

private:
};

class SceneLoaderSDLExit : public SceneLoader
{
public:
    SceneLoaderSDLExit() {}
    std::unique_ptr<Scene> loadScene(std::string_view sceneName) override;

private:
};

#endif