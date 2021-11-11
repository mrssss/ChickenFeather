project(ChickenFeather)

# Global setup
cmake_minimum_required(VERSION 3.19)

set (CMAKE_CXX_STANDARD 17)

if(MSVC)
    add_compile_options(/W3 /WX)
else()
    set (CMAKE_LINKER  "/usr/bin/ld.lld")
    add_compile_options(-W -Wall -Werror -pthread)
endif()

add_subdirectory (app)
add_subdirectory (lib)
add_subdirectory (examples)
add_subdirectory (third_party)
add_subdirectory (tests)
add_subdirectory (benchmark)