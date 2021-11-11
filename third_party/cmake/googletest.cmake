find_package(GTest REQUIRED
                gtest
                gtest_main
)

if(GTest_FOUND)
    message(STATUS "Use system gtest library")
    enable_testing()
    set_target_properties (GTest::gtest
                           GTest::gtest_main
        PROPERTIES IMPORTED_GLOBAL TRUE
    )
else()
    message(STATUS "Use gtest from source")
    enable_testing()
    add_subdirectory(googletest)
endif()