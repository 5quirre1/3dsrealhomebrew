cmake_minimum_required(VERSION 3.13)
project(hello C)

set(CMAKE_TOOLCHAIN_FILE "/c/devkitPro/cmake/3DS.cmake")
set(CMAKE_EXECUTABLE_SUFFIX ".3dsx")

add_executable(hello
    source/main.c
)

target_link_libraries(hello ctru citro3d citro2d)
