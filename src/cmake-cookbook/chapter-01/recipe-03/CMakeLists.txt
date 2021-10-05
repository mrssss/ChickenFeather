project(recipe-03)

add_library(message
    STATIC
        Message.hpp
        Message.cpp
)

add_library(message-objs
    OBJECT
        Message.hpp
        Message.cpp
)

set_target_properties(message-objs
    PROPERTIES
        POSITION_INDEPENDENT_CODE 1
)


add_library(message-shared
    SHARED
        $<TARGET_OBJECTS:message-objs>
)

add_library(message-static
    STATIC
        $<TARGET_OBJECTS:message-objs>
)

add_executable(cmake-recipe-03 hello-world.cpp)

target_link_libraries(cmake-recipe-03 message-shared)

