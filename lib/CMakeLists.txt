project (lib)

# Define library
# add_library(add OBJECT)

# target_sources(add
#     PRIVATE cal/add/add.cpp
#     PUBLIC cal/add/add.h
# )
# target_include_directories(add SYSTEM PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_library(_basic INTERFACE)
target_include_directories(_basic INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})

add_library (basic::max ALIAS _basic)
add_library (basic::smart_pointer ALIAS _basic)
add_library (basic::sort ALIAS _basic)
