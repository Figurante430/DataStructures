cmake_minimum_required(VERSION 3.26)
project(PL1Ds)

set(CMAKE_CXX_STANDARD 23)

add_executable(PL1Ds main.cpp
        Coordinate.hpp
        Pila.cpp
        Coordinate.cpp
        auxLib.cpp
        Cola.cpp
        Paquete.cpp
        Label.cpp
        ColadeCamiones.hpp
        ColadeCamiones.cpp
        Cola.hpp
        Label.hpp
        Paquete.hpp
        Pila.hpp)
