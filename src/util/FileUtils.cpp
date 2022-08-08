#include "FileUtils.hpp"

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
    size_t foundIndex = xmlText.find(tag, searchStart);
    if (foundIndex == std::string::npos)
        std::invalid_argument("Tag not found: " + std::string(tag));
    size_t start = foundIndex + tag.length();
    std::string closingTag = std::string("</") + std::string(tag.substr(1));
    size_t end = xmlText.find(closingTag, start);
    return std::string(xmlText.substr(start, end - start));
}