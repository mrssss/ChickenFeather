find_package (Boost COMPONENTS system thread REQUIRED)

if (Boost_FOUND)
    message (STATUS "Use system boost")
    set_target_properties (Boost::boost
                           Boost::system
                           Boost::thread
        PROPERTIES IMPORTED_GLOBAL TRUE
    )
else ()
    message (FATAL_ERROR "boost not found")
endif ()
