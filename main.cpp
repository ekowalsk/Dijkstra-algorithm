#include <iostream>

#include "Parser.h"
#include "Dijkstra.h"
#include "Utils.h"
#include "GraphGenerator.h"

int main(int argc, char* argv[]) {
    //Graph::edgeMap * edges = GraphGenerator::generateGraph(5000, 1, 1, 10);
    //Parser::parseGraphToFile(edges, "parsedEdges.txt");
    std::unordered_map<int, std::list<Edge>> * graphEdges;
    Graph * graph = nullptr;
    Dijkstra * dijkstraAlgorithm = nullptr;

    if (argc == 3 || argc == 4) {
        graphEdges = Parser::parseFile(argv[1]);
        graph = new Graph(graphEdges);
        dijkstraAlgorithm = new Dijkstra(*graph);
        if (argc == 3)
            dijkstraAlgorithm->shortestPath(atoi(argv[2]));
        else
            dijkstraAlgorithm->shortestPath(atoi(argv[2]), atoi(argv[3]));
    } else
        displayHelp();
    return 0;
}