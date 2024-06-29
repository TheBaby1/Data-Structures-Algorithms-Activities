#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ClosedHashing.h"


int main(){
	
	int size = INITIAL_SIZE;
	int count = 0;
	Dictionary D = malloc(size * sizeof(String));
	initializeDictionary(D, size);
	
	insertData(&D, "Lux", &size, &count);
    insertData(&D, "Sylas", &size, &count);
    insertData(&D, "Yasuo", &size, &count);
    insertData(&D, "Fizz", &size, &count);
    insertData(&D, "Wukong", &size, &count);
    insertData(&D, "Tryndamere", &size, &count);
    
    displayDictionary(D, size);
    
    printf("Is Yasuo in the Dictionary? %s\n", isMember(D, "Yasuo", size) ? "Yes" : "No");
    
    deleteData(&D, "Wukong", &size, &count);
	
	printf("\n\nAfter Deleting Wukong and Inserting 5 New Champions: \n\n");
	
	insertData(&D, "Pantheon", &size, &count);
    insertData(&D, "Diana", &size, &count);
    insertData(&D, "Tristana", &size, &count);
    insertData(&D, "Darius", &size, &count);
    insertData(&D, "Gangplank", &size, &count);
    
	displayDictionary(D, size);
	
	return 0;
}
