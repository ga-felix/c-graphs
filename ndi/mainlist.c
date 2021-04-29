#include <stdio.h>
#include "graphlist.h"

/* Code test of graph library */

int main() {

    Graph graph;
    int verticeNumber = 5;

    /*initialize(&graph, verticeNumber);
    Graph *pointer = &graph;
    addEdge(&graph, 3, 4, 5);
    addEdge(&graph, 3, 1, 4);
    removeEdge(&graph, 3, 1);
    print(&graph);*/
    char* filename = "grafo.txt";
    readGraph((char*) filename, &graph);
    print(&graph);
}