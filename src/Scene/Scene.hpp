#ifndef SDLDEMO_SCENE_SCENE_H
#define SDLDEMO_SCENE_SCENE_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>
#include <stdexcept>
#include <iostream>
#include <memory>
#include <utility>
#include "../render/Renderer.hpp"
#include "../GameObjects/GameObject.hpp"
#include "../GameObjects/Player.hpp"

enum struct SceneType : unsigned int
{
    SDL_GAME,
    SDL_EXIT
};

struct SceneDescriptor
{
    std::string sceneName;
    SceneType sceneType;
};

class Scene
{
public:
    Scene() = default;
    virtual ~Scene() = default;

    virtual void handleEvents() = 0;
    virtual void update() = 0;
    virtual void render() = 0;
    virtual bool exit() = 0;
    virtual SceneType nextSceneType() = 0;
};

class SceneSDL : public Scene
{
public:
    SceneSDL(SDL_Window *in_pWindow, Renderer &in_Renderer) : m_pWindow(in_pWindow), m_Renderer(in_Renderer) {}
    virtual ~SceneSDL() = default;

protected:
    SDL_Window *m_pWindow;
    Renderer &m_Renderer;
};

class SceneSDLGame : public SceneSDL
{
public:
    SceneSDLGame(SDL_Window *in_pWindow, Renderer &in_Renderer);

    void handleEvents() override;
    void update() override;
    void render() override;
    bool exit() override;
    SceneType nextSceneType() override;

private:
    bool m_exit;
    const Uint8 *m_keystates;
    Player *player;
    std::vector<std::unique_ptr<GameObject>> m_gameObjects;

    void handleKeyBoardState();
};

#endif