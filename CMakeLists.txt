cmake_minimum_required(VERSION 3.19)
project(EDA_LAB04_QUADTREE)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(EDA_LAB04_QUADTREE
        main.cpp
        Node.h
        Point.h
        QuadTree.cpp
        QuadTree.h Pgm.h)
