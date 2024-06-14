#include <stdio.h>
#include <stdlib.h>
#include "QueueLL.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	Queue Q;
	initQueue(&Q);
	enqueue(&Q, 5);
	enqueue(&Q, 8);
	enqueue(&Q, 4);
	enqueue(&Q, 1);
	display(Q);
	printf("The front is %d\n", front(Q));
	printf("The rear is %d\n", rear(Q));
	
	dequeue(&Q);
	
	display(Q);
	
	printf("The front is %d\n", front(Q));
	printf("The rear is %d\n", rear(Q));
	return 0;
}
