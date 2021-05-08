#include <stdbool.h>

typedef float Weight; // Makes code less sensetive to variable typing 

typedef int nodeType; // Makes code less sensetive to variable typing

/* Describes Edge struct */

typedef struct Edge {
    nodeType node;
    struct Edge* next;
    Weight weight;
} Edge;

typedef Edge* Pointer;

/* Describes Graph struct. "*nodes" represents the adjacency list */

typedef struct {
    Pointer* nodes;
    int nodesNumber;
    int edgesNumber;
} Graph;

/* Initializes a new graph */

bool initialize(Graph* graph, int nodesNumber);

/* Prints a graph structure */

bool print(Graph *graph);

/* Checks if node nodeType validity */

bool nodeValid(Graph *graph, int node);

/* Checks if there's an edge between two nodes */

bool isConnected(Graph *graph, int fromNode, int toNode);

/* Inserts an edge */

void addEdge(Graph *graph, int firstNode, int secondNode, Weight weight);

/* Removes an edge */

bool removeEdge(Graph *graph, int firstNode, int secondNode);

/* Reinitializes an existent graph */

bool reinitialize(Graph *graph);

/* Check if a node has no neighbors */

bool noNeighbors(Graph *graph, int node);

/* Returns adjacent node nodeType relative to 'adjacentNode' nodeType */

Pointer nextNeighbor(Graph *graph, int node, Pointer adjacentNode);

/* Checks if there's a path between two nodes */

bool isReachable(Graph *graph, int fromNode, int toNode);

/* Checks if graph has cycles */

bool hasCycles(Graph *graph);

/* Returns node degree */

int nodeDegree(Graph* graph, int node);

/* Returns entry degree of node */

int entryDegree(Graph* graph, int node);

/* Returns exit degree of node */

int exitDegree(Graph* graph, int node);

/* Finds the shortest path between two nodes */

bool shortestPath(Graph* graph, int fromNode, int toNode);

/* Finds the minimum cost path between two nodes */

bool minimumPath(Graph* graph, int fromNode, int toNode);

int readGraph(char* filename, Graph* graph);