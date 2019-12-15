#ifndef GIS_PARSER_H
#define GIS_PARSER_H

#include <unordered_map>
#include <list>

#include "Edge.h"

class Parser {
public:
    static std::unordered_map<int, std::list<Edge>> * parseStdin();
    static std::unordered_map<int, std::list<Edge>> * parseFile(const std::string& fileName);
    static std::ifstream openFile(const std::string& fileName);
};

#endif //GIS_PARSER_H
