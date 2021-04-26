#include <stdio.h>
#include "graphlist.h"

/* Code test of graph library */

int main() {

    Graph graph;
    int verticeNumber = 5;

    initialize(&graph, verticeNumber);
    Graph *pointer = &graph;
    printf("Value %d", pointer->nodesNumber);
}