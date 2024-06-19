#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "StackLL.h"

void initStackLL(StackLList *s){
	s->top = NULL;
}

StackLList createStackLL(){
	StackLList s;
	s.top = NULL;
	return s;
}

bool isEmpty(StackLList s){
	return (s.top == NULL);
}

bool stackLL_push(StackLList *s, int elem){
	NodePtr newNode = (NodePtr)malloc(sizeof(Node));
	
	if(newNode != NULL){
		newNode->data = elem;
		newNode->next = s->top;
		s->top = newNode;
	}
}

bool stackLL_pop(StackLList *s);
int stackLL_peek(StackLList s);

void display(StackLList s){
	
}

void visualize(StackLList s){
	NodePtr trav;
	
	for(trav = s.top; trav != NULL; trav = trav->next){
		printf("%d\n", trav->data);
	}
	printf("TOP is %d", trav->data);
}
