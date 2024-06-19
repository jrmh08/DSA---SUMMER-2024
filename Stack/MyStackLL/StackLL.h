#ifndef STACK_LINKEDLIST
#define  STACK_LINKEDLIST

#include <stdbool.h>

typedef struct node{
	int data;
	struct node* next;
}Node, *NodePtr;

typedef struct{
	NodePtr top;
}StackLList;

void initStackLL(StackLList *s);
StackLList createStackLL();

bool isFull(StackLList s);
bool isEmpty(StackLList s);

bool stackLL_push(StackLList *s, int elem);
bool stackLL_pop(StackLList *s);
int stackLL_peek(StackLList s);

void display(StackLList s);
void visualize(StackLList s);

#endif
