#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#include "CircularArray.h"

void initializeQueue(CircularQ *Q){
	
	int i;
	
	Q->front = 1;
	Q->rear = 0;
	
	for (i = 0; i < MAX - 1; i++){
		Q->data[i] = EMPTY;
	}	
}

void enQueue(CircularQ *Q, int data){
	
	if (!isFull(Q)){
		Q->rear = (Q->rear + 1) % MAX;
		Q->data[Q->rear] = data;
	}
}

int deQueue(CircularQ *Q){
	
	int value;	
	
	if (!isEmpty(Q)){
		value = Q->data[Q->front];
		Q->data[Q->front] = EMPTY;
		Q->front = (Q->front + 1) % MAX;
	}
	
	return value;
}

bool isEmpty(CircularQ *Q){
	
	return (Q->rear + 1) % MAX == Q->front;
}

bool isFull(CircularQ *Q){
	
	return (Q->rear + 2) % MAX == Q->front;
}

void displayQueue(CircularQ *Q){

	int value;
	CircularQ temp;
	initializeQueue(&temp);
	
	printf("Display Queue: \n");
	while (!isEmpty(Q)){
		value = deQueue(Q);
		enQueue(&temp, value);
		printf("%d ", value);
	}
	printf("\n\n");
	
	while (!isEmpty(&temp)){
		value = deQueue(&temp);
		enQueue(Q, value);
	}	
}

void visualizeQueue(CircularQ Q){
	
	printf("Visualize Queue: \n");
    printf("%5s  %5s  %s\n", "INDEX", "VALUE", "POSITION");

	int i;

    for (i = 0; i < MAX; i++) {
        printf("%5d", i);

        if (Q.data[i] != EMPTY) {
            printf("%6d", Q.data[i]);
        } else {
            printf("%5s", " ");
        } 

        if (i == Q.front) {
            printf("    Front");
        }

        if (i == Q.rear) {
            printf("    Rear");
        }

        printf("\n");
    }

    printf("\n");
}
