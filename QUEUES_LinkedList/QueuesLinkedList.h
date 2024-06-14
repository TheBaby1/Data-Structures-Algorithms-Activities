#ifndef QUEUES_LINKEDLIST
#define QUEUES_LINKEDLIST

#include <stdbool.h>

typedef struct node {
	int data;
	struct node *next;
} Node, *nodePtr;

typedef struct {
	nodePtr front, rear;
} Queue;

void initQueue(Queue *Q);
void enQueue(Queue *Q, int data);
void deQueue(Queue *Q);

int front(Queue Q);
int rear(Queue Q);

bool isEmpty(Queue Q);

void displayQueue(Queue Q);


#endif
