#include "SceneLoader.hpp"

#include <unordered_set>
#include "../Game/GameData.hpp"

std::vector<Sprite> SceneLoaderSDL::readRequiredSprites(const SceneDescriptor &sceneDescriptor)
{
    std::unordered_set<std::string> requiredSprites;
    requiredSprites.insert(sceneDescriptor.playerDescriptor.spriteName);
    for (GameObjectDescriptor gameObjectDescriptor : sceneDescriptor.gameObjectDescriptors)
    {
        requiredSprites.insert(gameObjectDescriptor.spriteName);
    }
    std::vector<Sprite> sprites;
    for (std::string &spriteName : requiredSprites)
    {
        const SpriteDescriptor &spriteDescriptor = GameData::instance().spriteDescriptors().at(spriteName);
        Sprite sprite{
            sdldemo::loadTexture(spriteDescriptor.spritePath),
            spriteDescriptor.frameWidth,
            spriteDescriptor.frameHeight};
        sprites.push_back(std::move(sprite));
    }
    return sprites;
}