cmake_minimum_required(VERSION 4.1)
project(Practica1)

set(CMAKE_CXX_STANDARD 11)

add_executable(Practica1 main.cpp
        Especie.cpp
        Especie.h
        LectorCSV.cpp
        LectorCSV.h
        VDinamico.h
        ListaDEnlazada.h
        Parque.cpp
        Parque.h)
