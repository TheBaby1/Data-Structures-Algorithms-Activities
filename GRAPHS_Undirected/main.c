#include <stdio.h>
#include <stdlib.h>

#include "Graph.h"

int main(){
	
	int adjMatrix[SIZE][SIZE];
	int num = SIZE;
	
	Graph *graph = createGraph(SIZE);
	
	initializeGraph(adjMatrix);
	
	addEdge(adjMatrix, A, B);
	addEdge(adjMatrix, A, C);
	addEdge(adjMatrix, A, D);
	
	addEdge(adjMatrix, B, A);
	addEdge(adjMatrix, B, C);
	addEdge(adjMatrix, B, D);
	addEdge(adjMatrix, B, E);
	
	addEdge(adjMatrix, C, A);
	addEdge(adjMatrix, C, B);
	addEdge(adjMatrix, C, D);
	
	addEdge(adjMatrix, D, A);
	addEdge(adjMatrix, D, B);
	addEdge(adjMatrix, D, C);
	addEdge(adjMatrix, D, E);
	
	addEdge(adjMatrix, E, B);
	addEdge(adjMatrix, E, D);
	
	
	displayMatrix(adjMatrix);
	
	
	addEdgeList(graph, A, B);
	addEdgeList(graph, A, C);
	addEdgeList(graph, A, D);
	
	addEdgeList(graph, B, A);
	addEdgeList(graph, B, C);
	addEdgeList(graph, B, D);
	addEdgeList(graph, B, E);
	
	addEdgeList(graph, C, A);
	addEdgeList(graph, C, B);
	addEdgeList(graph, C, D);
	
	addEdgeList(graph, D, A);
	addEdgeList(graph, D, B);
	addEdgeList(graph, D, C);
	addEdgeList(graph, D, E);
	
	addEdgeList(graph, E, B);
	addEdgeList(graph, E, D);
	
	displayList(graph);
	
	return 0;
}
