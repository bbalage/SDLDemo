#include "SceneLoader.hpp"

std::unique_ptr<Scene> SceneLoaderSDLExit::loadScene(std::string_view)
{
    return std::unique_ptr<Scene>();
}