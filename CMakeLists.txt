cmake_minimum_required(VERSION 3.16)

project(SDLDemo VERSION 1.0 LANGUAGES CXX)

find_package(SDL2 REQUIRED)
set(SDL2_INCLUDE_DIRS "/usr/local/include/SDL2")

include_directories(${SDL2_INCLUDE_DIRS})

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wpedantic -Wconversion -fsanitize=address,leak,undefined -m64") #-Wlifetime?
# set(CMAKE_CXX_FLAGS, "-f-sanitize=leak -m64 -O3")

enable_testing()

add_subdirectory(src)
add_subdirectory(test)