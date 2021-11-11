project(tests)

add_subdirectory (leetcode)

# This is a workaround for the requirements of add_executable command
file(WRITE null.cpp "")

add_executable (unit_tests
    null.cpp
)
target_sources (unit_tests
    PRIVATE
        # cal/add/test_add.cpp
        # palindrome/test_is_palindrome.cpp
)
target_link_libraries (unit_tests
    PRIVATE
        GTest::gtest
        GTest::gtest_main
        # add
)
