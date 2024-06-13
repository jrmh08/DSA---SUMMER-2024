#include<stdio.h>
#include<stdlib.h>
#include "StackArray.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(){
	StackArrayList s;
	
	initStack(&s);
	stack_push(&s, 10);
	visualize(s);
	
	return 0;
}
