#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "StackArray.h"


int main() {
	
	StackArrayList S = createStack();
	
	push(&S, 21);
	push(&S, 25);
	push(&S, 16);
	push(&S, 23);
	push(&S, 99);
	push(&S, 86); 


	printf("DISPLAY: \n");
	display(S);
	
	
	printf("VISUALIZE: \n");
	visualize(S);
	
	// Creating a new stack of even numbers from old stack
	StackArrayList newStack = getEven(&S);
	
	printf("Even Numbers Stack: \n");
	display(newStack);
		
	return 0;
}
