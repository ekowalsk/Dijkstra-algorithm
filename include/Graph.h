#ifndef GIS_GRAPH_H
#define GIS_GRAPH_H

#include <unordered_map>
#include <list>

#include "Edge.h"

class Graph {
public:
    typedef std::unordered_multimap<int, Edge>::iterator edgeIterator;
    Graph(std::unordered_multimap<int, Edge> * edges);
    Graph(const Graph & graph);
    ~Graph();
    void print() const;
    friend class Dijkstra;
private:
    std::unordered_multimap<int, Edge> * edges; // pairs <startVertex, Edge>
    std::pair<edgeIterator, edgeIterator> getOutgoingEdges (int vertex);
};
#endif //GIS_GRAPH_H
