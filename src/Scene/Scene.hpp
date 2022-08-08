#ifndef SDLDEMO_SCENE_SCENE_H
#define SDLDEMO_SCENE_SCENE_H

#include <SDL2/SDL.h>
#include <string>
#include <stdexcept>
#include <iostream>
#include <memory>
#include <utility>
#include "../render/Renderer.hpp"
#include "../GameObjects/GameObject.hpp"
#include "../GameObjects/Player.hpp"
#include "sceneUtils.hpp"

struct SceneSwitchDescriptor
{
    std::string sceneName;
    SceneType sceneType;
};

class Scene
{
public:
    Scene() = default;
    virtual ~Scene() = default;
    Scene(const Scene &) = delete;
    Scene &operator=(const Scene &) = delete;

    virtual void handleEvents() = 0;
    virtual void update() = 0;
    virtual void render() = 0;
    virtual bool exit() = 0;
    virtual SceneSwitchDescriptor nextSceneDescriptor() = 0;
};

class SceneSDL : public Scene
{
public:
    SceneSDL(SDL_Window *in_pWindow, std::unique_ptr<Renderer> in_pRenderer) : m_pWindow(in_pWindow),
                                                                               m_Renderer(std::move(in_pRenderer)) {}
    virtual ~SceneSDL() = default;

protected:
    SDL_Window *m_pWindow;
    std::unique_ptr<Renderer> m_Renderer;
};

class SceneSDLGame : public SceneSDL
{
public:
    SceneSDLGame(SDL_Window *in_pWindow,
                 std::unique_ptr<Renderer> in_pRenderer,
                 std::unique_ptr<Player> player,
                 std::vector<std::unique_ptr<GameObject>> gameObjects);

    void handleEvents() override;
    void update() override;
    void render() override;
    bool exit() override;
    SceneSwitchDescriptor nextSceneDescriptor() override;

private:
    bool m_exit;
    const Uint8 *m_keystates;
    Player *m_pPlayer;
    std::vector<std::unique_ptr<GameObject>> m_gameObjects;

    void handleKeyBoardState();
};

#endif