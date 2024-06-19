#include<stdio.h>
#include<stdlib.h>
#include "StackArray.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(){
	
	//Stack Array Implementation
	StackArrayList s;
	
	initStack(&s);
	printf("PUSHING OF ELEMENTS:\n");
	stack_push(&s, 10);
	stack_push(&s, 1);
	stack_push(&s, 4);
	stack_push(&s, 6);
	stack_push(&s, 5);
	stack_push(&s, 9);
	display(s);
	int top = stack_peek(s);
	printf("The top of the stack is: %d\n\n", top);
	system("pause");
	system("cls");
	
	printf("POPPING OF ELEMENTS:\n");
	stack_pop(&s);
	printf("\n\n");
	display(s);
	top = stack_peek(s);
	visualize(s);
	printf("The top of the stack is: %d\n\n", top);
	system("pause");
	system("cls");
	
	printf("GETTING ALL EVEN NUMBERS AND DISPLAYING IT IN A NEW STACK:\n");
	StackArrayList even = getAllEven(&s);
	visualize(even);
	system("pause");
	system("cls");
	
	return 0;
}
