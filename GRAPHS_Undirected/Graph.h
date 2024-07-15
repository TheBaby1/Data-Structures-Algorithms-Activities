#ifndef UNDIRECTED_GRAPH
#define UNDIRECTED_GRAPH

#define SIZE 5

enum Vertex {
	A, B, C, D, E
};

typedef struct AdjListNode {
	enum Vertex dest;
	struct AdjListNode *next;
} AdjListNode;

typedef struct AdjList {
	AdjListNode *head;
} AdjList;

typedef struct Graph {
	int numVertices;
	AdjList *array;
} Graph;

void initializeGraph(int adjMatrix[SIZE][SIZE]);
void addEdge(int adjMatrix[SIZE][SIZE], int v1, int v2);
void displayMatrix(int adjMatrix[SIZE][SIZE]);

AdjListNode* newAdjListNode(enum Vertex dest);
Graph* createGraph(int numVertices);
void addEdgeList(Graph* graph, enum Vertex src, enum Vertex dest);
void freeGraph(Graph* graph);
void displayList(Graph* graph);


#endif
