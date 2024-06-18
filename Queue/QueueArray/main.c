#include <stdio.h>
#include <stdlib.h>
#include "QueueArray.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	CircularQ Q;
	initArrQueue(&Q);
	
	printf("ENQUEUEING ELEMENTS:\n");
	enqueue(&Q, 7);
	enqueue(&Q, 3);
	enqueue(&Q, 10);
	enqueue(&Q, 2);
	enqueue(&Q, 4);
	enqueue(&Q, 15);
	enqueue(&Q, 9);
	enqueue(&Q, 13);
	enqueue(&Q, 6);
	enqueue(&Q, 8);
	enqueue(&Q, 6);
	enqueue(&Q, 11);
	display(Q);
	system("pause");
	system("cls");
	
	printf("DEQUEUEING ELEMENTS:\n");
	dequeue(&Q);
	display(Q);
	system("pause");
	system("cls");
	
	printf("ENQUEUEING ELEMENTS, AGAIN:\n");
	enqueue(&Q, 8);
	enqueue(&Q, 6);
	enqueue(&Q, 11);
	display(Q);
	
	return 0;
}
