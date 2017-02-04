cmake_minimum_required(VERSION 3.1)
project(ProjektSemestralnyTestowanie)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp Vehicle.cpp Vehicle.h EventsQueue.cpp EventsQueue.h Stop.cpp Stop.h Linia.cpp
        Linia.h Simulation.cpp Simulation.h Compare.cpp Compare.h Event.cpp Event.h Clock.cpp Tram.h Tram.cpp Clock.h  Person.cpp Person.h)
add_executable(ProjektSemestralnyTestowanie ${SOURCE_FILES})