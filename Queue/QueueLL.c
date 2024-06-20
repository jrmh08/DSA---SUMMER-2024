#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include "QueueLL.h"

void initQueue(Queue *q){
	q->front = NULL;
	q->rear = NULL;	
}

void enqueue(Queue *q, int elem){
	NodePtr newNode = (NodePtr)malloc(sizeof(Node));
	
	if(newNode != NULL){
		newNode->data = elem;
		newNode->next = q->front;
		if(isEmpty(*q)){
			q->front = newNode;
			q->rear = newNode;
		}else{
			q->front = newNode;
		}
		printf("enqueueing %d success.\n", elem);
	}else{
		printf("enqueueing failed.\n");
	}
}

void dequeue(Queue *q){
	NodePtr temp;
	
	if(!isEmpty(*q)){
		temp = q->front;
		q->front = temp->next;
		printf("dequeueing %d success.\n", temp->data);
		free(temp);
	}else{
		printf("dequeueing failed.");
	}
}

int front(Queue q){
	return q.front->data;
}

int rear(Queue q){
	return q.rear->data;
}

bool isEmpty(Queue q){
	return (q.rear == NULL);
}

Queue display(Queue q){
	int elem;
	Queue *newQueue = (Queue*)malloc(sizeof(Queue));
	
	while(!isEmpty(q)){
		elem = q.front->data;
		printf("%d\n", elem);
		enqueue(newQueue, elem);
		dequeue(&q);
	}
	printf("\n\n");
	return *newQueue;
}

void visualize(Queue q){
	NodePtr trav;
	
	for(trav = q.front; trav != NULL; trav = trav->next){
		printf("%d\n", trav->data);
	}
}
