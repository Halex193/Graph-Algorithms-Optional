//
// Created by Horatiu on 03-Mar-19.
//

#include "DirectedGraph.h"
#include "exceptions/VertexDoesNotExistException.h"
#include "exceptions/VertexAlreadyExistsException.h"
#include "exceptions/EdgeDoesNotExistException.h"
#include "exceptions/EdgeAlreadyExistsException.h"

DirectedGraph::DirectedGraph() = default;

DirectedGraph::DirectedGraph(int initialVertexNumber, int initialEdgeNumber)
{
//    inEdges = map<int, vector<int>>();
//    outEdges = map<int, vector<int>>();
//    edges = map<pair<int, int>, int>();

    for (int i = 0; i < initialVertexNumber; i++)
    {
        addVertex(i);
    }
}

int DirectedGraph::getNumberOfVertices()
{
    return inEdges.size();
}

int DirectedGraph::getNumberOfEdges()
{
    return edges.size();
}

int DirectedGraph::inDegree(int vertex)
{
    if (!existsVertex(vertex))
    {
        throw VertexDoesNotExistException();
    }

    return inEdges.find(vertex)->second.size();
}

int DirectedGraph::outDegree(int vertex)
{
    if (!existsVertex(vertex))
    {
        throw VertexDoesNotExistException();
    }

    return outEdges.find(vertex)->second.size();
}

vector<int>::iterator DirectedGraph::parseInboundEdges(int vertex)
{
    return inEdges.find(vertex)->second.begin();
}

vector<int>::iterator DirectedGraph::parseOutboundEdges(int vertex)
{
    return outEdges.find(vertex)->second.begin();
}

vector<int>::iterator DirectedGraph::parseVertices()
{
    std::vector<int> vertices;
    vertices.reserve(inEdges.size());
    for (auto const &pair: inEdges)
        vertices.push_back(pair.first);
    return vertices.begin();
}

bool DirectedGraph::existsEdge(int vertex1, int vertex2)
{
    return edges.find(pair<int, int>(vertex1, vertex2)) != edges.end();
}

int DirectedGraph::getCost(int vertex1, int vertex2)
{
    if (!existsEdge(vertex1, vertex2))
    {
        throw EdgeDoesNotExistException();
    }
    return edges.find(pair<int, int>(vertex1, vertex2))->second;
}

void DirectedGraph::changeCost(int vertex1, int vertex2, int newCost)
{
    if (!existsEdge(vertex1, vertex2))
    {
        throw EdgeDoesNotExistException();
    }
    edges.find(pair<int, int>(vertex1, vertex2))->second = newCost;
}

void DirectedGraph::addVertex(int vertex)
{
    if (existsVertex(vertex))
    {
        throw VertexAlreadyExistsException();
    }
    inEdges.insert(pair<int, vector<int>>(vertex, vector<int>()));
    outEdges.insert(pair<int, vector<int>>(vertex, vector<int>()));
}

bool DirectedGraph::existsVertex(int vertex)
{
    return inEdges.find(vertex) != inEdges.end();
}

void DirectedGraph::removeVertex(int vertex)
{
    if (!existsVertex(vertex))
    {
        throw VertexDoesNotExistException();
    }

    vector<int> *inEdgesList = &inEdges.find(vertex)->second;
    while (!inEdgesList->empty())
    {
        int vertex1 = (*inEdgesList)[0];
        removeEdge(vertex1, vertex);
    }
    vector<int> *outEdgesList = &outEdges.find(vertex)->second;
    while (!outEdgesList->empty())
    {
        int vertex2 = (*outEdgesList)[0];
        removeEdge(vertex, vertex2);
    }
    inEdges.erase(vertex);
    outEdges.erase(vertex);
}

void DirectedGraph::addEdge(int vertex1, int vertex2, int cost)
{
    if (!existsVertex(vertex1))
    {
        throw VertexDoesNotExistException();
    }
    if (!existsVertex(vertex2))
    {
        throw VertexDoesNotExistException();
    }
    if (existsEdge(vertex1, vertex2))
    {
        throw EdgeAlreadyExistsException();
    }
    inEdges.find(vertex2)->second.push_back(vertex1);
    outEdges.find(vertex1)->second.push_back(vertex2);
    edges.insert({{vertex1, vertex2}, cost});
}

void DirectedGraph::removeEdge(int vertex1, int vertex2)
{
    if (!existsVertex(vertex1))
    {
        throw VertexDoesNotExistException();
    }
    if (!existsVertex(vertex2))
    {
        throw VertexDoesNotExistException();
    }
    if (!existsEdge(vertex1, vertex2))
    {
        throw EdgeDoesNotExistException();
    }

    vector<int> *vector1 = &inEdges.find(vertex2)->second;
    vector1->erase(vector1->find(vertex2));
    // TODO from here on out
    outEdges.get(vertex1).remove(Integer.valueOf(vertex2));
    edges.remove(new VertexPair(vertex1, vertex2));
}

vector<pair<int, int>>::iterator DirectedGraph::parseEdges()
{
    return Collections.unmodifiableSet(edges.keySet());
}

DirectedGraph DirectedGraph::copy()
{
    DirectedGraph newGraph = new DirectedGraph();
    for (Integer vertex : inEdges.keySet())
    {
        newGraph.addVertex(vertex);
    }
    for (VertexPair edge : edges.keySet())
    {
        newGraph.addEdge(edge.getVertex1(), edge.getVertex2(), edges.get(edge));
    }
    return newGraph;
}


