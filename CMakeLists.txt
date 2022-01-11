cmake_minimum_required(VERSION 3.17)
project(Microcraft)

set(CMAKE_CXX_STANDARD 14)


include_directories(src)
include_directories(include)


add_executable(Microcraft
        lib/glad.c
        src/main.cpp)

target_link_libraries(Microcraft PRIVATE
        "-framework Cocoa"
        "-framework OpenGL"
        "-framework IOKit"
        ${CMAKE_SOURCE_DIR}/lib/libglfw3.a)

