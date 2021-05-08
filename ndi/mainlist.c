#include <stdio.h>
#include "graphlist.h"

/* Code test of graph library */

int main() {

    Graph graph;
    readGraph("grafo.txt", &graph);
    print(&graph);
}