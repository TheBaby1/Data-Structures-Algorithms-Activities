#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "QueuesLinkedList.h"

int main(){
	
	Queue Q;
	
	initQueue(&Q);
	
	printf("Enqueue: \n");
	enQueue(&Q, 10);
	enQueue(&Q, 20);
	enQueue(&Q, 30);
	enQueue(&Q, 40);
	enQueue(&Q, 50);
	
	displayQueue(Q);
	
	int frontQueue = front(Q);
	printf("\nFRONT: %d\n", frontQueue);
	
	int rearQueue = rear(Q);
	printf("\nREAR: %d\n", rearQueue);
	
	printf("\nDequeueing 2 Times: \n");
	deQueue(&Q);
	deQueue(&Q);
	
	displayQueue(Q);
	
	frontQueue = front(Q);
	printf("\nFRONT: %d\n", frontQueue);
	
	rearQueue = rear(Q);
	printf("\nREAR: %d\n", rearQueue);
	
	return 0;
}
