#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 10

typedef struct {
    char name[20];
    int idNum;
    int age;
} Info;

typedef struct node {
    Info studentInfo;
    struct node *next;
} Node, *nodePtr;

void insertFront(nodePtr *head, Info S);
void insertEnd(nodePtr *head, Info S);
void insertPosition(nodePtr *head, Info S, int pos);

void deleteFront(nodePtr *head);
void deleteEnd(nodePtr *head);
void deletePosition(nodePtr *head, int pos);

void displayList(nodePtr head);

int main(){

    nodePtr head = NULL;

    Info S = {"Nikko", 20101049, 23};
    Info S2 = {"Valerie", 20101046, 21};
    Info S3 = {"Marcelo", 24323432, 25};
    Info S4 = {"Dominic", 999999, 25};
    Info S5 = {"Kyran", 8888888, 22};
    Info S6 = {"Vincent", 77777777, 24};


    printf("Insert at Front: \n");
    insertFront(&head, S);
    insertFront(&head, S2);
    displayList(head);

    printf("Insert at End: \n");
    insertEnd(&head, S3);
    insertEnd(&head, S4);
    insertEnd(&head, S5);
    displayList(head);

    printf("Insert at Position 3: \n");
    insertPosition(&head, S6, 3);
    displayList(head);

    printf("Delete at Front: \n");
    deleteFront(&head);
    displayList(head);

    printf("Delete at End: \n");
    deleteEnd(&head);
    displayList(head);

    printf("Delete at Position 2: \n");
    deletePosition(&head, 2);
    displayList(head);

    return 0;
}

void insertFront(nodePtr *head, Info S){

    nodePtr newNode = malloc(sizeof(Node));

    if (newNode == NULL){
        printf("Memory Allocation Failed.\n");
    }

    newNode->studentInfo = S;
    newNode->next = *head;
    *head = newNode;
}

void insertEnd(nodePtr *head, Info S){

    nodePtr newNode = malloc(sizeof(Node));

    newNode->studentInfo = S;
    newNode->next = NULL;

    while (*head != NULL){
        head = &(*head)->next;
    }

    *head = newNode;
}

void insertPosition(nodePtr *head, Info S, int pos){

    nodePtr newNode = malloc(sizeof(Node));
    int count;
    nodePtr *current = head;

    newNode->studentInfo = S;

    for (count = 0; *current != NULL && count < pos; count++){
        current = &(*current)->next;
    }

    newNode->next = *current;
    *current = newNode;
}

void deleteFront(nodePtr *head){

    nodePtr temp = *head;

    if (*head == NULL){
        printf("List is Empty.\n");
    }

    *head = (*head)->next;
    free(temp);
}

void deleteEnd(nodePtr *head){

    nodePtr temp = *head;
    nodePtr prev;

    if (*head == NULL){
        printf("List is Empty.\n");
    }

    while (temp->next != NULL){
        prev = temp;
        temp = temp->next;
    }

    prev->next = NULL;
    free(temp);
}

void deletePosition(nodePtr *head, int pos){

    nodePtr temp = *head;
    nodePtr prev;
    int count;

    for (count = 0; temp->next != NULL && count < pos; count++){
        prev = temp;
        temp = temp->next;
    }

    prev->next = temp->next;
    free(temp);
}

void displayList(nodePtr head){

    while (head != NULL){
        printf("%10s %10d %5d\n", head->studentInfo.name, head->studentInfo.idNum, head->studentInfo.age);
        head = head->next;
    }
    printf("\n");
}
