#include "SceneLoader.hpp"

#include <unordered_set>
#include "../Game/GameData.hpp"

std::unordered_set<std::string> SceneLoaderSDL::readRequiredSpriteNames(const SceneDescriptor &sceneDescriptor)
{
    std::unordered_set<std::string> requiredSpriteNames;
    requiredSpriteNames.insert(sceneDescriptor.playerDescriptor.spriteName);
    for (GameObjectDescriptor gameObjectDescriptor : sceneDescriptor.gameObjectDescriptors)
    {
        requiredSpriteNames.insert(gameObjectDescriptor.spriteName);
    }
    return requiredSpriteNames;
}