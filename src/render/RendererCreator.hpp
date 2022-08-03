#ifndef SDLDEMO_RENDER_RENDERERCREATOR_H
#define SDLDEMO_RENDER_RENDERERCREATOR_H

#include "Renderer.hpp"
#include "../Scene/sceneUtils.hpp"
#include <memory>

class RendererCreator
{
public:
    RendererCreator() {}
    virtual ~RendererCreator() {}
    RendererCreator(const RendererCreator &) = delete;
    RendererCreator &operator=(const RendererCreator &) = delete;

    virtual std::unique_ptr<Renderer> createRenderer(std::vector<Sprite> &&sprites, SceneType sceneType) = 0;
};

class RendererCreatorSDL : public RendererCreator
{
public:
    RendererCreatorSDL(SDL_Renderer *pSDLRenderer) : m_pSDLRenderer(pSDLRenderer) {}
    std::unique_ptr<Renderer> createRenderer(std::vector<Sprite> &&sprites, SceneType sceneType) override;

private:
    SDL_Renderer *m_pSDLRenderer;
};

#endif