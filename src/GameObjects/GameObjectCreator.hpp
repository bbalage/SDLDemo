#ifndef SDLDEMO_GAMEOBJECTS_GAMEOBJECTCREATOR_H
#define SDLDEMO_GAMEOBJECTS_GAMEOBJECTCREATOR_H

#include <memory>
#include "GameObject.hpp"
#include "../Parser/parseUtils.hpp"

class GameObjectMaker
{
public:
    GameObjectMaker() {}
    virtual ~GameObjectMaker() {}
    GameObjectMaker(const GameObjectMaker &) = delete;
    GameObjectMaker &operator=(const GameObjectMaker &) = delete;

    virtual std::unique_ptr<GameObject> createGameObject(GameObjectDescriptor descriptor) = 0;
};

class GameObjectMakerSDLGame : GameObjectMaker
{
public:
    GameObjectMakerSDLGame() {}

    std::unique_ptr<GameObject> createGameObject(GameObjectDescriptor descriptor) override;
};

#endif