#include <random>

#include "GraphGenerator.h"

Graph::edgeMap * GraphGenerator::generateGraph(int nVertices, int probability, int maxWeight){
    auto * edgeMap = new Graph::edgeMap();
    for (int i = 1; i <= nVertices; i++)
        edgeMap->insert(std::make_pair(i, std::list<Edge>()));
    for (auto mapElement1 = edgeMap->begin(); mapElement1 != edgeMap->end(); mapElement1++){
        auto mapElement2 = edgeMap->begin();
        while (mapElement2 != edgeMap->end()){
            if (mapElement2 != mapElement1){
                if (isEdgeDrawn(probability))
                    edgeMap->at(mapElement1->first).emplace_back(Edge(mapElement1->first, mapElement2->first, generateEdgeWeight(maxWeight)));
            }
            mapElement2++;
        }
    }
    return edgeMap;
}

bool GraphGenerator::isEdgeDrawn(int probability) {
    std::random_device r;
    std::default_random_engine e1(r());
    std::uniform_int_distribution<int> uniform_dist(1, 100);
    return uniform_dist(e1) < probability;
}

int GraphGenerator::generateEdgeWeight(int maxWeight){
    std::random_device r;
    std::default_random_engine e1(r());
    std::uniform_int_distribution<int> uniform_dist(maxWeight/2, maxWeight);
    return uniform_dist(e1);
}