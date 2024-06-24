#ifndef CPU_SCHEDULING
#define CPU_SCHEDULING

#include <stdbool.h>

typedef struct {
	char proccessID;
	int arrivalTime;
	int burstTime;
	int completionTime;
	int waitingTime;
	int turnAroundTime;
} Process;

typedef struct node {
	Process process;
	struct node *next;
} Node, *nodePtr;

typedef struct {
	nodePtr front;
	nodePtr rear;
} Queue;

void initializeQueue(Queue *Q);
bool isEmpty(Queue *Q);
void enQueue(Queue *Q, Process P);
Process deQueue(Queue *Q);
int compareByArrivalTime(const void *a, const void *b);

//FCFS function prototypes
void calculateFCFS(Queue *Q, float *totalTT, float *totalWT);

//PRINT/DISPLAY function prototypes
void displayProcesses(Process P);
void displaySummary(int totalTT, int totalWT, int count);

#endif
