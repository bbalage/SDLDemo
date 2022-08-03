#ifndef SDLDEMO_PARSER_PARSEUTILS_H
#define SDLDEMO_PARSER_PARSEUTILS_H

#include <vector>
#include <string>

struct SpriteDescriptor
{
    std::string spritePath;
    int frameWidth;
    int frameHeight;
};

struct GameObjectDescriptor
{

    std::string spriteName;
    int posX;
    int posY;
};

struct SceneDescriptor
{
    std::vector<GameObjectDescriptor> gameObjectDescriptors;
};

#endif