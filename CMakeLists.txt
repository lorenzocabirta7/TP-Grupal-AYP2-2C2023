cmake_minimum_required(VERSION 3.22)
project(ayp2_plantilla_tp_grupal_2c2023)

set(CMAKE_C_STANDARD 23)

add_compile_options(-Wall -Werror -Wconversion)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "../")
set(CXXFLAGS "-Wall -Werror -Wconversion")
set(CMAKE_CXX_FLAGS "${CXXFLAGS}")

include_directories(include)
include_directories(src)
include_directories(bGVjdG9y)

add_executable(ayp2_plantilla_tp_grupal_2c2023
        src/Placa.cpp
        src/Arma.cpp
        src/Grafo.cpp
        src/Floyd.cpp
        src/Dijkstra.cpp
        src/Matriz.cpp
        bGVjdG9y/bGVjdG9y.cpp
        bGVjdG9y/ZGVjb2Rl.cpp
        main.cpp
)

set_target_properties(${PROJECT_NAME} PROPERTIES OUTPUT_NAME "main")