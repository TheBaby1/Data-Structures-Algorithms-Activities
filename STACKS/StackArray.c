#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#include "StackArray.h"

void initStack(StackArrayList *S){
	
	S->top = -1;
 }

StackArrayList createStack(){
	
	StackArrayList S;
	
	initStack(&S);
	return S;
}

bool isEmpty(StackArrayList *S){
	
	return S->top == -1;
}

bool isFull(StackArrayList *S){
	
	return S->top == MAX - 1;
}

bool push(StackArrayList *S, int elem){
	
	if (isFull(S)){
		printf("Stack Overflow.\n");
		return false;
	}
	S->data[++S->top] = elem;
	return true;
}

bool pop(StackArrayList *S){
	
	if (isEmpty(S)){
		printf("Stack Underflow.\n");
		return false;
	}
	S->top--;
	return true;
}

int peek(StackArrayList S){
	
	if (isEmpty(&S)){
		printf("Stack is Empty.\n");
		return -1;
	}
	
	return S.data[S.top];
}

void display(StackArrayList S){
	
	StackArrayList newStack;
	
	initStack(&newStack);
	
	while (!isEmpty(&S)){
		push(&newStack, peek(S));
		pop(&S);
	}
	
	while (!isEmpty(&newStack)){
		printf("%d \n", peek(newStack));
		pop(&newStack);
	}
	
	printf("\n");
}


void visualize(StackArrayList S){
	
	int i;
	
	if (isEmpty(&S)){
		printf("Stack is Empty.\n");
	}
	
	for (i = S.top; i >= 0; i--){
		printf("%d %d", S.data[i], i);
		if (S.data[i] != S.top){
			printf("%4s \n", "<-- top");
		} 
	}
	
	printf("\n");
}















