cmake_minimum_required(VERSION 3.12)
project(trabalho_grafos_grupo11)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)

add_executable(trabalho_grafos_grupo11
        include/Aresta.h
        include/GrafoListaAdj.h
        include/Vertice.h
        src/Aresta.cpp
        src/GrafoListaAdj.cpp
        src/Vertice.cpp
        main.cpp)
