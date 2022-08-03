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

    virtual std::unordered_map<std::string, SpriteDescriptor> parseSpriteDescriptors(std::string_view path) const = 0;
    virtual SceneDescriptor parseSceneDescriptor(std::string_view path) const = 0;
};

class ParserXML : public Parser
{
public:
    ParserXML() {}

    std::unordered_map<std::string, SpriteDescriptor> parseSpriteDescriptors(std::string_view path) const override;
    SceneDescriptor parseSceneDescriptor(std::string_view path) const override;
};

#endif