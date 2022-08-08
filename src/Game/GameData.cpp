#include "GameData.hpp"

#include "../util/FileUtils.hpp"

GameData &GameData::instance()
{
    static GameData gameData;
    return gameData;
}

GameData::GameData()
{
    m_fullPathToProject = findFullPathToProject();
    m_descriptorsDir = fullPathToProject() / std::string("assets") / std::string("descriptors");
    m_texturesDir = fullPathToProject() / std::string("assets") / std::string("textures");
    std::string fileContent = sdldemo::fileContentToString((m_fullPathToProject / SPRITES_DESCRIPTOR_PATH).string());
    size_t lastTag = 0;
    while (true)
    {
        size_t spriteTagI = fileContent.find(m_spriteTag, lastTag);
        if (spriteTagI == std::string::npos)
            break;
        std::string name = sdldemo::xmlTagContent(fileContent, m_nameTag, spriteTagI);
        std::string textureFilePath = sdldemo::xmlTagContent(fileContent, m_fileTag, spriteTagI);
        std::string width = sdldemo::xmlTagContent(fileContent, m_widthTag, spriteTagI);
        std::string height = sdldemo::xmlTagContent(fileContent, m_heightTag, spriteTagI);
        m_spriteDescriptors[name] = SpriteDescriptor{
            (texturesDir() / textureFilePath).string(),
            std::stoi(width),
            std::stoi(height)};
        lastTag = spriteTagI + m_spriteTag.length();
    }
}

const std::unordered_map<std::string, SpriteDescriptor> &GameData::spriteDescriptors() const
{
    return m_spriteDescriptors;
}

std::filesystem::path GameData::findFullPathToProject()
{
    std::string binaryFullPath = std::filesystem::current_path().string();
    std::string projectRootDirName("SDLDemo");
    size_t index = binaryFullPath.find(projectRootDirName);
    std::string projectFullPathString = binaryFullPath.substr(0, index + projectRootDirName.length() + 1);
    return std::filesystem::path(projectFullPathString);
}