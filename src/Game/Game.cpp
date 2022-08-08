#include "Game.hpp"
#include "../Scene/SceneLoader.hpp"

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
    m_pSDLRenderer = std::unique_ptr<SDL_Renderer, SDLRendererDeleter>(pRenderer, SDLRendererDeleter{});
    pRenderer = nullptr;
    m_pRendererCreator.reset(new RendererCreatorSDL(m_pSDLRenderer.get()));
    m_pParser.reset(new ParserXML);

    m_sceneLoaders[SceneType::SDL_GAME] = std::unique_ptr<SceneLoader>(new SceneLoaderSDLGame(m_pWindow.get(), *m_pRendererCreator, *m_pParser));
    m_sceneLoaders[SceneType::SDL_EXIT] = std::unique_ptr<SceneLoader>(new SceneLoaderSDLExit);

    setScene(SceneSwitchDescriptor{"demo_scene", SceneType::SDL_GAME});
}

Game::~Game()
{
    SDL_Quit();
}

void Game::run()
{
    while (m_pScene)
    {
        m_pScene->handleEvents();
        m_pScene->update();
        m_pScene->render();
        if (m_pScene->exit())
        {
            setScene(m_pScene->nextSceneDescriptor());
        }
    }
}

void Game::setScene(SceneSwitchDescriptor sceneDescriptor)
{
    m_pScene = m_sceneLoaders[sceneDescriptor.sceneType]->loadScene(sceneDescriptor.sceneName);
}