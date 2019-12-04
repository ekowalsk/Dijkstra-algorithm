#include <iostream>
#include "Edge.h"

Edge::Edge(int source, int destination, int weight){
    this->source = source;
    this->destination = destination;
    this->weight = weight;
}

int Edge::getWeight() const {
    return weight;
}

int Edge::getDestination() const {
    return destination;
}

void Edge::printEdge() const {
    std::cout << source << " -> " << destination << " : " << weight << std::endl;
}