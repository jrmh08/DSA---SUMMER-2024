#ifndef QUEUE_CPUSCHED
#define QUEUE_CPUSCHED

#include<stdbool.h>

typedef struct{
	char procLetter;            
	int AT;
	int BT;
	int CT;
	int TT;
	int WT;
	float avgTT;
	float avgWT;
}Process;

typedef struct node{
	Process proc;
	struct node* next;
}ProcNode, *ProcNodePtr;

typedef struct{
	ProcNodePtr front;
	ProcNodePtr rear;
	float avgTT;
	float avgWT;
	int count;
}ProcQ, *ProcQPtr;

void initProcQ(ProcQ *PQ);
bool isEmpty(ProcQ PQ);
ProcQ input();
void enqueuePQ(ProcQ *PQ, Process p);
void dequeuePQ(ProcQ *PQ);
ProcQ procSort(ProcQ *PQ);
void CPU_FCFS(ProcQ *PQ);
ProcQ display(ProcQ PQ);
void visualizePQ(ProcQ PQ);



#endif

