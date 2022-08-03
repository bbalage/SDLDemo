#ifndef SDLDEMO_SCENE_SCENELOADER_H
#define SDLDEMO_SCENE_SCENELOADER_H

#include <SDL2/SDL.h>
#include "Scene.hpp"
#include "../render/RendererCreator.hpp"
#include "../util/FileUtils.hpp"
#include "../Parser/Parser.hpp"

class SceneLoader
{
public:
    SceneLoader() {}
    virtual ~SceneLoader() {}

    /**
     * @brief Loads a scene from an XML file, and creates everything needed in the context of the Scene.
     *
     * @param sceneName
     * @return std::unique_ptr<Scene>
     */
    virtual std::unique_ptr<Scene> loadScene(std::string_view sceneName) = 0;
};

class SceneLoaderSDL
{
public:
    SceneLoaderSDL() {}
    virtual ~SceneLoaderSDL() {}

protected:
    Sprite readSprite(std::string_view spritePath, int frameWidth, int frameHeight);
};

class SceneLoaderSDLGame : public SceneLoader
{
public:
    SceneLoaderSDLGame(SDL_Window *in_pWindow, const RendererCreator &rendererCreator, const Parser &parser)
        : m_rendererCreator(rendererCreator),
          m_parser(parser) {}
    std::unique_ptr<Scene> loadScene(std::string_view sceneName) override;

private:
    SDL_Window *m_pWindow;
    const RendererCreator &m_rendererCreator;
    const Parser &m_parser;
};

class SceneLoaderSDLExit : public SceneLoader
{
public:
    SceneLoaderSDLExit() {}
    std::unique_ptr<Scene> loadScene(std::string_view sceneName) override;

private:
};

#endif