#ifndef SDLDEMO_PARSER_PARSER_H
#define SDLDEMO_PARSER_PARSER_H

#include <unordered_map>
#include <string>
#include <string_view>
#include "parseUtils.hpp"

class Parser
{
public:
    Parser() {}
    virtual ~Parser() {}
    Parser(const Parser &) = delete;
    Parser &operator=(const Parser &) = delete;
    Parser(Parser &&) = default;
    Parser &operator=(Parser &&) = default;

    virtual SceneDescriptor parseSceneDescriptor(std::string_view path) const = 0;
};

class ParserXML : public Parser
{
public:
    ParserXML() {}

    SceneDescriptor parseSceneDescriptor(std::string_view path) const override;

private:
    std::string m_playerTag{"<player>"};
    std::string m_gameObjectTag{"<gameObject>"};
    std::string m_gameObjectTypeTag{"<type>"};
    std::string m_spriteTag{"<sprite>"};
    std::string m_posXTag{"<x>"};
    std::string m_posYTag{"<y>"};
    std::unordered_map<std::string, GameObjectType> m_textToGameObjectTypeMapping{};

    PlayerDescriptor parsePlayerDescriptor(std::string_view xmlContent) const;
    std::vector<GameObjectDescriptor> parseGameObjectDescriptors(std::string_view xmlContent) const;
};

#endif