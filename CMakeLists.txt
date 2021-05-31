cmake_minimum_required(VERSION 3.19)
project(EDA_Quadtree)

set(CMAKE_CXX_STANDARD 17)

include_directories(.)

add_executable(EDA_Quadtree
        main.cpp
        Pgm.h
        Point.h
        QuadTree.h
        QuadTreeNode.h)
