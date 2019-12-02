#ifndef GIS_EDGE_H
#define GIS_EDGE_H

class Edge {
private:
    int source;
    int destination;
    int weight;

public:
    Edge (int source, int destination, int weight);

    int getSource() const;
    void setSource(int source);
    int getDestination() const;
    void setDestination(int destination);
    int getWeight() const;
    void setWeight(int weight);

    friend class Graph;
};
#endif //GIS_EDGE_H
