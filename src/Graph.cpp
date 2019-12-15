#include <limits.h>
#include <iostream>

#include "Graph.h"
#include "Parser.h"

Graph::Graph(std::unordered_multimap<int, Edge> * e){
    this->edges = new std::unordered_multimap<int, Edge>();
    for (auto & edge : *e)
        this->edges->insert(std::make_pair(edge.first, edge.second));
}

Graph::Graph(const Graph & graph){
    this->edges = new std::unordered_multimap<int, Edge>();
    for (auto & edge : *graph.edges)
        this->edges->insert(std::make_pair(edge.first, edge.second));
}

std::pair<Graph::edgeIterator, Graph::edgeIterator> Graph::getOutgoingEdges (int vertex) {
    return edges->equal_range(vertex);
}

Graph::~Graph(){
    delete edges;
}

void Graph::print() const {
    for (auto & edge : *edges)
        edge.second.printEdge();
}



