#include "Scene.hpp"

SceneSDLGame::SceneSDLGame(SDL_Window *in_pWindow,
                           std::unique_ptr<Renderer> in_pRenderer,
                           std::unique_ptr<Player> player,
                           std::vector<std::unique_ptr<GameObject>> gameObjects) : SceneSDL(in_pWindow, std::move(in_pRenderer)),
                                                                                   m_pPlayer(player.get()),
                                                                                   m_exit(false)
{
    for (auto &gameObject : gameObjects)
    {
        m_gameObjects.push_back(std::move(gameObject));
    }
    m_gameObjects.push_back(std::move(player));
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
    m_Renderer->startRendering();
    for (std::unique_ptr<GameObject> &gameObject : m_gameObjects)
    {
        m_Renderer->render(gameObject->renderInfo());
    }
    m_Renderer->finishRendering();
}

bool SceneSDLGame::exit()
{
    return m_exit;
}

SceneSwitchDescriptor SceneSDLGame::nextSceneDescriptor()
{
    return SceneSwitchDescriptor{std::string("noname"), SceneType::SDL_EXIT};
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