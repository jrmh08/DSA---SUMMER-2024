#include <stdio.h>
#include <stdlib.h>
#include "StackLL.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	StackLList L;
	initStackLL(&L);
	
	printf("PUSHING OF ELEMENTS:\n");
	stackLL_push(&L, 5);
	stackLL_push(&L, 10);
	stackLL_push(&L, 4);
	stackLL_push(&L, 8);
	stackLL_push(&L, 2);
	stackLL_push(&L, 12);
	visualize(L);
	int peek = stackLL_peek(L);
	printf("\ntop is %d\n", peek);
	system("pause");
	system("cls");
	
	printf("POPPING OF ELEMENTS:\n");
	stackLL_pop(&L);
	stackLL_pop(&L);
	stackLL_pop(&L);
	visualize(L);
	
	return 0;
}
