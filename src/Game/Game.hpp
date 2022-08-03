#ifndef SDLDEMO_GAME_GAME_H
#define SDLDEMO_GAME_GAME_H

#include <SDL2/SDL.h>

#include "../Scene/SceneManager.hpp"
#include "../util/SDLUtils.hpp"

#define SCREEN_WIDTH 1080
#define SCREEN_HEIGHT 768

class Game
{
public:
    Game();
    ~Game();

    void run();

private:
    std::unique_ptr<SDL_Window, SDLWindowDeleter> m_pWindow;
    std::unique_ptr<SDL_Renderer, SDLRendererDeleter> m_pSDLRenderer;
    std::unique_ptr<RendererCreator> m_pRendererCreator;
    std::unique_ptr<Parser> m_pParser;
    std::unique_ptr<Scene> m_pScene;
    std::unordered_map<SceneType, std::unique_ptr<SceneLoader>> m_sceneLoaders;

    void setScene(SceneSwitchDescriptor sceneDescriptor);
};

#endif