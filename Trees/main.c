#include <stdio.h>
#include <stdlib.h>
#include "BST.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	NodePtr tr;
	initBST(&tr);
	
	Product p3 = {"Cadbury", 100.00, 30, {12, 7, 2024}};
	Product p1 = {"Ferrero", 200.00, 30, {22, 1, 2024}};
	Product p2 = {"Hershey", 150.00, 20, {2, 4, 2024}};
	insertProd(&tr, p1);
	insertProd(&tr, p2);
	insertProd(&tr, p3);
	
	visualizeBST(tr);
	
	return 0;
}
