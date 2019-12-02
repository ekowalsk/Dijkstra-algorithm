#include <limits.h>
#include <iostream>

#include "Graph.h"
#include "Parser.h"

//TODO utworzyć klasę Dijkstra algorithm, dodać do niej updateDistance
Graph::Graph(){
    edges = Parser::parseStdin();
}

std::pair<Graph::edgeIterator, Graph::edgeIterator> Graph::getOutgoingEdges (int vertex) {
    return edges->equal_range(vertex);
}

Graph::~Graph(){
    delete edges;
}




