#include <stdio.h>
#include<stdbool.h>
#include "QueueArray.h"

void initArrQueue(CircularQ *q){
	q->front = 0;
	q->rear = -1;
}

void enqueue(CircularQ *q, int elem){
	if(!isFull(*q)){
		q->rear = (q->rear + 1) % MAX;
		q->data[q->rear] = elem;
		printf("enqueue elem %d success\n", elem);
	}else{
		printf("enqueue failed. Queue is full\n");
	}
}

void dequeue(CircularQ *q){
	if(!isEmpty(*q)){
		printf("dequeue elem %d success\n", q->data[q->front]);
		q->front = (q->front + 1) % MAX;
	}else{
		printf("dequeue failed\n");
	}
}

int front(CircularQ q){
	return q.front;
}

int rear(CircularQ q){
	return q.rear;
}

bool isEmpty(CircularQ q){
	return ((q.rear + 1) % MAX == q.front);
}
bool isFull(CircularQ q){
	return ((q.rear + 2) % MAX == q.front);
}

void display(CircularQ q) {
    int x, ctr = 0;

    if (isEmpty(q)) {
        printf("Queue is empty\n");
    }else{
    	printf("Elements in the queue:\n");
    
	    for(x = q.front; x != q.rear; x = (x + 1) % MAX, ctr++){
	    	printf("%d\n", q.data[x]);
		}
	    // Print the last element
	    printf("%d\n", q.data[x]);
	    ctr++;
	}

    printf("The number of elements in the queue are: %d\n", ctr);
}
