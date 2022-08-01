#ifndef SDLDEMO_UTIL_FILEUTILS_H
#define SDLDEMO_UTIL_FILEUTILS_H

#include <string>
#include <fstream>
#include <sstream>
#include <filesystem>

namespace sdlutils
{
    constexpr char separator();
    std::string descriptorsDir();
    std::string texturesDir();
    std::string fileContentToString(std::string filepath);
}

#endif