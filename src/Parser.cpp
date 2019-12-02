#include <iostream>

#include "Parser.h"

std::multimap<int, Edge> * Parser::parseStdin(){
    int source = -1, destination = -1, weight = -1;
    auto * parsedEdges = new std::multimap<int, Edge>{};
    while (std::cin >> source){
        if (std::cin >> destination >> weight)
            parsedEdges->insert(std::make_pair(source, Edge(source, destination, weight)));
        else {
            std::cerr << "Bad input data format" << std::endl;
            exit(-1);
        }
    }
    return parsedEdges;
}

