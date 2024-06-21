#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include "Queue.h"

void initQueue(Queue *q){
	q->front = NULL;
	q->rear = NULL;	
}

void enqueue(Queue *q, int elem){
	NodePtr newNode = (NodePtr*)malloc(sizeof(Node));
	
	if(isEmpty(q)){
		front = *q;
		rear = *q;
	}else{
		rear = newNode;
	}
	if(newNode != NULL){
		newNode->data = elem;
		newNode->next = *q;
		*q = newNode;
	}
}

void dequeue(Queue *q);
int front(Queue q);
int rear(Queue q);
bool isEmpty(Queue q){
	return q.front == NULL && q.rear == NULL;
}
