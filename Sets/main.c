#include <stdio.h>
#include <stdlib.h>
#include "Sets.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	SET A = {0,1,1,0,0,1,1,1,0,1};
	SET B = {1,0,1,1,0,1,0,0,0,1};
	display(A);
	display(B);
	
	SET * intersectionSet = Intersection(A, B);
	printf("The intersection is: ");
	display(*intersectionSet);
	
	SET * unionSet = Union(A, B);
	printf("The union is: ");
	display(*unionSet);
	
	insertVal(A, 0);
	display(A);
	
	deleteVal(A, 0);
	display(A);
	return 0;
}
