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

std::string sdldemo::fileContentToString(std::string filepath)
{
    std::ifstream infstream(filepath);
    std::stringstream buffer;
    buffer << infstream.rdbuf();
    std::string output(buffer.str());
    infstream.close();
    return output;
}