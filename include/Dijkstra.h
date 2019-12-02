#ifndef GIS_DIJKSTRA_H
#define GIS_DIJKSTRA_H

#include "Graph.h"
class Dijkstra {
private:
    Graph graph;
    std::map<int, int> * priorityQueue;
    std::map<int, int> * predecessors;

    void initState();
    void clearState();
    void updateDistance(int vertex, int distance);
    bool isValidVertex(int vertex);
    int peekPriorityQueue();
    void eraseFromPriorityQueue(int vertex);
    void updateSuccessorsDistances(int vertex);
    int getDistance(int vertex);
    std::list<int> reconstructPath(int source, int destination);
    std::string printPath(const std::list<int>& path);
public:
    Dijkstra(Graph pGraph);
    ~Dijkstra();
    std::pair<int, std::list<int>> shortest_path(int source, int destination);
};
#endif //GIS_DIJKSTRA_H
