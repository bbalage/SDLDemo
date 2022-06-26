enable_testing()

file(GLOB_RECURSE ALL_SOURCES LIST_DIRECTORIES true *.hpp *.h *.cpp)
set(LIB_SOURCES ${ALL_SOURCES})
list(FILTER LIB_SOURCES EXCLUDE REGEX ".*main.cpp$")
set(LIB_NAME ${CMAKE_PROJECT_NAME}_lib)

add_library(${LIB_NAME} STATIC ${LIB_SOURCES} )
target_link_libraries(${LIB_NAME}
${SDL2_LIBRARIES})

set(MAIN_EXECUTABLE_NAME ${CMAKE_PROJECT_NAME})
add_executable(${MAIN_EXECUTABLE_NAME} "main.cpp" ${SDL2_LIBRARY})
target_link_libraries(${MAIN_EXECUTABLE_NAME}
    ${LIB_NAME}
    ${SDL2_LIBRARIES})