#ifndef GIS_GRAPH_H
#define GIS_GRAPH_H

#include <map>
#include <list>

#include "Edge.h"

class Graph {
public:
    typedef std::multimap<int, Edge>::iterator edgeIterator;
    Graph(std::multimap<int, Edge> * edges);
    Graph(const Graph & graph);
    ~Graph();
    void print() const;
    friend class Dijkstra;
private:
    std::multimap<int, Edge> * edges; // pairs <startVertex, Edge>
    std::pair<edgeIterator, edgeIterator> getOutgoingEdges (int vertex);
};
#endif //GIS_GRAPH_H
