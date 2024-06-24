#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "MainHeader.h"

void initializeQueue(Queue *Q){
	
	Q->front = Q->rear = NULL;
}

bool isEmpty(Queue *Q){
	
	return Q->front == NULL;
}

void enQueue(Queue *Q, Process P){
	
	nodePtr newNode = malloc(sizeof(Node));
	
	newNode->process = P;
	newNode->next = NULL;
	
	if (isEmpty(Q)){
		Q->front = Q->rear = newNode;
	} else {
		Q->rear->next = newNode;
		Q->rear = newNode;
	}
}

Process deQueue(Queue *Q){
	
	nodePtr temp = Q->front;
	Process P = temp->process;
	Q->front = Q->front->next;
	
	if (Q->front == NULL){
		Q->rear = NULL;
	}
	
	free(temp);
	return P;
}

int compareByArrivalTime(const void *a, const void *b){
	
    return ((Process *)a)->arrivalTime - ((Process *)b)->arrivalTime;
}

void displayProcesses(Process P){
	
	printf("| %7c | %11d | %9d | %10d | %11d | %14d |\n", 
           P.proccessID, P.arrivalTime, P.burstTime, P.completionTime, P.waitingTime, P.turnAroundTime);
}

void displaySummary(int totalTT, int totalWT, int count){
	
	float averageTT = (float)totalTT / count;
	float averageWT = (float)totalWT / count;
	
	printf("+---------+------------+----------+------------+------------+--------------+\n");
    printf("|         Total TT: %-54d |\n", totalTT);
    printf("|         Total WT: %-54d |\n", totalWT);
    printf("|         Average TT: %-52.2f |\n", averageTT);
    printf("|         Average WT: %-52.2f |\n", averageWT);
    printf("+---------+------------+----------+------------+------------+--------------+\n");
}

