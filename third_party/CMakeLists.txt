find_package(GTest REQUIRED)

if(GTest_FOUND)
    message(STATUS "Use system gtest library")
    enable_testing()
    include_directories(${GTEST_INCLUDE_DIRS})
else()
    message(STATUS "Use gtest from source")
    include(third_party/cmake-scripts/googletest.cmake)
endif()


find_package(Poco REQUIRED 
                Foundation
                Util
)

if(Poco_FOUND)
    message(STATUS "Use system poco library")
    enable_testing()
    include_directories(${POCO_INCLUDE_DIRS})
else()
    message(STATUS "Use poco from source")
    include(third_party/cmake-scripts/poco.cmake)
endif()