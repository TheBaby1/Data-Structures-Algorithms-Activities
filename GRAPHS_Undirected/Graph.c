#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "Graph.h"

void initializeGraph(int adjMatrix[SIZE][SIZE]){
	
	int i, j;
	
	for (i = 0; i < SIZE; i++){
		for (j = 0; j < SIZE; j++){
			adjMatrix[i][j] = 0;
		}
	}
}

void addEdge(int adjMatrix[SIZE][SIZE], int v1, int v2){

	adjMatrix[v1][v2] = 1;
	adjMatrix[v2][v1] = 1;
}

void displayMatrix(int adjMatrix[SIZE][SIZE]){
	
	printf("Adjacency Matrix: \n\n");
	
	int i, j;
	
	printf("   ");
    for (i = 0; i < SIZE; ++i) {
        printf("%c ", 'A' + i);
    }
    printf("\n");

    for (i = 0; i < SIZE; ++i) {
        printf("%c  ", 'A' + i);
        for (j = 0; j < SIZE; ++j) {
            printf("%d ", adjMatrix[i][j]);
        }
        printf("\n");
    }
} 



AdjListNode* newAdjListNode(enum Vertex dest){
	
	AdjListNode* newNode = (AdjListNode*) malloc(sizeof(AdjListNode));
    
    newNode->dest = dest;
    newNode->next = NULL;
    
    return newNode;
}

Graph* createGraph(int numVertices){
	
	Graph* graph = (Graph*) malloc(sizeof(Graph));
   
    graph->numVertices = numVertices;

    graph->array = (AdjList*) malloc(numVertices * sizeof(AdjList));
   
   	int i;
   
    for (i = 0; i < numVertices; ++i) {
        graph->array[i].head = NULL;
    }

    return graph;
}

void addEdgeList(Graph* graph, enum Vertex src, enum Vertex dest) {
    
    AdjListNode* current = graph->array[src].head;
    while (current != NULL) {
        if (current->dest == dest) {
            return;
        }
        current = current->next;
    }

    AdjListNode* newNode = newAdjListNode(dest);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;

    
    current = graph->array[dest].head;
    while (current != NULL) {
        if (current->dest == src) {
            return;
        }
        current = current->next;
    }

    newNode = newAdjListNode(src);
    newNode->next = graph->array[dest].head;
    graph->array[dest].head = newNode;
}


void freeGraph(Graph* graph){
	
	int i;
	
	if (graph != NULL) {
    	for (i = 0; i < graph->numVertices; ++i) {
            AdjListNode* current = graph->array[i].head;
            while (current != NULL) {
                AdjListNode* next = current->next;
                free(current);
                current = next;
            }
        }
        free(graph->array);
        free(graph);
    }
}

void displayList(Graph* graph){
	
	int i;
	
	printf("\nAdjacency List:\n\n");
    for (i = 0; i < graph->numVertices; ++i) {
        AdjListNode* temp = graph->array[i].head;
        printf("Vertex %c: ", 'A' + i);
        while (temp != NULL) {
            printf("%c ", 'A' + temp->dest);
            temp = temp->next;
        }
        printf("\n");
    }
}






