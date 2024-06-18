#ifndef CIRCULAR_ARRAY
#define CIRCULAR_ARRAY

#include <stdbool.h>

#define MAX 10
#define EMPTY 999

typedef char String[20];

typedef struct {
	int data[MAX];
	int front;
	int rear;
} CircularQ;

void initializeQueue(CircularQ *Q);
void enQueue(CircularQ *Q, int value);
void deQueue(CircularQ *Q);

int front(CircularQ Q);
bool isEmpty(CircularQ Q);
bool isFull(CircularQ Q);

void visualize(CircularQ Q);
void display(CircularQ Q);

#endif
