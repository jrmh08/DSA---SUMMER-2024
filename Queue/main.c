#include <stdio.h>
#include <stdlib.h>
#include "QueueLL.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	Queue Q;
	initQueue(&Q);
	
	enqueue(&Q, 5);
	enqueue(&Q, 4);
	enqueue(&Q, 1);
	enqueue(&Q, 2);
	enqueue(&Q, 6);
	Q = display(Q);
	visualize(Q);
	system("pause");
	system("cls");
	
	dequeue(&Q);
	Q = display(Q);
	visualize(Q);
	
	return 0;
}
