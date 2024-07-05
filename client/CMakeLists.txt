cmake_minimum_required(VERSION 3.10)
project(branchApp)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Set the include directories
include_directories(/usr/include)

# Set the library directories
link_directories(/usr/lib)

# Add the executable target
add_executable(branchApp
    src/main.cpp
    src/common.cpp
)

# Link the executable to the shared library
target_link_libraries(branchApp
    my_library
)

# Set the output directory for the executable
set_target_properties(branchApp PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)

# Install the executable
install(TARGETS branchApp
    RUNTIME DESTINATION /usr/bin
)
