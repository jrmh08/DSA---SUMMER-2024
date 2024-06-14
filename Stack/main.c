#include<stdio.h>
#include<stdlib.h>
#include "StackArray.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(){
	StackArrayList s;
	
	initStack(&s);
	stack_push(&s, 10);
	stack_push(&s, 1);
	stack_push(&s, 4);
	stack_push(&s, 6);
	stack_push(&s, 5);
	stack_push(&s, 9);
	display(s);
	stack_pop(&s);
	printf("\n\n");
	//display(s);
	int top = stack_peek(s);
	printf("The top of the stack is: %d", top);
	
	return 0;
}
