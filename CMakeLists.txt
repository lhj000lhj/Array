cmake_minimum_required(VERSION 3.0.0)
project(Array VERSION 0.1.0)

include(CTest)
enable_testing()

set(CMAKE_BUILD_TYPE "Release")
add_definitions(-DICEAPI_EXPORTS)
add_library(Array SHARED ./src/Array_private.c ./src/Array.c)
add_subdirectory(./test)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
