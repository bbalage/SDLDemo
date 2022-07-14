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
        SDL_WINDOW_SHOWN);
    if (m_pWindow == NULL)
    {
        std::runtime_error(std::string("Could not create window! ") + std::string(SDL_GetError()));
    }

    m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);
    if (m_pRenderer == NULL)
    {
        std::runtime_error(std::string("Could not create renderer! ") + std::string(SDL_GetError()));
    }
    // TODO: SDL_Surface *pTempSurface = IMG_Load("assets/animate.png");
}

Game::~Game()
{
    SDL_DestroyRenderer(m_pRenderer);
    SDL_DestroyWindow(m_pWindow);
    SDL_Quit();
}

void Game::run()
{
    auto screenSurface = SDL_GetWindowSurface(m_pWindow);
    SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0xFF, 0xFF, 0xFF));
    SDL_UpdateWindowSurface(m_pWindow);
    SDL_Delay(2000);
}