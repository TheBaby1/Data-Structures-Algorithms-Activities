#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "QueuesLinkedList.h"


void initQueue(Queue *Q){
	Q->front = Q->rear = NULL;
}

void enQueue(Queue *Q, int data){
	
	nodePtr newNode = malloc(sizeof(struct node));
	
	if (newNode != NULL){
		newNode->data = data;
		
		if (isEmpty(*Q)){
			Q->front = Q->rear = newNode;
		} else {
			Q->rear->next = newNode;
			Q->rear = newNode;
		}
	}
	
	Q->rear->next = NULL;
}

void deQueue(Queue *Q){
	
	nodePtr temp;
	
	if (!isEmpty(*Q)){
		temp = Q->front;
		Q->front = temp->next;
		free(temp);
	}
}

int front(Queue Q){
	
    return (Q.front != NULL) ? Q.front->data : 0;    
}

int rear(Queue Q){
	
    return (Q.rear != NULL) ? Q.rear->data : 0;
}


bool isEmpty(Queue Q){
	
	return (Q.front == NULL) ? 1 : 0;
}

void displayQueue(Queue Q){
	
	nodePtr trav;
	
	for (trav = Q.front; trav != NULL; trav = trav->next){
		printf("%d\n", trav->data);
	}
}


