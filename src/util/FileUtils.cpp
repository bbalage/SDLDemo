#include "FileUtils.hpp"

constexpr char sdlutils::separator()
{
    return std::filesystem::path::preferred_separator;
}

std::string sdlutils::descriptorsDir()
{
    return std::string("assets") + sdlutils::separator() + std::string("descriptors");
}

std::string sdlutils::texturesDir()
{
    return std::string("assets") + sdlutils::separator() + std::string("textures");
}

std::string sdlutils::fileContentToString(std::string filepath)
{
    std::ifstream infstream(filepath);
    std::stringstream buffer;
    buffer << infstream.rdbuf();
    std::string output(buffer.str());
    infstream.close();
    return output;
}