#include <stdio.h>
#include <stdlib.h>

#include "OpenHashing.h"

int main(){
	
	Dictionary D;
	int size = INITIAL_SIZE;
	int count = 0;
	
	initializeDictionary(&D, size);
	
	insertData(&D, "Ashe", &size, &count);
    insertData(&D, "Zed", &size, &count);
    insertData(&D, "Yasuo", &size, &count);
    insertData(&D, "Fizz", &size, &count);
    insertData(&D, "Wukong", &size, &count);
    insertData(&D, "Nidalee", &size, &count);
    insertData(&D, "Lucian", &size, &count);
	
	visualizeDictionary(D, size);
	
	char *result = isMember(D, "Wukong", size);
	if (result != NULL){
		printf("%s is a member\n", result);
	} else {
		printf("Wukong is not member\n");
	}
	
	printf("\nDeleting Wukong from Dictionary\n");
	deleteMember(D, "Wukong", size);
	visualizeDictionary(D, size);
	
	char *result2 = isMember(D, "Wukong", size);
	if (result2 != NULL){
		printf("%s is a member\n", result2);
	} else {
		printf("Wukong is not member\n");
	}
	
	//Free memory
	int i;
	
	for (i = 0; i < size; i++){
        nodePtr trav = D[i];
        while (trav != NULL){
            nodePtr temp = trav;
            trav = trav->next;
            free(temp);
        }
    }
    free(D);
	
	
	return 0;
}
