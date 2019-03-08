#include <iostream>
#include "graphs/DirectedGraph.h"
#include "Controller.h"
#include "ConsoleUI.h"
#include "graphs/exceptions/FileNotFoundException.h"

DirectedGraph createDirectedGraphFromFile(const char string[15]);

using namespace std;

int main()
{
    DirectedGraph directedGraph;
    try
    {
        directedGraph = createDirectedGraphFromFile("graph.txt");
    } catch (FileNotFoundException e)
    {
        cout << "File was not found";
        directedGraph = DirectedGraph();
    }
    Controller controller(directedGraph);
    ConsoleUI consoleUI(controller);
    consoleUI.run();
    return 0;
}

DirectedGraph createDirectedGraphFromFile(const char *string)
{
    return DirectedGraph();
}

