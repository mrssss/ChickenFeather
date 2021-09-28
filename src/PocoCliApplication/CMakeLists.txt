project(poco_cli_application)

add_executable(poco_cli
        cli.cpp
        CliApplication.h
        CliApplication.cpp)

target_link_libraries(poco_cli Poco::Util)