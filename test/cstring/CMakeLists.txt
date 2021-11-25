cmake_minimum_required(VERSION 3.0.0)
project(cstring VERSION 0.1.0)

include(CTest)
enable_testing()
include_directories(./include/)
add_library(cstring SHARED ./src/cstring.c)
add_subdirectory(test)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)