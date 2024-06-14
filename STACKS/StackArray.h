#ifndef STACK_ARRAY
#define STACK_ARRAY

#include <stdbool.h>

#define MAX 10

typedef struct {
	int data[MAX];
	int top;
} StackArrayList;

void initStack(StackArrayList *S);
StackArrayList createStack();

bool isEmpty(StackArrayList *S);
bool isFull(StackArrayList *S);

bool push(StackArrayList *S, int elem);
bool pop(StackArrayList *S);
int peek(StackArrayList S);

void display(StackArrayList S);
void visualize(StackArrayList S);

//create a function that would get all even numbers and return as a new stack removing from the old stack
StackArrayList getEven(StackArrayList *S);

#endif
