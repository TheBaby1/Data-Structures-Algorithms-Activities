#ifndef SETS_ACTIVITY
#define SETS_ACTIVITY

#include <stdbool.h>

#define MAX 15

typedef struct {
	bool elem[MAX];
	int count;
} Set;

Set newSet();

void addElement(Set *S, int value);
void removeElement(Set *S, int value);

Set setUnion(Set A, Set B);
Set setIntersection(Set A, Set B);
Set setDifference(Set A, Set B);

void displaySet(Set S);
void visualizeSet(Set S);



#endif
