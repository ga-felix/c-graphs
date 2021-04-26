#include <stdio.h>
#include <stdlib.h>
#include "graphlist.h"

/* Verifies if node value can exist in graph */

bool nodeValid(Graph *graph, int node) {
    return (graph->nodesNumber > node && 0 < node);
}

/* Initializes a new graph, setting all fields to empty default value */

bool initialize(Graph* graph, int nodesNumber) {

    if(nodesNumber <= 0) {
        fprintf(stderr, "[ERROR] node's number is negative or zero %d\n", nodesNumber);
        return false;
    }
    
    if(!(graph->nodes = (Pointer*) calloc(nodesNumber + 1, sizeof(Pointer)))) {
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

/* Returns header from adjancecy list of node */
Pointer getHeader(Graph *graph, int node) {
    return graph->nodes[node];
}

/* Returns adjacent node nodeType relative to 'adjacentNode' nodeType */

Pointer nextNeighbor(Graph *graph, int node, Pointer adjacentNode) {
    
    if(!nodeValid(graph, node) || !nodeValid(graph, adjacentNode->node)) {
        fprintf(stderr, "[ERROR] node's value out of bounds %d or %d\n", node, adjacentNode->node);
        return NULL;
    }

    if(!graph->nodes[node]) {
        fprintf(stderr, "[ERROR] node is not assigned %d\n", node);
        return NULL;
    }


}

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
    new->next = graph->nodes[fromNode];
    graph->nodes[fromNode] = new;
    graph->edgesNumber++;

}

bool isConnected(Graph *graph, int fromNode, int toNode) {
    Pointer edge = graph->nodes[fromNode];

    while(edge) {
        if(edge->node == toNode) return true;
        edge = edge->next;
    }

    return false;
}

bool removeEdge(Graph *graph, int fromNode, int toNode) {

    if(!nodeValid(graph, fromNode) || !nodeValid(graph, toNode)) {
        fprintf(stderr, "[ERROR] node's value out of bounds %d or %d\n", fromNode, toNode);
        return false;
    }

    Pointer edge = graph->nodes[fromNode];
    Pointer beforeEdge = graph->nodes[fromNode];

    while(edge) {
        if(edge->node == toNode) break;
        beforeEdge = edge;
        edge = edge->next;
    }

    if(edge == graph->nodes[fromNode]) {

    }

    beforeEdge->next = edge->next;
    edge->next = NULL;
    free(edge);
    edge = NULL;
    graph->edgesNumber--;

}