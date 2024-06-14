#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "StackLinkedList.h"

int main(){
    			
    StackLinkedList *head = createStack();
	
    push(&head, 32);
    push(&head, 22);
    push(&head, 13);
    push(&head, 65);
    push(&head, 324);
    push(&head, 235);
	
	printf("Display Stack: \n");
    displayStack(head);
    visualizeStack(head);
    
    StackLinkedList *newStack = getEven(&head);
    
    printf("Stack with Even Numbers:\n");
    displayStack(newStack);
    
    return 0;
}
