cmake_minimum_required(VERSION 3.31)
project(os_lab1)

set(CMAKE_CXX_STANDARD 20)

add_executable(os_lab1 src/main.cpp
        include/employee.h
        src/Creator.cpp
        src/reporter.cpp)
