find_package(GTest REQUIRED)

file(GLOB_RECURSE TEST_SOURCES LIST_DIRECTORIES true *.hpp *.cpp)

add_executable(
  ${CMAKE_PROJECT_NAME}_test
  ${TEST_SOURCES}
)

target_link_libraries(
  ${CMAKE_PROJECT_NAME}_test
  PRIVATE ${CMAKE_PROJECT_NAME}_lib
  GTest::GTest GTest::Main
  ${OpenCV_LIBS}
)

include(GoogleTest)
gtest_discover_tests(${CMAKE_PROJECT_NAME}_test)
