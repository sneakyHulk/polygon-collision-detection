include_directories(.)

add_library(boost_extension INTERFACE)
target_include_directories(boost_extension
        INTERFACE $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/..>
        $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
        )
target_link_libraries(boost_extension INTERFACE)