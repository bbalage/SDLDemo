#ifndef SDLDEMO_GAME_GAME_H
#define SDLDEMO_GAME_GAME_H

#include <SDL2/SDL.h>

#include "../Scene/SceneManager.hpp"

#define SCREEN_WIDTH 1080
#define SCREEN_HEIGHT 768

class Game
{
public:
    Game();
    ~Game();

    void run();

private:
    // TODO: Make into unique pointer with custom deleter.
    SDL_Window *m_pWindow;
    SDL_Renderer *m_pRenderer;

    std::unique_ptr<SceneManager> m_pSceneManager;
    Scene *m_pScene;
};

#endif