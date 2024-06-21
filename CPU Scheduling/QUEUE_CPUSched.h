#ifndef QUEUE_CPUSCHED
#define QUEUE_CPUSCHED

#include<stdlib.h>

typedef struct{
	char procLetter;
	int AT;
	int BT;
	int CT;
	int TT;
	int WT;
}Process, *ProcessPtr;

typedef struct node{
	Process proc;
	struct node* next;
}ProcNode, ProcNodePtr;

typedef struct{
	ProcNode
};
