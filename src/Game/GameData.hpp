#ifndef SDLDEMO_GAME_GAMEDATA_H
#define SDLDEMO_GAME_GAMEDATA_H

#include <unordered_map>
#include <string>
#include <string_view>
#include "../Parser/parseUtils.hpp"

#define SPRITES_DESCRIPTOR_PATH "assets/descriptors/sprites.xml"

class GameData
{
public:
    GameData(const GameData &) = delete;
    GameData &operator=(const GameData &) = delete;

    static GameData &instance();

    const std::unordered_map<std::string, SpriteDescriptor> &spriteDescriptors() const;

private:
    GameData();

    std::unordered_map<std::string, SpriteDescriptor> m_spriteDescriptors;

    std::string m_spriteTag{"<sprite>"};
    std::string m_nameTag{"<name>"};
    std::string m_fileTag{"<file>"};
    std::string m_widthTag{"<width>"};
    std::string m_heightTag{"<height>"};
};

#endif