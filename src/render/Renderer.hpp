#ifndef SDLDEMO_RENDER_RENDERER_H
#define SDLDEMO_RENDER_RENDERER_H

#include "Sprite.hpp"
#include <iostream>
#include <vector>

class Renderer
{
public:
    Renderer() {}
    virtual ~Renderer() {}
    Renderer(const Renderer &) = delete;
    Renderer &operator=(const Renderer &) = delete;

    virtual void startRendering() = 0;
    virtual void render(const RenderInfo &renderInfo) = 0;
    virtual void finishRendering() = 0;
};

class RendererSDLGame : public Renderer
{
public:
    RendererSDLGame(SDL_Renderer *in_pRenderer, std::vector<Sprite> &&sprites);

    void startRendering() override;
    void render(const RenderInfo &renderInfo) override;
    void finishRendering() override;

private:
    SDL_Renderer *m_pRenderer;
    std::vector<Sprite> m_sprites;
};

#endif