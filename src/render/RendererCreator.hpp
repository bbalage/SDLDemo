#ifndef SDLDEMO_RENDER_RENDERERCREATOR_H
#define SDLDEMO_RENDER_RENDERERCREATOR_H

#include "Renderer.hpp"
#include <memory>

class RendererCreator
{
public:
    RendererCreator() {}

    std::unique_ptr<Renderer> createRenderer();
};

#endif