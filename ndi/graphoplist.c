#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "graphlist.h"


/* Verifies if node value can exist in graph O(1) */

bool nodeValid(Graph *graph, int node) {
    return (graph->nodesNumber > node && 0 <= node);
}

/* Initializes a new graph, setting all fields to empty default value O(n) */

bool initialize(Graph* graph, int nodesNumber) {

    if(nodesNumber <= 0) {
        fprintf(stderr, "[ERROR] node's number is negative or zero %d\n", nodesNumber);
        return false;
    }
    
    if(!(graph->nodes = (Pointer*) calloc(nodesNumber, sizeof(Pointer)))) {
        fprintf(stderr, "[ERROR] calloc operation failed: memory is full\n");
        return false;
    }

    graph->nodesNumber = nodesNumber; // Signs the number of nodes
    graph->edgesNumber = 0;
    return true;
}

/* Check if a node has no neighbors O(1) */

bool noNeighbors(Graph *graph, int node) {

    if(!nodeValid(graph, node)) {
        fprintf(stderr, "[ERROR] node's value out of bounds %d\n", node);
        return false;
    }

    return (!graph->nodes[node]);

}

/* Returns header from adjancecy list of node O(1) */
Pointer getHeader(Graph *graph, int node) {
    return graph->nodes[node];
}

/* Returns adjacent node nodeType relative to 'adjacentNode' nodeType O(1) */

Pointer nextNeighbor(Graph *graph, int node, Pointer adjacentNode) {
    
    if(!nodeValid(graph, node) || !nodeValid(graph, adjacentNode->node)) {
        fprintf(stderr, "[ERROR] node's value out of bounds %d or %d\n", node, adjacentNode->node);
        return NULL;
    }

    if(!graph->nodes[node]) {
        fprintf(stderr, "[ERROR] node is not assigned %d\n", node);
        return NULL;
    }

    return adjacentNode->next;

}

/* Insert a new edge O(1) */

void addEdge(Graph *graph, int fromNode, int toNode, Weight weight) {

    if(!nodeValid(graph, fromNode) || !nodeValid(graph, toNode)) {
        fprintf(stderr, "[ERROR] node's value out of bounds %d or %d\n", fromNode, toNode);
        return;
    }

    Pointer new;
    if(!(new = (Pointer) calloc(1, sizeof(Pointer)))) {
        fprintf(stderr, "[ERROR] calloc operation failed: memory is full\n");
        return;
    }

    new->node = toNode;
    new->weight = weight;
    new->next = graph->nodes[fromNode]; // Inserts on head, so it's faster
    graph->nodes[fromNode] = new;
    graph->edgesNumber++;

}

/* Checks if there's an edge betweetn two given nodes O(n) */

bool isConnected(Graph *graph, int fromNode, int toNode) {
    
    Pointer edge = graph->nodes[fromNode];
    while(edge) {
        if(edge->node == toNode) return true;
        edge = edge->next;
    }

    return false;
}

/* Removes an edge between two given nodes. O(n) */

bool removeEdge(Graph *graph, int fromNode, int toNode) {

    if(!nodeValid(graph, fromNode) || !nodeValid(graph, toNode)) {
        fprintf(stderr, "[REMOVE-EDGE] node's value out of bounds %d or %d\n", fromNode, toNode);
        return false;
    }

    Pointer edge = graph->nodes[fromNode];
    Pointer beforeEdge = graph->nodes[fromNode];

    while(edge && edge->node != toNode) {
        beforeEdge = edge;
        edge = edge->next;
    }

    if(!edge) {
        fprintf(stderr, "[REMOVE-EDGE] connection doesn't exist between %d and %d\n", fromNode, toNode);
        return false;
    }

    if(edge == graph->nodes[fromNode]) {
        graph->nodes[fromNode] = edge->next;
    } else {
        beforeEdge->next = edge->next;
    }

    edge->next = NULL;
    free(edge);
    edge = NULL;
    graph->edgesNumber--;
    return true;

}

/* Prints graph O(v + a) */

bool print(Graph *graph) {

    if(graph->nodesNumber == 0) {
        fprintf(stderr, "[PRINT] Cannot print an empty graph\n");
        return false;
    }

    for(int index = 0; index < graph->nodesNumber; index++) {
        fprintf(stdout, "[PRINT] Node %d\nConnections: ", index);
        Pointer edge = graph->nodes[index];
        while(edge) {
            fprintf(stdout, "%d (weight %lf), ", edge->node, edge->weight);
            edge = edge->next;
        }

        fprintf(stdout, "\n");
    }

    return true;
}

/* Read input from file */

int readGraph(char* fileName, Graph* graph) {
    FILE* filePointer;
    int bufferLength = 255;
    int nodes, edges;
    char buffer[bufferLength];

    filePointer = fopen(fileName, "r");
    if(!filePointer) {
        fprintf(stderr, "[READ-GRAPH] Unable to open file");
        return(0);
    }

    if(fscanf(filePointer, "%d %d", &nodes, &edges) != 2)
        return (0);
    initialize(graph, nodes);

    int fromNode, toNode;
    Weight weight;
    while((fscanf(filePointer, "%d %d %f", &fromNode, &toNode, &weight)) != EOF) {
        printf("fromNode value %d toNode value %d weight value %f\n", fromNode, toNode, weight);
        addEdge(graph, fromNode, toNode, weight);
    }

    fclose(filePointer);
    return (1);
}