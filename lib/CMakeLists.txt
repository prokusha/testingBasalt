cmake_minimum_required(VERSION 3.10)

project(libbranch VERSION 1.0.0)

# Создаем shared library
add_library(libbranch SHARED
    src/getBranch.cpp
    include/getBranch.h
)

# Устанавливаем версию библиотеки
set_target_properties(libbranch PROPERTIES
    VERSION ${PROJECT_VERSION}
    SOVERSION 1
)

# Указываем путь к заголовочным файлам
target_include_directories(libbranch
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:/usr/include>
)

# Устанавливаем библиотеку
install(TARGETS libbranch
    LIBRARY DESTINATION /usr/lib
    ARCHIVE DESTINATION /usr/lib
    RUNTIME DESTINATION /usr/bin
)

# Устанавливаем заголовочные файлы
install(DIRECTORY include/
    DESTINATION /usr/include
)
