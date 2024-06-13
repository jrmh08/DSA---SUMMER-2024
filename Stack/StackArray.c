#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include "StackArray.h"

void initStack(StackArrayList *s){
	s->top = -1;
}

StackArrayList createStack(){
	StackArrayList s;
	s.top = -1;
	return s;
}

bool isFull(StackArrayList s){
	return (s.top == MAX-1);
}

bool isEmpty(StackArrayList s){
	return (s.top == -1);
}

void stack_push(StackArrayList *s, int elem){
	if(isFull(*s) != 1){
		s->top++;
		s->data[s->top] = elem;
	}else{
		printf("Stack is full, can't push.'");
	}
}

void stack_pop(StackArrayList *s){
	if(isEmpty(*s) != 1){
		s->top--;
	}
}

int stack_peek(StackArrayList *s);

void display(StackArrayList s){
	
}

void visualize(StackArrayList s){
	int x;
	printf("%s  |  %s", "Index", "Value\n");
	for(x = 0; x < s.top + 1; x++){
		printf("%3d    |  %3d\n", x, s.data[x]);
	}
}
