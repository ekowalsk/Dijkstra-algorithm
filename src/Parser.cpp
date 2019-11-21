#include <iostream>

#include "Parser.h"

Edge Parser::parseLine(){
    int source, destination, weight;
    std::cin >> source;
    std::cin >> destination;
    std::cin >> weight;
    return Edge(source, destination, weight);
}

