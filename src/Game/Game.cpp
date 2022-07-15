#include "Game.hpp"

Game::Game()
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        std::runtime_error(std::string("Could not initialize SDL2! ") + std::string(SDL_GetError()));
    }
    m_pWindow = SDL_CreateWindow(
        "hello_sdl2",
        SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
        SCREEN_WIDTH, SCREEN_HEIGHT,
        SDL_WINDOW_FULLSCREEN_DESKTOP | SDL_WINDOW_SHOWN);
    if (m_pWindow == NULL)
    {
        std::runtime_error(std::string("Could not create window! ") + std::string(SDL_GetError()));
    }

    m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);
    if (m_pRenderer == NULL)
    {
        std::runtime_error(std::string("Could not create renderer! ") + std::string(SDL_GetError()));
    }

    m_pSceneManager.reset(new SceneManagerSDLSimple(m_pWindow, m_pRenderer));
    m_pSceneManager->setScene(SceneType::SDL_GAME);
    m_pScene = m_pSceneManager->getScene();
}

Game::~Game()
{
    SDL_DestroyRenderer(m_pRenderer);
    SDL_DestroyWindow(m_pWindow);
    SDL_Quit();
}

void Game::run()
{
    while (m_pScene != nullptr)
    {
        m_pScene->handleEvents();
        m_pScene->update();
        m_pScene->render();
        if (m_pScene->exit())
        {
            m_pSceneManager->setScene(m_pScene->nextSceneType());
            m_pScene = m_pSceneManager->getScene();
        }
    }
}