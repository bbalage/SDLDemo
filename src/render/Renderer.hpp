#ifndef SDLDEMO_RENDER_RENDERER_H
#define SDLDEMO_RENDER_RENDERER_H

#include "Sprite.hpp"
#include <iostream>
#include <vector>

class Renderer
{
public:
    virtual ~Renderer() {}

    virtual void startRendering() = 0;
    virtual void render(const RenderInfo &renderInfo) = 0;
    virtual void finishRendering() = 0;
    virtual uint addSprite(Sprite &&sprite) = 0;
};

class RendererSDLGame : public Renderer
{
public:
    RendererSDLGame(SDL_Renderer *in_pRenderer);

    void startRendering() override;
    void render(const RenderInfo &renderInfo) override;
    void finishRendering() override;

    /**
     * @brief Adds sprite to context and returns the id of the sprite.
     *
     * @param sprite
     * @return uint
     */
    uint addSprite(Sprite &&sprite) override;

private:
    SDL_Renderer *m_pRenderer;
    std::vector<Sprite> sprites;
};

#endif