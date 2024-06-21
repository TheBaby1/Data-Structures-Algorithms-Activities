#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "SetHeader.h"

int main(){
	
	Set unionSet, intersectionSet;
	
	Set A = newSet();
	Set B = newSet();
	
	addElement(&A, 1);
	addElement(&A, 2);
	addElement(&A, 3);
	addElement(&A, 4);
	addElement(&A, 5);
	addElement(&A, 7);

	
    addElement(&B, 2);
	addElement(&B, 4);
	addElement(&B, 6);
	addElement(&B, 8);
	addElement(&B, 10);
	addElement(&B, 12);
	
	
	printf("Set A: \n");
	displaySet(A);
	
	printf("\nSet B: \n");
	displaySet(B);
	
	
	intersectionSet = setIntersection(A, B);
	unionSet = setUnion(A, B);
	
	printf("\nIntersection of Set A and Set B: \n");
	displaySet(intersectionSet);
	
	printf("\nUnion of Set A and Set B: \n");
	displaySet(unionSet);
	
	printf("\nRemoving elements 4 and 7 in Set A: \n");
	removeElement(&A, 4);
	removeElement(&A, 7);
	displaySet(A);
	
	printf("\nVisualization of Set A: \n");
	visualizeSet(A);
	
	return 0;
}
