find_package (RocksDB)

if (NOT RocksDB_FOUND)
    message (FATAL_ERROR "RocksDB Not Found")
endif()
