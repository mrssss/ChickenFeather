find_package(Poco REQUIRED 
                Foundation 
                Util 
                Net
)

if(Poco_FOUND)
    message(STATUS "Use system poco library")
    enable_testing()
    set_target_properties (Poco::Foundation
                           Poco::Util
                           Poco::Net
        PROPERTIES IMPORTED_GLOBAL TRUE
    )
else()
    message(FATAL_ERROR "Poco Not Found")
endif()

