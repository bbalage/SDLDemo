#include "Parser.hpp"

#include "../util/FileUtils.hpp"

std::unordered_map<std::string, SpriteDescriptor> ParserXML::parseSpriteDescriptors(std::string_view path) const
{
}

SceneDescriptor ParserXML::parseSceneDescriptor(std::string_view path) const
{
    std::string fileContent = sdldemo::fileContentToString(path);
}
