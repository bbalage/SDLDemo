#ifndef SDLDEMO_RENDER_RENDERER_H
#define SDLDEMO_RENDER_RENDERER_H

#include "renderUtils.hpp"
#include "RenderCtx.hpp"

class Renderer
{
public:
    virtual ~Renderer() {}

    virtual void startRendering() = 0;
    virtual void render(const RenderInfo &renderInfo) = 0;
    virtual void finishRendering() = 0;
};

class RendererSDLGame : public Renderer
{
public:
    RendererSDLGame(SDL_Renderer *in_pRenderer) : m_pRenderer(in_pRenderer) {}
    RendererSDLGame(SDL_Renderer *in_pRenderer, RenderCtx ctx) : m_pRenderer(in_pRenderer), ctx(ctx) {}

    void startRendering() override;
    void render(const RenderInfo &renderInfo) override;
    void finishRendering() override;

private:
    SDL_Renderer *m_pRenderer;
    RenderCtx ctx;
};

#endif