cmake_minimum_required(VERSION 3.10)
project(branchApp VERSION 1.0.0)

include_directories(/usr/include)

link_directories(/usr/lib)

add_executable(branchApp
    src/main.cpp
    src/common.cpp
)

target_link_libraries(branchApp branch)

set_target_properties(branchApp PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)
