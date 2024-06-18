#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "CircularArray.h"

int main(){
	
	
	CircularQ Q;
	initializeQueue(&Q);
	
	enQueue(&Q, 10);
	enQueue(&Q, 20);
	enQueue(&Q, 30);
	enQueue(&Q, 40);
	enQueue(&Q, 50);
	enQueue(&Q, 60);
	enQueue(&Q, 70);
	enQueue(&Q, 80);
	enQueue(&Q, 90);
	
	
	
	display(Q);
	
	visualize(Q);
	
	
	deQueue(&Q);
	deQueue(&Q);
	
	display(Q);
	
	visualize(Q);
	
	return 0;
}
