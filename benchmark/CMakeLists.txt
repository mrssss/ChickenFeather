project (benchmark)

add_executable (benchmark_sample
    benchmark_sample.cpp
)
target_link_libraries(benchmark_sample
    PRIVATE
        benchmark::benchmark
)
