cmake_minimum_required(VERSION 3.10)

project("ChickenFeather")

SET (CMAKE_LINKER  "/usr/bin/ld.lld")
SET (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")

message(STATUS "CMAKE_SOURCE_DIR: ${CMAKE_SOURCE_DIR}")

include(third_party/CMakeLists.txt)

add_subdirectory(src)

macro (print_all_vars)
    message(STATUS "==========print all variables==========")
    get_cmake_property(_variableNames VARIABLES)

    foreach (_variableName ${_variableNames})
        message(STATUS "${_variableName}=${${_variableName}}")
    endforeach()
    message(STATUS "==========print all variables==========")
endmacro()

#print_all_vars()

# Add unit test
macro (grep_gtest_sources BASE_DIR DST_VAR)
    message(STATUS "grep_gtest_sources(${BASE_DIR} ${DST_VAR})")
    file (GLOB_RECURSE "${DST_VAR}" RELATIVE "${BASE_DIR}" "gtest*.cpp")
endmacro()

grep_gtest_sources("${CMAKE_SOURCE_DIR}" unit_test_sources)

if (unit_test_sources)
    message(STATUS "Found unit test")
    add_executable(unit_tests ${unit_test_sources})
    target_link_libraries( unit_tests gtest gtest_main)
    add_test( unit_tests unit_tests )
else()
    message(STATUS "Not found unit test")
endif()