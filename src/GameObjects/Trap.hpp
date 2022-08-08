#ifndef SDLDEMO_GAMEOBJECTS_TRAP_H
#define SDLDEMO_GAMEOBJECTS_TRAP_H

#include "GameObject.hpp"

class Trap : public GameObject
{
public:
    Trap(int posX, int posY, uint spriteId) : GameObject(posX, posY, spriteId) {}

    void update() override;
    RenderInfo renderInfo() const override;
};

#endif