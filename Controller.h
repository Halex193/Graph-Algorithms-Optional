//
// Created by Horatiu on 03-Mar-19.
//

#ifndef LAB1OPTIONAL_CONTROLLER_H
#define LAB1OPTIONAL_CONTROLLER_H


#include "graphs/DirectedGraph.h"

class Controller
{
private:
    DirectedGraph directedGraph;

public:
    explicit Controller(const DirectedGraph &directedGraph);
};


#endif //LAB1OPTIONAL_CONTROLLER_H
