#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "MainHeader.h"


int main() {
	
	Queue Q;
	initializeQueue(&Q);
	float totalTT, totalWT;
	
	int processNum, i;
	
	printf("Enter Number of Processes: ");
	scanf("%d", &processNum);
	
	Process P[processNum];
	
	for (i = 0; i < processNum; i++){
		
		printf("Enter Process ID[char]: ");
		scanf(" %c", &P[i].proccessID);
		
		printf("Enter Arrival Time: ");
		scanf("%d", &P[i].arrivalTime);
		
		printf("Enter Burst Time: ");
		scanf("%d", &P[i].burstTime);
	}
	
	int size = sizeof(P) / sizeof(P[0]);
	int j;
	
	qsort(P, size, sizeof(Process), compareByArrivalTime);
	
	for (j = 0; j < size; j++){
		enQueue(&Q, P[j]);
	}
	
	
	printf("+---------+-------------+-----------+------------+-------------+----------------+\n");
    printf("| Process | ArrivalTime | BurstTime | Completion | WaitingTime | TurnAroundTime |\n");
    printf("+---------+-------------+-----------+------------+-------------+----------------+\n");

	calculateFCFS(&Q, &totalTT, &totalWT);

	printf("+---------+-------------+-----------+------------+-------------+----------------+\n");
    displaySummary(totalTT, totalWT, size);

	return 0;
}
