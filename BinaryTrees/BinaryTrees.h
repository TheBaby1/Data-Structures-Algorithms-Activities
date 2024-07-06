#ifndef BINARY_TREES
#define BINARY_TREES

#include <stdbool.h>

#define STRING_SIZE 50

typedef struct {
	int day;
	int month;
	int year;
} Date;

typedef struct {
	char prodName[STRING_SIZE];
	float prodPrice;
	int prodQty;
	Date expDate;
} Product;

typedef struct node {
	Product item;
	struct node *left;
	struct node *right;
} NodeType, *NodePtr;

typedef struct QueueNode {
	NodePtr treeNode;
	struct QueueNode *next;
} QueueNode;

typedef struct {
	QueueNode *front;
	QueueNode *rear;
} Queue;

void addNode(NodePtr *list, Product item);
void deleteNode(NodePtr *list, Product item);

void inorderBST(NodePtr list);
void preorderBST(NodePtr list);
void postorderBST(NodePtr list);
void breadthFirstSearchBST(NodePtr root);

bool isEmpty(NodePtr list);
void initializeTree(NodePtr *list);

Date createDate(int day, int month, int year);
Product createProduct(char *prodName, float prodPrice, int prodQty, Date expDate);
void displayProduct(Product item);

void initializeQueue(Queue *Q);
bool isQueueEmpty(Queue *Q);
void enQueue(Queue *Q, NodePtr treeNode);
NodePtr deQueue(Queue *Q);



#endif
