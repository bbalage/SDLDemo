#include "Scene.hpp"

SceneSDLGame::SceneSDLGame(SDL_Window *in_pWindow, SDL_Renderer *in_pRenderer) : SceneSDL(in_pWindow, in_pRenderer),
                                                                                 m_exit(false)
{
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
    m_keystates = SDL_GetKeyboardState(NULL);
}

void SceneSDLGame::handleEvents()
{
    SDL_Event event;
    if (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
        case SDL_QUIT:
            m_exit = true;
            break;
        default:
            break;
        }
    }
    handleKeyBoardState();
}

void SceneSDLGame::update()
{
}

void SceneSDLGame::render()
{
    SDL_RenderClear(m_pRenderer);
    SDL_RenderCopy(m_pRenderer, m_pTexture, &m_sourceRectangle, &m_destinationRectangle);
    SDL_RenderPresent(m_pRenderer);
    SDL_Delay(10);
}

bool SceneSDLGame::exit()
{
    return m_exit;
}

SceneType SceneSDLGame::nextSceneType()
{
    return SceneType::SDL_EXIT;
}

void SceneSDLGame::handleKeyBoardState()
{
    if (m_keystates[SDL_SCANCODE_ESCAPE])
    {
        m_exit = true;
    }
    else if (m_keystates[SDL_SCANCODE_A])
    {
        m_destinationRectangle.x--;
    }
    else if (m_keystates[SDL_SCANCODE_D])
    {
        m_destinationRectangle.x++;
    }
    else if (m_keystates[SDL_SCANCODE_W])
    {
        m_destinationRectangle.y--;
    }
    else if (m_keystates[SDL_SCANCODE_S])
    {
        m_destinationRectangle.y++;
    }
}