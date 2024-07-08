cmake_minimum_required(VERSION 3.10)
project(branchApp VERSION 1.0.0)

add_subdirectory(lib)
add_subdirectory(client)

include(CPack)

set(CPACK_GENERATOR "RPM")
set(CPACK_PACKAGE_NAME "${PROJECT_NAME}")
set(CPACK_PACKAGE_VERSION "${PROJECT_VERSION}")
