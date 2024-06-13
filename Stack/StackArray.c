#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include "StackArray.h"

void initStack(StackArrayList *s){
	s->top = -1;
}

StackArrayList createStack(){
	StackArrayList s;
	return s.top = -1;
}

bool isFull(StackArrayList s){
	return (s.top == MAX-1);
}

bool isEmpty(StackArrayList s){
	return (s.top == -1);
}

bool stack_push(StackArrayList *s, int elem){
	bool push = false;
	if(isFull(s)){
		s->top++;
		s->data[s->top] = elem;
		push = true;
	}
	return push;
}

bool stack_pop(StackArrayList *s, int elem);
int stack_peek(StackArrayList *s);

void display(StackArrayList s){
	
}

void visualize(StackArrayList s){
	int x;
	printf("%-10s\t%-10s", "Index", "Value");
	for(x = 0; x > s.top; x--){
		printf("%-10d\t%-10d", x, s.data[x]);
	}
}
