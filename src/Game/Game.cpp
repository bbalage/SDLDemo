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
    SDL_Surface *pTempSurface = IMG_Load("assets/test_texture.png");
    if (pTempSurface == NULL)
    {
        std::runtime_error(std::string("Could not load image!"));
    }
    m_pTexture = SDL_CreateTextureFromSurface(m_pRenderer, pTempSurface);
    SDL_FreeSurface(pTempSurface);
    SDL_QueryTexture(m_pTexture, NULL, NULL, &m_sourceRectangle.w, &m_sourceRectangle.h);
    m_destinationRectangle.x = m_sourceRectangle.x = 0;
    m_destinationRectangle.y = m_sourceRectangle.y = 0;
    m_destinationRectangle.w = m_sourceRectangle.w;
    m_destinationRectangle.h = m_sourceRectangle.h;
    SDL_SetRenderDrawColor(m_pRenderer, 255, 255, 255, 255);
}

Game::~Game()
{
    SDL_DestroyRenderer(m_pRenderer);
    SDL_DestroyWindow(m_pWindow);
    SDL_Quit();
}

void Game::run()
{
    SDL_RenderClear(m_pRenderer);
    SDL_RenderCopy(m_pRenderer, m_pTexture, &m_sourceRectangle, &m_destinationRectangle);
    SDL_RenderPresent(m_pRenderer);
    SDL_Delay(5000);
}