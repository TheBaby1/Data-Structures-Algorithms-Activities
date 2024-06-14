#ifndef STACK_LINKEDLIST
#define STACK_LINKEDLIST

#include <stdbool.h>

typedef struct node {
    int data;
    struct node *next;
} StackLinkedList;

void initStack(StackLinkedList **head);
StackLinkedList *createStack();
bool isEmpty(StackLinkedList *head);
void push(StackLinkedList **head, int elem);
void pop(StackLinkedList **head);
int peek(StackLinkedList *head);

void displayStack(StackLinkedList *head);
void visualizeStack(StackLinkedList *head);

StackLinkedList *getEven(StackLinkedList **head);

#endif
