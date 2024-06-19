#include <stdio.h>
#include <stdlib.h>
#include "StackLL.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	StackLList L;
	initStackLL(&L);
	
	stackLL_push(&L, 5);
	stackLL_push(&L, 10);
	stackLL_push(&L, 4);
	stackLL_push(&L, 8);
	stackLL_push(&L, 2);
	stackLL_push(&L, 12);
	visualize(L);
	system("pause");
	system("cls");
	
	stackLL_pop(&L);
	visualize(L);
	
	return 0;
}
