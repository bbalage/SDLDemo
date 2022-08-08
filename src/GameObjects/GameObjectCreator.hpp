#ifndef SDLDEMO_GAMEOBJECTS_GAMEOBJECTCREATOR_H
#define SDLDEMO_GAMEOBJECTS_GAMEOBJECTCREATOR_H

#include <memory>
#include "GameObject.hpp"
#include "../Parser/parseUtils.hpp"

class GameObjectCreator
{
public:
    GameObjectCreator() {}
    virtual ~GameObjectCreator() {}
    GameObjectCreator(const GameObjectCreator &) = delete;
    GameObjectCreator &operator=(const GameObjectCreator &) = delete;

    virtual std::unique_ptr<GameObject> createGameObject(GameObjectDescriptor descriptor) = 0;
};

class GameObjectCreatorSDLGame : GameObjectCreator
{
public:
    GameObjectCreatorSDLGame() {}

    std::unique_ptr<GameObject> createGameObject(GameObjectDescriptor descriptor) override;
};

#endif