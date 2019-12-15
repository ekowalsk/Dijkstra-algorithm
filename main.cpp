#include <iostream>
#include "Parser.h"
#include "Dijkstra.h"


int main(int argc, char* argv[]) {
    std::unordered_multimap<int, Edge> * graphEdges;

    if (argc == 2)
        graphEdges = Parser::parseFile(argv[1]);
    else
        graphEdges = Parser::parseStdin();
    Graph graph = Graph(graphEdges);

    Dijkstra dijkstra_algorithm = Dijkstra(graph);
    dijkstra_algorithm.shortest_path(2);
    dijkstra_algorithm.getPath(2, 7);
    dijkstra_algorithm.getPath(2, 5);
    dijkstra_algorithm.getPath(2, 1);
    dijkstra_algorithm.getPath(1, 6);



    return 0;
}