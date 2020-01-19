#include <iostream>
#include <chrono>

#include "Parser.h"
#include "Dijkstra.h"

int main(int argc, char* argv[]) {
    std::unordered_map<int, std::list<Edge>> * graphEdges;
    Graph * graph = nullptr;
    Dijkstra * dijkstraAlgorithm = nullptr;
    std::chrono::time_point<std::chrono::steady_clock> start, end;

    if (argc >= 3) {
        graphEdges = Parser::parseFile(argv[1]);
        graph = new Graph(graphEdges);
        dijkstraAlgorithm = new Dijkstra(*graph);
        if (argc == 3){
            start = std::chrono::steady_clock::now();
            dijkstraAlgorithm->shortest_path(atoi(argv[2]));
            end = std::chrono::steady_clock::now();
        }
        else if (argc == 4){
            start = std::chrono::steady_clock::now();
            dijkstraAlgorithm->shortest_path(atoi(argv[2]), atoi(argv[3]));
            end = std::chrono::steady_clock::now();
        }
        double elapsed_seconds = std::chrono::duration_cast<std::chrono::duration<double> >(end - start).count();
        std::cout << "czas obliczeń: " << elapsed_seconds <<  " sekund" << '\n';
    }
    return 0;
}