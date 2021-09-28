add_subdirectory(third_party/poco)

include_directories(${Poco_SOURCE_DIR}/Net/include)
include_directories(${Poco_SOURCE_DIR}/Util/include)