cmake_minimum_required(VERSION 3.14)
project(GIS)

set(CMAKE_CXX_STANDARD 14)

add_executable(GIS main.cpp include/Edge.h src/Edge.cpp include/Graph.h src/Graph.cpp src/Parser.cpp include/Parser.h include/Dijkstra.h src/Dijkstra.cpp)

include_directories(./include)