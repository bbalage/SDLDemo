#ifndef SDLDEMO_RENDER_RENDERER_H
#define SDLDEMO_RENDER_RENDERER_H

#include "Sprite.hpp"
#include <unordered_set>
#include <iostream>
#include <vector>
#include <map>

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
    virtual uint idForName(const std::string &spriteName) const = 0;
};

class RendererSDLGamePreloadSprites : public Renderer
{
public:
    RendererSDLGamePreloadSprites(SDL_Renderer *in_pRenderer, const std::unordered_set<std::string> &requiredSpriteNames);

    void startRendering() override;
    void render(const RenderInfo &renderInfo) override;
    void finishRendering() override;
    uint idForName(const std::string &spriteName) const override;

private:
    SDL_Renderer *m_pRenderer;
    std::map<std::string, uint> m_spriteNameMap;
    std::vector<Sprite> m_sprites;
};

#endif