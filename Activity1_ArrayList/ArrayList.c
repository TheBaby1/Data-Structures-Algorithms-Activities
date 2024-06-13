#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char fName[20];
	char lName[20];
} StudName;

typedef struct {
	int month;
	int year;
} Birthday;

typedef struct {
	StudName name;
	Birthday birthdate; 
	int age;
	int idNum;
} StudentInfo;

typedef struct {
	StudentInfo studArray[20];
	int studCount;
} ClassRecord;

void insertFront(ClassRecord *record, StudentInfo student);
void insertRear(ClassRecord *record, StudentInfo student);
void insertPosition(ClassRecord *record, StudentInfo student, int pos);
void insertSortAge(ClassRecord *record, StudentInfo student);


void deleteFront(ClassRecord *record);
void deleteRear(ClassRecord *record);
void deletePosition(ClassRecord *record, int pos);

void displayClass(ClassRecord *record);

int main() {
	
	ClassRecord class = {.studCount = 0};

	StudentInfo student1 = {{"Nikko", "Ensomo"}, {5, 2001}, 24, 1};
    StudentInfo student2 = {{"Marcelo", "Meneses"}, {7, 1999}, 25, 2};
    StudentInfo student3 = {{"Dominic", "Dagale"}, {12, 1989}, 22, 3};

	insertFront(&class, student1);
    insertRear(&class, student2);
    insertSortAge(&class, student3);
    
    printf("Class Record after insertions:\n");
    displayClass(&class);

    deleteFront(&class);
    printf("\nClass Record after deleting at front:\n");
    displayClass(&class);

    deleteRear(&class);
    printf("\nClass Record after deleting at rear:\n");
    displayClass(&class);

    insertRear(&class, student2);
    insertRear(&class, student1);
    deletePosition(&class, 1);
    printf("\nClass Record after deleting at position 1:\n");
    displayClass(&class);

	return 0;
}


void insertFront(ClassRecord *record, StudentInfo student){

	int i = 0;

	if (record->studCount >= 20){
		printf("Record is Full.\n");
	}

	for (i = record->studCount; i > 0; i--){
		record->studArray[i] = record->studArray[i - 1];
	}

	record->studArray[record->studCount] = student;
	record->studCount++;
}

void insertRear(ClassRecord *record, StudentInfo student){

	if (record->studCount >= 20){
		printf("Record is Full.\n");
	}

	record->studArray[record->studCount] = student;
	record->studCount++;
}

void insertPosition(ClassRecord *record, StudentInfo student, int pos){

	int i;

	if (record->studCount >= 20){
		printf("Record is Full.\n");
	}

	for (i = record->studCount; i > pos; i--){
		record->studArray[i] = record->studArray[i - 1];
	}

	record->studArray[record->studCount] = student;
	record->studCount++;
}

void insertSortAge(ClassRecord *record, StudentInfo student){

	int i = 0;

	if (record->studCount >= 20){
		printf("Record is Full.\n");
	}

	while (i < record->studCount && record->studArray[i].age <= student.age){
		i++;
	}

	insertPosition(record, student, i);
}

void deleteFront(ClassRecord *record){

	int i;

	if (record->studCount <= 0){
		printf("Record is Empty.\n");
	}

	for (i = 0; i < record->studCount - 1; i++){
		record->studArray[i] = record->studArray[i + 1];
	}

	record->studCount--;
}

void deleteRear(ClassRecord *record){

	if (record->studCount <= 0){
		printf("Record is Empty.\n");
	}

	record->studCount--;
}

void deletePosition(ClassRecord *record, int pos){

	int i;

	if (record->studCount <= 0){
		printf("Record is Empty.\n");
	}

	for (i = pos; i < record->studCount - 1; i++){
		record->studArray[i] = record->studArray[i + 1];
	}

	record->studCount--;
}

void displayClass(ClassRecord *record){

	int i;

	for (i = 0; i < record->studCount; i++){
		printf("Student %d: %s %s, Age: %d, ID: %d, Birthdate: %d/%d\n",
               i + 1,
               record->studArray[i].name.fName,
               record->studArray[i].name.lName,
               record->studArray[i].age,
               record->studArray[i].idNum,
               record->studArray[i].birthdate.month,
               record->studArray[i].birthdate.year);
	}
}