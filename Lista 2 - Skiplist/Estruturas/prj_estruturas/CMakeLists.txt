cmake_minimum_required(VERSION 3.28)
project(prj_estruturas)

set(CMAKE_CXX_STANDARD 17)

add_executable(prj_estruturas main.cpp
        Lista.cpp
        Lista.h
        Passenger.cpp
        Passenger.h)
