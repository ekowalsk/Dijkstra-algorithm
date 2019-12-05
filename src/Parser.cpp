#include <utility>

#include <iostream>
#include <fstream>

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

std::multimap<int, Edge> * Parser::parseFile(const std::string& fileName){
    int source = -1, destination = -1, weight = -1;
    std::ifstream inFile = openFile(fileName);
    auto * parsedEdges = new std::multimap<int, Edge>{};

    while (inFile >> source) {
        if (inFile >> destination >> weight)
            parsedEdges->insert(std::make_pair(source, Edge(source, destination, weight)));
        else {
            std::cerr << "Bad input data format" << std::endl;
            exit(-1);
        }
    }
    return parsedEdges;
}

std::ifstream Parser::openFile(const std::string& fileName){
    std::ifstream inFile;
    inFile.open(fileName);
    if (!inFile) {
        std::cerr << "Unable to open file test_graph.txt";
        exit(1);
    }
    return inFile;
}

