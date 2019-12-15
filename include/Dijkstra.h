#ifndef GIS_DIJKSTRA_H
#define GIS_DIJKSTRA_H

#include <limits.h>

#include "Graph.h"
class Dijkstra {
private:
    Graph graph;
    std::unordered_map<int, int> * distances{};
    std::unordered_map<int, int> * predecessors{};

    void initState();
    void clearState();
    void updateDistance(int vertex, int distance);
    bool isValidVertex(int vertex);
    int popPriorityQueue(std::unordered_map<int, int> * priorityQueue);
    void updateSuccessorsDistances(int vertex);
    void updatePredecessors(int vertex, int predecessor);
    int getDistance(int vertex);
    std::list<int> reconstructPath(int source, int destination);
    void calculate_shortest_path(int source, int destination);
    std::unordered_map<int, int> * createPriorityQueue();
    static void printPath(const std::list<int>& path);
    static void handleNoConnection(int source, int destination);
public:
    explicit Dijkstra(Graph pGraph);
    ~Dijkstra();
    void shortest_path(int source, int destination = INT_MIN);
    void getPath(int source, int destination);
};
#endif //GIS_DIJKSTRA_H
