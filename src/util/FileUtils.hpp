#ifndef SDLDEMO_UTIL_FILEUTILS_H
#define SDLDEMO_UTIL_FILEUTILS_H

#include <string>
#include <fstream>
#include <sstream>
#include <filesystem>

namespace sdldemo
{
    constexpr char separator();
    std::string descriptorsDir();
    std::string texturesDir();
    std::string fileContentToString(std::string_view filepath);
}

#endif