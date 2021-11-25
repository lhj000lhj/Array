cmake_minimum_required(VERSION 3.0.0)
project(CStringBase VERSION 0.1.0)
project(CStringSearch VERSION 0.1.0)
project(CStringProcess VERSION 0.1.0)
include(CTest)
enable_testing()
include_directories(../include/)

add_executable(CStringBase CStringBase.c)
target_link_libraries(CStringBase cstring)
add_executable(CStringSearch CStringSearch.c)
target_link_libraries(CStringSearch cstring)
add_executable(CStringProcess CStringProcess.c)
target_link_libraries(CStringProcess cstring)



set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)