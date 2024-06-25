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
		newNode->next = NULL;
		if(isEmpty(*q)){
			q->front = newNode;
			q->rear = newNode;
		}else{
            q->rear->next = newNode;
			q->rear = newNode;
		}
		printf("enqueue success!\n");
	}else{
		printf("enqueue failed!\n");
	}
}

void dequeue(Queue *q){
	NodePtr temp;
	
	if(!isEmpty(*q)){
		temp = q->front;
		q->front = q->front->next;
		free(temp);
		printf("dequeue success!\n");
	}else{
		printf("dequeue failed!\n");
	}
}

int front(Queue q);

int rear(Queue q);

bool isEmpty(Queue q){
	return (q.front == NULL);
}

Queue display(Queue q){
	Queue newQ;
	initQueue(&newQ);
	
	while(!isEmpty(q)){
		printf("%d\n", q.front->data);
		enqueue(&newQ, q.front->data);
		dequeue(&q);
	}
	return newQ;
}

void visualize(Queue q){
	NodePtr trav;
	
	for(trav = q.front; trav != NULL; trav = trav->next){
		printf("%d", trav->data);
		if(trav == q.front){
			printf(" <-- front");
		}
		printf("\n");
	}
}
