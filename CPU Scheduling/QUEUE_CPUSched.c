#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include "QUEUE_CPUSched.h"

void initProcQ(ProcQ *PQ){
	PQ->front = NULL;
	PQ->rear = NULL;
}

ProcQ createPQ(){
	ProcQ pq;
	pq.front = NULL;
	pq.front = NULL;
	return pq;
}

bool isEmpty(ProcQ PQ){
	return (PQ.front == NULL);
}

ProcQ input(){
	int size, x, AT, BT;
	char start = 'A', end = 'Z', ch;
	ProcQ Q;
	initProcQ(&Q);
	
	printf("Enter how many processes: ");
	scanf("%d", &size);
	
	Process input[size];
	
	for(x = 0, ch = start; x < size && ch <= end; x++, ch++){
		input[x].procLetter = ch;
		printf("Enter AT: ");
		scanf("%d", &input[x].AT);
		printf("Enter BT: ");
		scanf("%d", &input[x].BT);
		enqueuePQ(&Q, input[x]);
	}
	return Q;
}

void enqueuePQ(ProcQ *PQ, Process p){
	ProcNodePtr newNode = (ProcNodePtr)malloc(sizeof(ProcNode));
	
	if(newNode != NULL){
		newNode->proc = p;
		newNode->next = NULL;
		if(isEmpty(*PQ)){
			PQ->front = newNode;
			PQ->rear = newNode;
		}else{
			PQ->rear->next = newNode;
			PQ->rear = newNode;
		}
		printf("enqueue success!\n");
	}else{
		printf("enqueue failed!\n");
	}
}

void dequeuePQ(ProcQ *PQ){
	ProcNodePtr temp;
	
	if(!isEmpty(*PQ)){
		temp = PQ->front;
		PQ->front = PQ->front->next;
		free(temp);
		printf("dequeue success!\n");
	}else{
		printf("dequeue failed!\n");
	}
}

ProcQ procSort(ProcQ *PQ){
	Proc sorted = createPQ();
	ProcNodePtr trav = PQ->front;
	int ctr = 0;
	
	while(trav != NULL){
		while(PQ->front->proc.AT == ctr ){
			enqueuePQ(PQ, PQ->front->proc);
			trav = trav->next;
		}
		ctr++;
	}
}

void CPU_FCFS(ProcQ)

ProcQ display(ProcQ PQ){
	ProcQ temp = createPQ();
	Process p;
	
	while(!isEmpty(PQ)){
		p = PQ.front->proc;
		printf("Process %10c", p.procLetter);
		printf("%10d", p.AT);
		printf("%10d", p.BT);
		printf("\n");
		enqueuePQ(&temp, p);
		dequeuePQ(&PQ);
	}
	return temp;
}

void visualizePQ(ProcQ PQ){
	ProcNodePtr trav;
	
	printf("Process %10s%10s\n", "AT", "BT");
	for(trav = PQ.front; trav != NULL; trav = trav->next){
		printf("Process %10c", trav->proc.procLetter);
		printf("%10d", trav->proc.AT);
		printf("%10d", trav->proc.BT);
		printf("\n");
	}
}








