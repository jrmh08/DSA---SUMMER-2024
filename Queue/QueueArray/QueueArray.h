#ifndef QUEUE_ARRAY
#define QUEUE_ARRAY

#include <stdbool.h>

#define MAX 10

typedef struct node{
	int data[MAX];
	int front;
	int rear;
}CircularQ;

void initArrQueue(CircularQ *q);
void enqueue(CircularQ *q, int elem);
void dequeue(CircularQ *q);
int front(CircularQ q);
int rear(CircularQ q);
bool isEmpty(CircularQ q);
bool isFull(CircularQ q);
void display(CircularQ q);

#endif
