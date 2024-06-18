#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#include "CircularArray.h"

void initializeQueue(CircularQ *Q){
	
	int i;
	Q->front = 1;
	Q->rear = 0;
	
	for (i = 0; i < MAX; i++){
		Q->data[i] = EMPTY;
	}
}

void enQueue(CircularQ *Q, int value){
	
	if (!isFull(*Q)){
		Q->rear = (Q->rear + 1) % MAX;
		Q->data[Q->rear] = value;
	}
}

void deQueue(CircularQ *Q){
	
	if (!isEmpty(*Q)){
		Q->data[Q->front] = EMPTY;
		Q->front = (Q->front + 1) % MAX;
	}
}

int front(CircularQ Q){
	
	if (!isEmpty(Q)){
		return Q.data[Q.front];
	}
	
	return EMPTY;
}

bool isEmpty(CircularQ Q){
	
	return (Q.rear + 1) % MAX == Q.front;
}

bool isFull(CircularQ Q){
	
	return (Q.rear + 2) % MAX == Q.front;
}

void visualize(CircularQ Q){
	
	printf("Visualize Queue\n");
	printf("%5s  %5s  %s\n", "INDEX", "VALUE", "POSITION");
	
	int i;
	
	for (i = 0; i < MAX; i++){
		printf("%5d", i);
		
		if (Q.data[i] != EMPTY){
			printf("%6d", Q.data[i]);
		} else {
			printf("%5s", " ");
		} 
		
		if (i == Q.front){
			printf("    Front");
		}
		
		if (i == Q.rear){
			printf("    Rear");
		}
		
		printf("\n");
	}
	printf("\n");
}

void display(CircularQ Q){
	
	int i;
	
	printf("Display Queue: \n");
	for (i = 0; i < MAX; i++){
		if (Q.data[i] != EMPTY){
			printf("%d-->", Q.data[i]);
		}
	}
	printf("\n\n");
}

