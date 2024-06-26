#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include "QUEUE_CPUSched.h"

void initProcQ(ProcQ *PQ){
	PQ->front = NULL;
	PQ->rear = NULL;
	PQ->count = 0;
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
	printf("number of processes: %d\n", Q.count);
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
		PQ->count++;
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
	ProcNodePtr trav;
	ProcNodePtr temp;
	int ctr = 0, x, total = 0;
	
	Process sort[PQ->count];
	
	for(trav = PQ->front, x = 0; trav != NULL; trav = trav->next, x++){
		sort[x] = trav->proc;
	}

	ProcQ sorted;
	initProcQ(&sorted);
	
	while(ctr != -1){
		for(x = 0; x < PQ->count; x++){
			if(sort[x].AT == ctr){
				enqueuePQ(&sorted, sort[x]);
				total++;
			}
		}
		if(total != PQ->count){
			ctr++;
		}else{
			ctr = -1;
		}
	}
	return sorted;
}

void CPU_FCFS(ProcQ *PQ){
	ProcNodePtr trav;
	int tempCT = 0;
	float tempAvgTT, tempAvgWT;
	
	for(trav = PQ->front; trav != NULL; trav = trav->next){
		tempCT += trav->proc.BT;
		trav->proc.CT = tempCT;
		trav->proc.TT = trav->proc.CT - trav->proc.AT;
		trav->proc.WT = trav->proc.TT - trav->proc.BT;
		PQ->avgTT += trav->proc.TT;
		PQ->avgWT += trav->proc.WT;
	}	
	PQ->avgTT /= PQ->count;
	PQ->avgWT /= PQ->count;
}

ProcQ display(ProcQ PQ){
	ProcQ temp = createPQ();
	Process p;
	printf("\n\nDISPLAY OF PROCESSES:\n");
	printf("Process %10s%10s%10s%10s%10s\n", "AT", "BT", "CT", "TT", "WT");
	while(!isEmpty(PQ)){
		p = PQ.front->proc;
		printf("%4c", p.procLetter);
		printf("%14d", p.AT);
		printf("%10d", p.BT);
		printf("%10d", p.CT);
		printf("%10d", p.TT);
		printf("%10d", p.WT);
		printf("\n");
		enqueuePQ(&temp, p);
		dequeuePQ(&PQ);
	}
	printf("\n\n");
	return temp;
}

void visualizePQ(ProcQ PQ){
	ProcNodePtr trav;
	
	printf("\n\nVISUALIZATION OF ELEMENTS:\n");
	printf("Process %10s%10s%10s%10s%10s\n", "AT", "BT", "CT", "TT", "WT");
	printf("-----------------------------------------------------------\n");
	for(trav = PQ.front; trav != NULL; trav = trav->next){
		printf("%4c", trav->proc.procLetter);
		printf("%14d", trav->proc.AT);
		printf("%10d", trav->proc.BT);
		printf("%10d", trav->proc.CT);
		printf("%10d", trav->proc.TT);
		printf("%10d", trav->proc.WT);
		printf("\n");
	}
	printf("%48.2f", PQ.avgTT);
	printf("%10.2f", PQ.avgWT);
	printf("\n\n");
}








