#include <iostream>
#include "Edge.h"

Edge::Edge(int source, int destination, int weight){
    this->source = source;
    this->destination = destination;
    this->weight = weight;
}

int Edge::getSource() const {
    return source;
}

void Edge::setSource(int source) {
    Edge::source = source;
}

int Edge::getDestination() const {
    return destination;
}

void Edge::setDestination(int destination) {
    Edge::destination = destination;
}

int Edge::getWeight() const {
    return weight;
}

void Edge::setWeight(int weight) {
    Edge::weight = weight;
}
