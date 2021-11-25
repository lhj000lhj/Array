cmake_minimum_required(VERSION 3.0.0)
project(ArrayTest VERSION 0.1.0)

include(CTest)
enable_testing()

set(CMAKE_BUILD_TYPE "Release")

add_executable(ArrayTest test.c ./cstring/src/cstring.c)
target_link_libraries(ArrayTest Array)
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)