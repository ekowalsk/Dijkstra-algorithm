#include <iostream>
#include "Parser.h"
#include "Dijkstra.h"

int main(int argc, char* argv[]) {
    std::multimap<int, Edge> * graphEdges;
    if (argc == 2){
        graphEdges = Parser::parseFile(argv[1]);
    }
    else
        graphEdges = Parser::parseStdin();
    Graph graph = Graph(graphEdges);
    graph.print();

    Dijkstra dijkstra_algorithm = Dijkstra(graph);
    dijkstra_algorithm.shortest_path(2,5);

    return 0;
}