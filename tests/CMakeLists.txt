cmake_minimum_required(VERSION 3.22)
project(TDAs_tests)

set(CMAKE_C_STANDARD 23)

add_subdirectory(gtest_lib)

include_directories(../include)
include_directories(${gmock_SOURCE_DIR}/include ${gmock_SOURCE_DIR})

add_executable(Google_Tests_run
        ABB_tests.cpp
        Heap_tests.cpp
        Grafo_tests.cpp
        ../src/Grafo.cpp
        ../src/Dijkstra.cpp
        ../src/Floyd.cpp
        ../src/Matriz.cpp
)

target_link_libraries(Google_Tests_run gtest gtest_main)