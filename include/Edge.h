#ifndef GIS_EDGE_H
#define GIS_EDGE_H

class Edge {
private:
    int source;
    int destination;
    int weight;
public:
    Edge (int source, int destination, int weight);
};
#endif //GIS_EDGE_H
