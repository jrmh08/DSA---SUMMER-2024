#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include "StackArray.h"

void initStack(StackArrayList *s){
	s->top = null;
}

StackArrayList createStack(){
	StackArrayList s;
	s.top = null;
	return s;
}

bool isFull(StackArrayList s){
	return (s.top == MAX-1);
}

bool isEmpty(StackArrayList s){
	return (s.top == null);
}

bool stack_push(StackArrayList *s, int elem){
	bool push = true;
	if(!isFull(*s)){
		s->top++;
		s->data[s->top] = elem;
		printf("push successful\n");
	}else{
		printf("Stack is full, can't push.\n");
		push = false;
	}
	return push;
}

bool stack_pop(StackArrayList *s){
	bool pop = true;
	if(!isEmpty(*s)){
		s->top--;
		printf("pop successful\n");
	}else{
		printf("list is empty\n");
		pop = false;
	}
	return pop;
}

int stack_peek(StackArrayList s){
	return s.data[s.top];
}

void display(StackArrayList s){
	StackArrayList temp = createStack();
	int x;
	printf("\n\nSTACK DISPLAY\n");
	while(!isEmpty(s)){
		x = s.data[s.top];
		stack_push(&temp, x);
		printf("%d\n", temp.data[temp.top]);
		stack_pop(&s);
	}
}

void visualize(StackArrayList s){
	int x;
	printf("%s  |  %s", "Index", "Value\n");
	for(x = s.top; x > -1; x--){
		printf("%3d    |  %3d", x, s.data[x]);
		if(s.data[x] == s.data[s.top]){
			printf("   <-- TOP");
		}
		printf("\n");
	}
}

StackArrayList getAllEven(StackArrayList *s){  
	StackArrayList evenStack = createStack();
	int x, even;
	for(x = s->top; x > null && !isEmpty(*s); x--){
		even = s->data[x];
		if(even % 2 == 0){
			stack_push(&evenStack, s->data[x]);
		}
		stack_pop(s);
	}
}
