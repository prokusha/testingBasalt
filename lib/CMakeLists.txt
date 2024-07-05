cmake_minimum_required(VERSION 3.10)

project(libbranch VERSION 1.0.0)

add_library(branch SHARED
    src/getBranch.cpp
    include/getBranch.h
)

set_target_properties(branch PROPERTIES
    VERSION ${PROJECT_VERSION}
    SOVERSION 1
)

target_include_directories(branch
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:/usr/include>
)

install(TARGETS branch
    LIBRARY DESTINATION /usr/lib
    ARCHIVE DESTINATION /usr/lib
    RUNTIME DESTINATION /usr/bin
)

install(DIRECTORY include/
    DESTINATION /usr/include
)
