#ifndef GIS_DIJKSTRA_H
#define GIS_DIJKSTRA_H

#include "Graph.h"
class Dijkstra {
private:
    Graph graph;
    std::map<int, int> * priorityQueue{};
    std::map<int, int> * predecessors{};

    void initState();
    void clearState();
    void updateDistance(int vertex, int distance);
    bool isValidVertex(int vertex);
    int peekPriorityQueue();
    void eraseFromPriorityQueue(int vertex);
    void updateSuccessorsDistances(int vertex);
    void updatePredecessors(int vertex, int predecessor);
    int getDistance(int vertex);
    std::list<int> reconstructPath(int source, int destination);
    std::list<int> calculate_shortest_path(int source, int destination);
    static void printPath(const std::list<int>& path);
    static void handleNoConnection(int source, int destination);
public:
    explicit Dijkstra(Graph pGraph);
    ~Dijkstra();
    void shortest_path(int source, int destination);
};
#endif //GIS_DIJKSTRA_H
