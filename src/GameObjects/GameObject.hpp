#ifndef SDLDEMO_GAMEOBJECTS_GAMEOBJECT_H
#define SDLDEMO_GAMEOBJECTS_GAMEOBJECT_H

#include "SDL2/SDL.h"
#include "../render/renderUtils.hpp"

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