#ifndef GIS_GRAPHGENERATOR_H
#define GIS_GRAPHGENERATOR_H

#include "Graph.h"

class GraphGenerator {
private:
    static bool isEdgeDrawn(int probability);
    static int generateEdgeWeight(int maxWeight);

public:
    static Graph::edgeMap * generateGraph(int nVertices, int probability, int maxWeight);
};
#endif //GIS_GRAPHGENERATOR_H
