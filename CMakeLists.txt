cmake_minimum_required(VERSION 3.16)
project(Overengineered)

set(CMAKE_CXX_STANDARD 17)

file(GLOB_RECURSE SOURCES
    source/entry/*.cpp
)

add_executable(Overengineered ${SOURCES})

target_include_directories(Overengineered PRIVATE
    ${CMAKE_SOURCE_DIR}/raylib/include
    ${CMAKE_SOURCE_DIR}/inc
    ${CMAKE_SOURCE_DIR}/source/entry
)

link_directories(${CMAKE_SOURCE_DIR}/raylib/lib)

target_link_libraries(Overengineered
    raylib
    opengl32
    gdi32
    winmm
)