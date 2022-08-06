#include "FileUtils.hpp"

constexpr char sdldemo::separator()
{
    return std::filesystem::path::preferred_separator;
}

std::string sdldemo::descriptorsDir()
{
    return std::string("assets") + sdldemo::separator() + std::string("descriptors");
}

std::string sdldemo::texturesDir()
{
    return std::string("assets") + sdldemo::separator() + std::string("textures");
}

std::string sdldemo::fileContentToString(std::string_view filepath)
{
    std::string strPath(filepath);
    std::ifstream infstream(strPath);
    std::stringstream buffer;
    buffer << infstream.rdbuf();
    std::string output(buffer.str());
    infstream.close();
    return output;
}

std::string sdldemo::xmlTagContent(std::string_view xmlText, std::string_view tag, size_t searchStart)
{
    size_t start = xmlText.find(tag, searchStart) + tag.length();
    std::string closingTag = std::string("</") + std::string(tag.substr(1));
    size_t end = xmlText.find(closingTag, start) + tag.length();
    return std::string(xmlText.substr(start, end - start));
}