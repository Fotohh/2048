cmake_minimum_required(VERSION 3.28)
project(c2048 C)

set(CMAKE_C_STANDARD 23)

find_package(raylib CONFIG REQUIRED)


add_executable(c2048 main.c
        window.c
        window.h
        grid.h
        grid.c)

target_link_libraries(c2048 PRIVATE raylib)
