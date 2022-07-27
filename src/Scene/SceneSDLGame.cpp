#include "Scene.hpp"

SceneSDLGame::SceneSDLGame(SDL_Window *in_pWindow, Renderer &in_pRenderer) : SceneSDL(in_pWindow, in_pRenderer),
                                                                             m_exit(false)
{
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
    m_Renderer.startRendering();
    for (std::unique_ptr<GameObject> &gameObject : m_gameObjects)
    {
        m_Renderer.render(gameObject->renderInfo());
    }
    m_Renderer.finishRendering();
    SDL_Delay(10);
}

bool SceneSDLGame::exit()
{
    return m_exit;
}

SceneDescriptor SceneSDLGame::nextSceneDescriptor()
{
    return SceneDescriptor{std::string("noname"), SceneType::SDL_EXIT};
}

void SceneSDLGame::handleKeyBoardState()
{
    if (m_keystates[SDL_SCANCODE_ESCAPE])
    {
        m_exit = true;
    }
    else if (m_keystates[SDL_SCANCODE_A])
    {
        m_pPlayer->move(Vec2{-1, 0});
    }
    else if (m_keystates[SDL_SCANCODE_D])
    {
        m_pPlayer->move(Vec2{1, 0});
    }
    else if (m_keystates[SDL_SCANCODE_W])
    {
        m_pPlayer->move(Vec2{0, -1});
    }
    else if (m_keystates[SDL_SCANCODE_S])
    {
        m_pPlayer->move(Vec2{0, 1});
    }
}