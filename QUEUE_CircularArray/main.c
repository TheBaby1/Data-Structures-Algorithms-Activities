#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "CircularArray.h"

int main() {
	
	CircularQ Q;
	
	initializeQueue(&Q);
	
	enQueue(&Q, 10);
	enQueue(&Q, 20);
	enQueue(&Q, 30);
	enQueue(&Q, 40);
	enQueue(&Q, 50);
	
	enQueue(&Q, 12);
	enQueue(&Q, 13);
	enQueue(&Q, 14);
	
	enQueue(&Q, 15);
	
	displayQueue(&Q);
	visualizeQueue(Q);
	
	return 0;
}
