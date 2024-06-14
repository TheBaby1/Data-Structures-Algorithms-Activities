#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "StackLinkedList.h"

void initStack(StackLinkedList **head){

    *head = NULL;
}

StackLinkedList *createStack(){
	
	StackLinkedList *head;
	
	initStack(&head);
	
	return head;
}

bool isEmpty(StackLinkedList *head){

    return (head == NULL);
}

void push(StackLinkedList **head, int elem){

    StackLinkedList *current = malloc(sizeof(struct node));

    if (isEmpty(*head)){
        current->data = elem;
        current->next = NULL;
        *head = current;
    } else {
    	current->data = elem;
    	current->next = *head;
    	*head = current;
	}
}

void pop(StackLinkedList **head){

    StackLinkedList *temp;

    if (isEmpty(*head)){
        printf("Stack is Empty.\n");
    } else {
    	temp = *head;
    	*head = (*head)->next;
    	free(temp);
	}
	
}


int peek(StackLinkedList *head){

    StackLinkedList *current = head;

    if (isEmpty(head)){
        printf("Stack is Empty.\n");
    }

    return current->data;
}

void displayStack(StackLinkedList *head){

    StackLinkedList *newStack;
    initStack(&newStack);

    while (!isEmpty(head)){
        int top = peek(head);
        push(&newStack, top);
        pop(&head);
    }

    printf("Elements: \n");
    while (!isEmpty(newStack)){
        int top = peek(newStack);
        printf("%5d \n", top);
        push(&head, top);
        pop(&newStack);
    }
    
    printf("\n");
}

void visualizeStack(StackLinkedList *head){

    StackLinkedList *current = head;
	int top = peek(head);

    printf("Visualize Stack: \n");
    printf("Elements: \n");
    while (current != NULL){
        printf("%5d ", current->data);
        if (current->data == top){
        	printf("%s", "<--- Top");
		}
        current = current->next;
        
        printf("\n");
    }

    printf("\n");
}

StackLinkedList *getEven(StackLinkedList **head) {
    
    StackLinkedList *tempStack = createStack();
    StackLinkedList *newStack = createStack();
	    
    while (!isEmpty(*head)) {
        int top = peek(*head);
        pop(head);
        
        if (top % 2 == 0) {
            push(&newStack, top);
        } else {
            push(&tempStack, top);
        }
    }
    
    while (!isEmpty(tempStack)) {
        push(head, peek(tempStack));
        pop(&tempStack);
    }
    
    return newStack;
}


