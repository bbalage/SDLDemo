#include "Game.hpp"
#include "../Scene/SceneLoader.hpp"
#include <chrono>

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
    Uint32 delay = 1U;
    while (m_pScene)
    {
        auto startTime = std::chrono::high_resolution_clock::now();
        m_pScene->handleEvents();
        m_pScene->update();
        m_pScene->render();
        if (m_pScene->exit())
        {
            setScene(m_pScene->nextSceneDescriptor());
        }
        // Set fix FPS
        auto timePassed = std::chrono::high_resolution_clock::now() - startTime;
        auto timeForTurn = sdldemo::timeForTurn();
        auto nanosecondsPassed = std::chrono::duration_cast<std::chrono::nanoseconds>(timePassed).count();
        delay = timeForTurn < nanosecondsPassed ? 0 : (timeForTurn - nanosecondsPassed) / 1000000; // TODO: Get rid of conversion warning!
        SDL_Delay(delay);
        // Calculate FPS
        auto totalTimePassed = std::chrono::high_resolution_clock::now() - startTime;
        auto totalNanosecondsPassed = std::chrono::duration_cast<std::chrono::nanoseconds>(totalTimePassed).count();
        double fps = 1.0e9 / static_cast<double>(totalNanosecondsPassed);
        std::cout << "FPS: " << fps << "\n";
    }
}

void Game::setScene(SceneSwitchDescriptor sceneDescriptor)
{
    m_pScene = m_sceneLoaders[sceneDescriptor.sceneType]->loadScene(sceneDescriptor.sceneName);
}

constexpr long sdldemo::timeForTurn()
{
    return 1e9 / DESIRED_FPS; // TODO: Get rid of conversion warning!
}