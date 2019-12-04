#ifndef GIS_PARSER_H
#define GIS_PARSER_H

#include <map>

#include "Edge.h"

class Parser {
public:
    static std::multimap<int, Edge> * parseStdin();
    static std::multimap<int, Edge> * parseFile(const std::string& fileName);
    static std::ifstream openFile(const std::string& fileName);
};

#endif //GIS_PARSER_H
