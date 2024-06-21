#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "SetHeader.h"

Set newSet(){
	
	int i;
	Set S;
	
	S.count = 0;
	for (i = 0; i < MAX; i++){
		S.elem[i] = 0;
	}
	
	return S;
}


void addElement(Set *S, int value){
	
	S->elem[value] = 1;
	S->count++;
}

void removeElement(Set *S, int value){
	
	S->elem[value] = 0;
	S->count--;
}

Set setUnion(Set A, Set B){
	
	Set unionSet = newSet();
	int i;
	
	for (i = 0; i < MAX; i++){
		if (A.elem[i] || B.elem[i]){
			addElement(&unionSet, i);
		}
	}
	
	return unionSet;
}

Set setIntersection(Set A, Set B){
	
	Set intersectionSet = newSet();
	int i; 
	
	for (i = 0; i < MAX; i++){
		if (A.elem[i] && B.elem[i]){
			addElement(&intersectionSet, i);
		}
	}
	
	return intersectionSet;
}


void displaySet(Set S){
	
	int i;
	
	for (i = 0; i < MAX; i++){
		if (S.elem[i]){
			printf("%d ", i);
		}
	}
	
	printf("\n");
}

void visualizeSet(Set S){
	
	int i;
	
	printf("%s %5s\n", "INDEX", "DATA");
	for (i = 0; i < MAX; i++){
		if (i < 10){
			printf("%d %8d\n", i, S.elem[i]);
		} else {
			printf("%d %7d\n", i, S.elem[i]);
		}
	}
	
	printf("\n");
}


