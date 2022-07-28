#ifndef SDLDEMO_SCENE_SCENELOADER_H
#define SDLDEMO_SCENE_SCENELOADER_H

#include <SDL2/SDL.h>
#include "Scene.hpp"

class SceneLoader
{
public:
    SceneLoader() {}

    virtual void loadScene(std::string_view sceneName) = 0;
};

class SceneLoaderGame : public SceneLoader
{
public:
    SceneLoaderGame() {}
    void loadScene(std::string_view sceneName) override;
};

class SceneLoaderExit : public SceneLoader
{
public:
    SceneLoaderExit() {}
    void loadScene(std::string_view sceneName) override;
};

#endif