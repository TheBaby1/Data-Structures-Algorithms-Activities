#ifndef CIRCULAR_ARRAY
#define CIRCULAR_ARRAY

#include <stdbool.h>

#define MAX 10
#define EMPTY 999

typedef struct {
	int data[MAX];
	int front;
	int rear;
} CircularQ;

void initializeQueue(CircularQ *Q);
void enQueue(CircularQ *Q, int data);
int deQueue(CircularQ *Q);

bool isEmpty(CircularQ *Q);
bool isFull(CircularQ *Q);

void displayQueue(CircularQ *Q);
void visualizeQueue(CircularQ Q);

#endif
