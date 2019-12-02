#ifndef GIS_PARSER_H
#define GIS_PARSER_H

#include <map>

#include "Edge.h"

class Parser {
public:
    static std::multimap<int, Edge> * parseStdin();
};

#endif //GIS_PARSER_H
