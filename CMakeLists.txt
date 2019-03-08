cmake_minimum_required(VERSION 3.13)
project(Lab1Optional)

set(CMAKE_CXX_STANDARD 17)

add_executable(Lab1Optional main.cpp graphs/DirectedGraph.cpp graphs/DirectedGraph.h Controller.cpp Controller.h ConsoleUI.cpp ConsoleUI.h graphs/exceptions/FileNotFoundException.cpp graphs/exceptions/FileNotFoundException.h graphs/exceptions/VertexDoesNotExistException.h graphs/exceptions/VertexAlreadyExistsException.cpp graphs/exceptions/VertexAlreadyExistsException.h graphs/exceptions/EdgeDoesNotExistException.cpp graphs/exceptions/EdgeDoesNotExistException.h graphs/exceptions/EdgeAlreadyExistsException.cpp graphs/exceptions/EdgeAlreadyExistsException.h)