#include <limits.h>
#include <iostream>

#include "Graph.h"
#include "Parser.h"

Graph::Graph(std::unordered_map<int, std::list<Edge>> * e){
    this->edges = new std::unordered_map<int, std::list<Edge>>();
    for (auto & edge : *e)
        this->edges->insert(std::make_pair(edge.first, std::list<Edge>(edge.second)));
}

Graph::Graph(const Graph & graph){
    this->edges = new std::unordered_map<int, std::list<Edge>>();
    for (auto & edge : *graph.edges)
        this->edges->insert(std::make_pair(edge.first, std::list<Edge>(edge.second)));
}

Graph::edgeIterator Graph::getOutgoingEdges (int vertex) {
    return edges->find(vertex);
}

Graph::~Graph(){
    delete edges;
}

void Graph::print() const {
    for (auto & edge : *edges){
        for (auto & e : edge.second)
            e.printEdge();
    }
}



