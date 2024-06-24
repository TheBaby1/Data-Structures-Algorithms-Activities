#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "MainHeader.h"

void calculateFCFS(Queue *Q, float *totalTT, float *totalWT){
	
	int currentTime = 0;
	*totalTT = 0;
	*totalWT = 0;
	
	while (!isEmpty(Q)){
		Process P = deQueue(Q);
		
		if (currentTime < P.arrivalTime){
			currentTime = P.arrivalTime;
		}
		
		P.completionTime = currentTime + P.burstTime;
		P.turnAroundTime = P.completionTime - P.arrivalTime;
		P.waitingTime = P.turnAroundTime - P.burstTime;
		
		currentTime = P.completionTime;
		
		*totalTT += P.turnAroundTime;
		*totalWT += P.waitingTime;
		
		displayProcesses(P);
	}
}





