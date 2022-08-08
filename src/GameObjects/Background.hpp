#ifndef SDLDEMO_GAMEOBJECTS_BACKGROUND_H
#define SDLDEMO_GAMEOBJECTS_BACKGROUND_H

#include "GameObject.hpp"

class Background : public GameObject
{
public:
    Background(int posX, int posY, uint spriteId) : GameObject(posX, posY, spriteId) {}

    void update() override;
    RenderInfo renderInfo() const override;
};

#endif