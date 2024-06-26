#include <stdio.h>
#include <stdlib.h>
#include "QUEUE_CPUSched.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	ProcQ pq = input();
	ProcQ sort = procSort(&pq);
//	pq = display(pq);
//	visualizePQ(pq);
	CPU_FCFS(&sort);
	visualizePQ(sort);
	sort = display(sort);
	
	
	return 0;
}
