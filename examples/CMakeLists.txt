project (examples)

add_executable (stl_clock
stl/utilities/clock.cpp
)

add_executable (stl_calendar
    stl/utilities/calendar.cpp
)

add_executable (boost_validate_installation
    boost/validate_install/validate.cpp
)
target_link_libraries (boost_validate_installation 
    PRIVATE 
        Boost::boost
)

add_executable (poco_active_object
    poco/active_object/active_object.cpp
)
target_link_libraries (poco_active_object
    PRIVATE
        Poco::Foundation
)

add_executable (poco_basic_event
    poco/event/basic_event.cpp
)
target_link_libraries (poco_basic_event
    PRIVATE
        Poco::Foundation
)

add_executable (poco_time_server
    poco/time_server/time_server.cpp
)
target_link_libraries (poco_time_server
    PRIVATE
        Poco::Net
        Poco::Util
)

add_executable (basic_max_example
    basic/max.cpp
)
target_link_libraries (basic_max_example PRIVATE basic::max)

add_executable (basic_smart_pointer_example
    basic/smart_pointer.cpp
)
target_link_libraries (basic_smart_pointer_example PRIVATE basic::smart_pointer)

add_executable (rocksdb_example
    rocksdb/rocksdb_example.cpp
)
target_link_libraries (rocksdb_example PRIVATE rocksdb)