cmake_minimum_required(VERSION 3.31)
project(os_lab1)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Создаем отдельные исполнимые файлы для Main, Creator и Reporter
add_executable(Main src/main.cpp)
add_executable(Creator src/Creator.cpp)
add_executable(Reporter src/reporter.cpp)

# Указываем общие каталоги для заголовочных файлов
target_include_directories(Main PRIVATE ${CMAKE_SOURCE_DIR}/include)
target_include_directories(Creator PRIVATE ${CMAKE_SOURCE_DIR}/include)
target_include_directories(Reporter PRIVATE ${CMAKE_SOURCE_DIR}/include)

#enable_testing()

#include(FetchContent)
#FetchContent_Declare(
#        googletest
#        URL https://github.com/google/googletest/archive/release-1.12.1.zip
#)
#set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
#FetchContent_MakeAvailable(googletest)
