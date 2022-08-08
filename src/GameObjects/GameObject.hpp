#ifndef SDLDEMO_GAMEOBJECTS_GAMEOBJECT_H
#define SDLDEMO_GAMEOBJECTS_GAMEOBJECT_H

#include "SDL2/SDL.h"
#include "../render/renderUtils.hpp"

class GameObject
{
public:
    GameObject(int posX, int posY, uint spriteId) : m_pos(Vec2{posX, posY}), m_spriteId(spriteId) {}
    virtual ~GameObject() {}

    virtual void update() = 0;
    virtual RenderInfo renderInfo() const = 0;

protected:
    Vec2 m_pos;
    uint m_spriteId;
};

#endif