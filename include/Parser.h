#ifndef GIS_PARSER_H
#define GIS_PARSER_H

#include <unordered_map>
#include <list>

#include "Edge.h"
#include "Graph.h"

class Parser {
private:
    static std::ifstream openFile(const std::string& fileName);
public:
    static std::unordered_map<int, std::list<Edge>> * parseStdin();
    static std::unordered_map<int, std::list<Edge>> * parseFile(const std::string& fileName);
    static void parseGraphToFile(Graph::edgeMap * edges, const std::string& fileName);
};

#endif //GIS_PARSER_H
