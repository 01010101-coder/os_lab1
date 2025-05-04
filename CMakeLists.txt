cmake_minimum_required(VERSION 3.31)
project(os_lab1)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Добавление исходных файлов для компиляции
add_executable(os_lab1
        src/main.cpp
        src/Creator.cpp
        src/reporter.cpp
)

# Включите подпроекты.
add_subdirectory(src)

#enable_testing()

#include(FetchContent)
#FetchContent_Declare(
#        googletest
#        URL https://github.com/google/googletest/archive/release-1.12.1.zip
#)
#set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
#FetchContent_MakeAvailable(googletest)
