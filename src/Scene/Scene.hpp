#ifndef SDLDEMO_SCENE_SCENE_H
#define SDLDEMO_SCENE_SCENE_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>
#include <stdexcept>
#include <iostream>

enum struct SceneType : unsigned int
{
    SDL_GAME,
    SDL_EXIT
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
    SceneSDL(SDL_Window *in_pWindow, SDL_Renderer *in_pRenderer) : m_pWindow(in_pWindow), m_pRenderer(in_pRenderer) {}
    virtual ~SceneSDL() = default;

protected:
    SDL_Window *m_pWindow;
    SDL_Renderer *m_pRenderer;
};

class SceneSDLGame : public SceneSDL
{
public:
    SceneSDLGame(SDL_Window *in_pWindow, SDL_Renderer *in_pRenderer);

    void handleEvents() override;
    void update() override;
    void render() override;
    bool exit() override;
    SceneType nextSceneType() override;

private:
    bool m_exit;

    SDL_Texture *m_pTexture;
    SDL_Rect m_sourceRectangle;
    SDL_Rect m_destinationRectangle;
};

#endif