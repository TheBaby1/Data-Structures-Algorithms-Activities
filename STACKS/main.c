#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "StackArray.h"


int main() {
	
	StackArrayList S;
	
	initStack(&S);
	
	push(&S, 10);
	push(&S, 20);
	push(&S, 30);


	printf("DISPLAY: \n");
	display(S);
	
	
	printf("VISUALIZE: \n");
	visualize(S);
		
	return 0;
}
