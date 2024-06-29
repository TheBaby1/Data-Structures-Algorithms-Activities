#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "ClosedHashing.h"

void initializeDictionary(Dictionary D, int size){
	
	int i;
	
	for (i = 0; i < size; i++){
		D[i][0] = EMPTY;
	}
}

void insertData(Dictionary *D, String champion, int *size, int *count){
	
	if ((double)(*count) / (*size) > LOAD_FACTOR) {
        reHash(D, size, count);
    }

    int key = hash(champion, *size);
    int index = key;

    while ((*D)[index][0] != EMPTY){
        index = (index + 1) % *size; 
    }

    strcpy((*D)[index], champion); 
    (*count)++; 
}

void deleteData(Dictionary *D, String champion, int *size, int *count){
	
	int key = hash(champion, *size);
    int index = key;

    while ((*D)[index][0] != EMPTY){
        if (strcmp((*D)[index], champion) == 0){
            (*D)[index][0] = EMPTY; 
            (*count)--; 
            return;
        }
        
        index = (index + 1) % *size; 
        if (index == key){ 
            break;
        }
    }

    printf("%s not found in Dictionary\n", champion);
}

int hash(String champion, int size){
	
	unsigned long int hash = 0;
	unsigned int seed = 131;
	int i;
	
	for (i = 0; champion[i] != '\0'; i++){
		hash = hash * seed + (unsigned)champion[i];
	}
	
	return hash % size;
}

void reHash(Dictionary *D, int *size, int *count){
	
	int newSize = (*size) * 2;
    Dictionary newD = malloc(newSize * sizeof(String));
    int i;
    
    for (i = 0; i < newSize; i++){
        newD[i][0] = EMPTY;
    }
    
    for (i = 0; i < *size; i++){
        if ((*D)[i][0] != EMPTY){
            String champion;
            strcpy(champion, (*D)[i]);
            int newIndex = hash(champion, newSize);
            
            while (newD[newIndex][0] != EMPTY){
                newIndex = (newIndex + 1) % newSize; 
            }
            strcpy(newD[newIndex], champion);
        }
    }

    free(*D);
    *D = newD;
    *size = newSize;
}

bool isMember(Dictionary D, String champion, int size){
	
	int key = hash(champion, size);
	int index = key;
	
	while (D[index][0] != EMPTY){
		if (strcmp(D[index], champion) == 0){
			return true;
		}
		
		index = (index + 1) % size;
		if (index == key){
			break;
		}
	}
	
	return false;
}

void displayDictionary(Dictionary D, int size){
	
	int i;
	
	printf("Dictionary Visualization: \n");
	printf("Dictionary Size: %d\n\n", size);
	
	for (i = 0; i < size; i++){
		if (D[i][0] != EMPTY){
			printf("Index %d: %s\n", i, D[i]);
		} else {
			printf("Index %d:  \n", i);
		}
	}
	
	printf("\n");
}
















