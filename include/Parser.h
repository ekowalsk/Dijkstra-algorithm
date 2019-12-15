#ifndef GIS_PARSER_H
#define GIS_PARSER_H

#include <unordered_map>

#include "Edge.h"

class Parser {
public:
    static std::unordered_multimap<int, Edge> * parseStdin();
    static std::unordered_multimap<int, Edge> * parseFile(const std::string& fileName);
    static std::ifstream openFile(const std::string& fileName);
};

#endif //GIS_PARSER_H
