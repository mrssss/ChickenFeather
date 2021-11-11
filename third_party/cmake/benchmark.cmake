find_package(benchmark REQUIRED)

if (benchmark_FOUND)
    message (STATUS "Use system google benchmark")
    set_target_properties (benchmark::benchmark
        PROPERTIES IMPORTED_GLOBAL TRUE
    )
else ()
    message (FATAL_ERROR "Not Found benchmark")
    # message(STATUS "Use benchmark from source")
    # add_subdirectory (benchmark)
endif()
