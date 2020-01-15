#include <utility>

#include <iostream>
#include <fstream>

#include "Parser.h"

std::unordered_map<int, std::list<Edge>> * Parser::parseStdin(){
    int source = -1, destination = -1, weight = -1;
    auto * parsedEdges = new std::unordered_map<int, std::list<Edge>>{};
    while (std::cin >> source){
        if (std::cin >> destination >> weight){
            if (parsedEdges->find(source) == parsedEdges->end())
                parsedEdges->insert(std::make_pair(source, std::list<Edge>()));
            parsedEdges->find(source)->second.emplace_back(source, destination, weight);
        }
        else {
            std::cerr << "Bad input data format" << std::endl;
            exit(-1);
        }
    }
    return parsedEdges;
}

std::unordered_map<int, std::list<Edge>> * Parser::parseFile(const std::string& fileName){
    int source = -1, destination = -1, weight = -1;
    std::ifstream inFile = openFile(fileName);
    auto * parsedEdges = new std::unordered_map<int, std::list<Edge>>{};

    while (inFile >> source) {
        if (inFile >> destination >> weight){
            if (parsedEdges->find(source) == parsedEdges->end())
                parsedEdges->insert(std::make_pair(source, std::list<Edge>()));
            parsedEdges->find(source)->second.emplace_back(source, destination, weight);
        }
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
        std::cerr << "Unable to open file " << fileName;
        exit(1);
    }
    return inFile;
}

void Parser::parseGraphToFile(Graph::edgeMap * edgesMap, const std::string& fileName){
    std::ofstream outFile;
    outFile.open(fileName, std::ofstream::trunc);
    if (!outFile) {
        std::cerr << "Unable to open file " << fileName;
        exit(1);
    }
    
    for (auto &mapElement : *edgesMap){
        for (auto edge : mapElement.second) {
            outFile << mapElement.first << " " << edge.getDestination() << " " << edge.getWeight() << std::endl;
        }
    }
}

