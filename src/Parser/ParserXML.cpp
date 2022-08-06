#include "Parser.hpp"

#include "../util/FileUtils.hpp"

SceneDescriptor ParserXML::parseSceneDescriptor(std::string_view path) const
{
    std::string fileContent = sdldemo::fileContentToString(path);
    PlayerDescriptor playerDescriptor = parsePlayerDescriptor(fileContent);
    std::vector<GameObjectDescriptor> gameObjectDescriptors = parseGameObjectDescriptors(fileContent);
    return SceneDescriptor{playerDescriptor, gameObjectDescriptors};
}

PlayerDescriptor ParserXML::parsePlayerDescriptor(std::string_view xmlContent) const
{
    size_t playerTagI = xmlContent.find(m_playerTag, 0);
    std::string sprite = sdldemo::xmlTagContent(xmlContent, m_spriteTag, playerTagI);
    std::string xPos = sdldemo::xmlTagContent(xmlContent, m_posXTag, playerTagI);
    std::string yPos = sdldemo::xmlTagContent(xmlContent, m_posYTag, playerTagI);
    return PlayerDescriptor{sprite, std::stoi(xPos), std::stoi(yPos)};
}

std::vector<GameObjectDescriptor> ParserXML::parseGameObjectDescriptors(std::string_view xmlContent) const
{
    size_t lastTag = 0;
    std::vector<GameObjectDescriptor> descriptors;
    while (true)
    {
        size_t gameObjectTagI = xmlContent.find(m_gameObjectTag, lastTag);
        if (gameObjectTagI == std::string::npos)
            break;
        std::string type = sdldemo::xmlTagContent(xmlContent, m_gameObjectTypeTag, gameObjectTagI);
        std::string sprite = sdldemo::xmlTagContent(xmlContent, m_spriteTag, gameObjectTagI);
        std::string xPos = sdldemo::xmlTagContent(xmlContent, m_posXTag, gameObjectTagI);
        std::string yPos = sdldemo::xmlTagContent(xmlContent, m_posYTag, gameObjectTagI);
        GameObjectType gameObjectType = m_textToGameObjectTypeMapping.at(type);
        descriptors.push_back(GameObjectDescriptor{
            gameObjectType,
            sprite,
            std::stoi(xPos),
            std::stoi(yPos)});
        lastTag = gameObjectTagI + m_gameObjectTag.length();
    }
    return descriptors;
}