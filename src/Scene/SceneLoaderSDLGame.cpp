#include "SceneLoader.hpp"
#include "../GameObjects/Background.hpp"
#include "../GameObjects/Trap.hpp"
#include "../Game/GameData.hpp"

std::unique_ptr<Scene> SceneLoaderSDLGame::loadScene(std::string_view sceneName)
{
    std::string scenePath{(GameData::instance().descriptorsDir() / sceneName).string() + XML_POSTFIX};
    std::cout << "Path to scene descriptor: " << scenePath << std::endl;
    SceneDescriptor sceneDescriptor = m_parser.parseSceneDescriptor(scenePath);
    auto spriteNames = readRequiredSpriteNames(sceneDescriptor);
    std::unique_ptr<Renderer> renderer = m_rendererCreator.createRenderer(spriteNames, SceneType::SDL_GAME);
    auto player = loadPlayer(sceneDescriptor.playerDescriptor, renderer.get());
    const auto &gameObjectDescriptors = sceneDescriptor.gameObjectDescriptors;
    auto gameObjects = loadGameObjects(gameObjectDescriptors, renderer.get());
    std::unique_ptr<SceneSDLGame> scene{new SceneSDLGame(
        m_pWindow, std::move(renderer), std::move(player), std::move(gameObjects))};
    return scene;
}

std::unique_ptr<Player> SceneLoaderSDLGame::loadPlayer(const PlayerDescriptor &playerDescriptor, Renderer *renderer)
{
    Player *pPlayer = new Player(
        playerDescriptor.posX,
        playerDescriptor.posY,
        renderer->idForName(playerDescriptor.spriteName));
    return std::unique_ptr<Player>(pPlayer);
}

std::vector<std::unique_ptr<GameObject>> SceneLoaderSDLGame::loadGameObjects(
    const std::vector<GameObjectDescriptor> &gameObjectDescriptors,
    Renderer *renderer)
{
    std::vector<std::unique_ptr<GameObject>> gameObjects;
    gameObjects.reserve(gameObjectDescriptors.size());
    for (const GameObjectDescriptor &gameObjectDescriptor : gameObjectDescriptors)
    {
        // TODO: This switch statement should be part of the GameObjectCreator class.
        switch (gameObjectDescriptor.type)
        {
        case GameObjectType::TRAP:
            gameObjects.push_back(std::unique_ptr<GameObject>(
                new Trap(gameObjectDescriptor.posX, gameObjectDescriptor.posY, renderer->idForName(gameObjectDescriptor.spriteName))));
            break;
        case GameObjectType::BACKGROUND:
            gameObjects.push_back(std::unique_ptr<GameObject>(
                new Background(gameObjectDescriptor.posX, gameObjectDescriptor.posY, renderer->idForName(gameObjectDescriptor.spriteName))));
            break;
        }
    }
    return gameObjects;
}