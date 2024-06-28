#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "OpenHashing.h"

void initializeDictionary(Dictionary *D, int size){
	
	int i;
	*D = malloc(size * sizeof(nodePtr));
	
	for (i = 0; i < size; i++){
		(*D)[i] = NULL;
	}
}

void visualizeDictionary(Dictionary D, int size){
	
	int i;
	nodePtr trav;
	
	printf("\nDictionary Visualization: \n\n");
	printf("SIZE = %d\n", size);
	for (i = 0; i < size; i++){
		printf("[ %d ]: ", i);
		for (trav = D[i]; trav != NULL; trav = trav->next){
			printf("%s", trav->champion);
			if (trav->next != NULL){
				printf("-->");
			}
		}
		printf("\n");
	}
	printf("\n");
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

void insertData(Dictionary *D, String champion, int *size, int *count){
	
	if ((float)(*count + 1) / *size > LOAD_FACTOR){
		reHash(D, size, count);
	}
	
	int key = hash(champion, *size);
	nodePtr *trav, temp;
	
	for (trav = &(*D)[key]; *trav != NULL && strcmp((*trav)->champion, champion) < 0; trav = &(*trav)->next){}
	
	if (*trav == NULL || strcmp((*trav)->champion, champion) != 0){
		
		temp = malloc(sizeof(Node));
		
		if (temp != NULL){
			strcpy(temp->champion, champion);
			temp->next = *trav;
			*trav = temp;
			(*count)++;
		}
	}
}

void reHash(Dictionary *D, int *size, int *count){
	
	int newSize = (*size * 2);
	Dictionary newD;
	initializeDictionary(&newD, newSize);
	int i;
	
	for (i = 0; i < *size; i++){
		
		nodePtr trav = (*D)[i];
		while (trav != NULL){
			nodePtr next = trav->next;
			int newIndex = hash(trav->champion, newSize);
			trav->next = newD[newIndex];
			newD[newIndex] = trav;
			trav = next;
		}
	}
	
	free(*D);
	*D = newD;
	*size = newSize;
}

void deleteMember(Dictionary D, String champion, int size){
	
	int key = hash(champion, size);
	nodePtr *trav, temp;
	
	for (trav = &D[key]; *trav != NULL && strcmp((*trav)->champion, champion) != 0; trav = &(*trav)->next){}
	
	if (*trav != NULL){
		temp = *trav;
		*trav = (*trav)->next;
		free(temp);
	}	
}

char *isMember(Dictionary D, String champion, int size){
	
	int key = hash(champion, size);
	nodePtr trav;
	
	for (trav = D[key]; trav != NULL && strcmp(trav->champion, champion) != 0; trav = trav->next){}
	
	return (trav != NULL) ? trav->champion : NULL;
}











