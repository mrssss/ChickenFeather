cmake_minimum_required(VERSION 3.10)

project("ChickenFeather")

SET (CMAKE_LINKER  "/usr/bin/ld.lld")
SET (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")

message(STATUS "CMAKE_SOURCE_DIR: ${CMAKE_SOURCE_DIR}")

include (third_party/CMakeLists.txt)

include_directories (src)

add_subdirectory (src)

add_executable (server bin/server/main.cpp)
target_link_libraries (server libserver)
