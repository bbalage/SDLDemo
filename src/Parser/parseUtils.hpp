#ifndef SDLDEMO_PARSER_PARSEUTILS_H
#define SDLDEMO_PARSER_PARSEUTILS_H

#include <vector>
#include <string>

#include "../GameObjects/gameObjectUtils.hpp"

struct SpriteDescriptor
{
    std::string spritePath;
    int frameWidth;
    int frameHeight;
};

struct GameObjectDescriptor
{
    GameObjectType type;
    std::string spriteName;
    int posX;
    int posY;
};

struct PlayerDescriptor
{
    std::string spriteName;
    int posX;
    int posY;
};

struct SceneDescriptor
{
    PlayerDescriptor playerDescriptor;
    std::vector<GameObjectDescriptor> gameObjectDescriptors;
};
#endif