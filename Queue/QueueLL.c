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
		printf("enqueue successful.\n");
	}
}

void dequeue(Queue *q){
	NodePtr temp;
	if(!isEmpty(*q)){
		temp = q->front;
		q->front = temp->next;
		free(temp);
		printf("dequeue successful.\n");
	}
}

int front(Queue q){
	return q.front->data;
}

int rear(Queue q){
	return q.rear->data;
}

bool isEmpty(Queue q){
	return q.front == NULL && q.rear == NULL;
}

void display(Queue q){
	NodePtr trav;
	
	for(trav = q.front; trav != NULL; trav = trav->next){
		printf("%d\n", trav->data);
	}
	printf("\n\n");
}







