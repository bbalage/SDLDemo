#ifndef SDLDEMO_GAME_GAMEDATA_H
#define SDLDEMO_GAME_GAMEDATA_H

#include <unordered_map>
#include <string>
#include <string_view>
#include "../Parser/parseUtils.hpp"
#include "../util/FileUtils.hpp"

#define SPRITES_DESCRIPTOR_PATH std::string("assets/descriptors/sprites.xml")

class GameData
{
public:
    GameData(const GameData &) = delete;
    GameData &operator=(const GameData &) = delete;

    static GameData &instance();

    const std::unordered_map<std::string, SpriteDescriptor> &spriteDescriptors() const;
    const std::filesystem::path &fullPathToProject() const { return m_fullPathToProject; }

    std::filesystem::path descriptorsDir() { return m_descriptorsDir; }
    std::filesystem::path texturesDir() { return m_texturesDir; }

private:
    GameData();

    std::unordered_map<std::string, SpriteDescriptor> m_spriteDescriptors;
    std::filesystem::path m_fullPathToProject;
    std::filesystem::path m_descriptorsDir;
    std::filesystem::path m_texturesDir;

    std::string m_spriteTag{"<sprite>"};
    std::string m_nameTag{"<name>"};
    std::string m_fileTag{"<file>"};
    std::string m_widthTag{"<width>"};
    std::string m_heightTag{"<height>"};

    std::filesystem::path findFullPathToProject();
};

#endif