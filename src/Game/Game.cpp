#include "Game.hpp"

Game::Game()
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        std::runtime_error(std::string("Could not initialize SDL2! ") + std::string(SDL_GetError()));
    }
    SDL_Window *pWindow = SDL_CreateWindow(
        "hello_sdl2",
        SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
        SCREEN_WIDTH, SCREEN_HEIGHT,
        SDL_WINDOW_FULLSCREEN_DESKTOP | SDL_WINDOW_SHOWN);
    if (pWindow == nullptr)
    {
        std::runtime_error(std::string("Could not create window! ") + std::string(SDL_GetError()));
    }
    m_pWindow = std::unique_ptr<SDL_Window, SDLWindowDeleter>(pWindow, SDLWindowDeleter{});
    pWindow = nullptr;
    SDL_Renderer *pRenderer = SDL_CreateRenderer(m_pWindow.get(), -1, 0);
    if (pRenderer == nullptr)
    {
        std::runtime_error(std::string("Could not create renderer! ") + std::string(SDL_GetError()));
    }
    m_pRenderer = std::unique_ptr<SDL_Renderer, SDLRendererDeleter>(pRenderer, SDLRendererDeleter{});
    pRenderer = nullptr;

    m_pSceneManager.reset(new SceneManagerSDLSimple(m_pWindow.get(), m_pRenderer.get()));
    m_pSceneManager->setScene(SceneDescriptor{"noname", SceneType::SDL_GAME});
    m_pScene = m_pSceneManager->getScene();
}

Game::~Game()
{
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
            m_pSceneManager->setScene(m_pScene->nextSceneDescriptor());
            m_pScene = m_pSceneManager->getScene();
        }
    }
}