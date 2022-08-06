#include "GameData.hpp"

#include "../util/FileUtils.hpp"

GameData &GameData::instance()
{
    static GameData gameData;
    return gameData;
}

GameData::GameData()
{
    std::string fileContent = sdldemo::fileContentToString(SPRITES_DESCRIPTOR_PATH);
    size_t lastTag = 0;
    while (true)
    {
        size_t spriteTagI = fileContent.find(m_spriteTag, lastTag);
        if (spriteTagI == std::string::npos)
            break;
        std::string name = sdldemo::xmlTagContent(fileContent, m_nameTag, spriteTagI);
        std::string textureFileName = sdldemo::xmlTagContent(fileContent, m_fileTag, spriteTagI);
        std::string width = sdldemo::xmlTagContent(fileContent, m_widthTag, spriteTagI);
        std::string height = sdldemo::xmlTagContent(fileContent, m_heightTag, spriteTagI);
        m_spriteDescriptors[name] = SpriteDescriptor{
            textureFileName,
            std::stoi(width),
            std::stoi(height)};
        lastTag = spriteTagI + m_spriteTag.length();
    }
}

const std::unordered_map<std::string, SpriteDescriptor> &GameData::spriteDescriptors() const
{
    return m_spriteDescriptors;
}