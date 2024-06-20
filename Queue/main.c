#include <stdio.h>
#include <stdlib.h>
#include "QueueLL.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	Queue Q;
	initQueue(&Q);
	
	printf("ENQUEUEING ELEMENTS:\n\n");
	enqueue(&Q, 5);
	enqueue(&Q, 2);
	enqueue(&Q, 1);
	enqueue(&Q, 1);
	enqueue(&Q, 4);
	
	printf("front is %d\n", front(Q));
	printf("rear is %d\n\n", rear(Q));
	display(Q);
	visualize(Q);
	system("pause");
	system("cls");
	
	printf("DEQUEUEING ELEMENTS:\n\n");
	dequeue(&Q);
	display(Q);
	visualize(Q);
	system("pause");
	
	return 0;
}
