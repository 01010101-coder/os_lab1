add_executable(Main main.cpp)
add_executable(Creator creator.cpp)
add_executable(Reporter reporter.cpp)

target_include_directories(Main PRIVATE ${CMAKE_SOURCE_DIR}/include)
target_include_directories(Creator PRIVATE ${CMAKE_SOURCE_DIR}/include)
target_include_directories(Reporter PRIVATE ${CMAKE_SOURCE_DIR}/include)