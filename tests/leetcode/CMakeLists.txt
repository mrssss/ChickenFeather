project(leetcode)

# This is a workaround for the requirements of add_executable command
file(WRITE null.cpp "")

add_executable (leetcode
    null.cpp
)
target_sources (leetcode
    PRIVATE
        1.two_sum.cpp
        135.candy.cpp
        455.findContentChildren.cpp
)
target_link_libraries (leetcode
    PRIVATE
        GTest::gtest
        GTest::gtest_main
)
target_compile_options(leetcode PRIVATE -Wno-sign-compare)
