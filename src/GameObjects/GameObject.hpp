#ifndef SDLDEMO_GAMEOBJECTS_GAMEOBJECT_H
#define SDLDEMO_GAMEOBJECTS_GAMEOBJECT_H

#include "SDL2/SDL.h"

struct RenderInfo
{
    uint textureId;
    uint spriteRow;
    uint spriteCol;
};

class GameObject
{
public:
    GameObject(uint textureId) : m_textureId(textureId) {}
    virtual ~GameObject() {}

    virtual void update() = 0;
    virtual const RenderInfo &renderInfo() const = 0;

protected:
    uint m_textureId;
};

#endif