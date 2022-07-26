#ifndef SDLDEMO_GAMEOBJECTS_PLAYER_H
#define SDLDEMO_GAMEOBJECTS_PLAYER_H

#include "GameObject.hpp"
#include "../util/Vector.hpp"

class Player : public GameObject
{
public:
    Player(uint spriteId) : GameObject(spriteId) {}

    void update() override;
    RenderInfo renderInfo() const override;

    // TODO: Remove:
    void move(Vec2 movement) { m_pos += movement; }

private:
    Vec2 m_pos;
};

#endif