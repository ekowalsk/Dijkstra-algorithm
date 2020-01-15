#include <iostream>

#include "Parser.h"
#include "Dijkstra.h"
#include "GraphGenerator.h"

int main(int argc, char* argv[]) {
    std::unordered_map<int, std::list<Edge>> * graphEdges;

    if (argc == 2)
        graphEdges = Parser::parseFile(argv[1]);
    else
        graphEdges = Parser::parseStdin();
    Graph graph = Graph(graphEdges);

    //dijkstra_algorithm.shortest_path(2);
    //dijkstra_algorithm.getPath(2, 7);
    //dijkstra_algorithm.getPath(2, 5);
    //dijkstra_algorithm.getPath(2, 1);

    Graph::edgeMap * edges = GraphGenerator::generateGraph(1000, 3, 10);
    Parser::parseGraphToFile(edges, "parsedEdges.txt");

    Graph g2 = Graph(edges);
    Dijkstra dijkstra_algorithm = Dijkstra(g2);
    dijkstra_algorithm.shortest_path(1,60);

    return 0;
}