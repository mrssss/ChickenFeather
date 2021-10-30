project (lib)

# Define library
add_library(add OBJECT)

target_sources(add
    PRIVATE cal/add/add.cpp
    PUBLIC cal/add/add.h
)
target_include_directories(add SYSTEM PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})