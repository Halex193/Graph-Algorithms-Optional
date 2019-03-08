//
// Created by Horatiu on 03-Mar-19.
//

#ifndef LAB1OPTIONAL_DIRECTEDGRAPH_H
#define LAB1OPTIONAL_DIRECTEDGRAPH_H

#include <map>
#include <vector>
#include <rpcndr.h>

using namespace std;

class DirectedGraph
{
protected:

    map<int, vector<int>> inEdges;
    map<int, vector<int>> outEdges;
    map<pair<int, int>, int> edges;

public:

    class iterator
    {

    };

    DirectedGraph();

    DirectedGraph(int initialVertexNumber, int initialEdgeNumber);

    int getNumberOfVertices();

    int getNumberOfEdges();

    int inDegree(int vertex);

    int outDegree(int vertex);

    vector<int>::iterator parseInboundEdges(int vertex);

    vector<int>::iterator parseOutboundEdges(int vertex);

    vector<int>::iterator parseVertices();

    bool existsEdge(int vertex1, int vertex2);

    int getCost(int vertex1, int vertex2);

    void changeCost(int vertex1, int vertex2, int newCost);

    void addVertex(int vertex);

    bool existsVertex(int vertex);

    void removeVertex(int vertex);

    void addEdge(int vertex1, int vertex2, int cost);

    void removeEdge(int vertex1, int vertex2);

    vector<pair<int, int>>::iterator parseEdges();

    DirectedGraph copy();
};


#endif //LAB1OPTIONAL_DIRECTEDGRAPH_H
