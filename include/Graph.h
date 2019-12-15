#ifndef GIS_GRAPH_H
#define GIS_GRAPH_H

#include <unordered_map>
#include <list>

#include "Edge.h"

class Graph {
public:
    typedef std::unordered_map<int, std::list<Edge>>::iterator edgeIterator;
    Graph(std::unordered_map<int, std::list<Edge>> * edges);
    Graph(const Graph & graph);
    ~Graph();
    void print() const;
    friend class Dijkstra;
private:
    std::unordered_map<int, std::list<Edge>> * edges; // pairs <startVertex, Edge>
    edgeIterator getOutgoingEdges (int vertex);
};
#endif //GIS_GRAPH_H
