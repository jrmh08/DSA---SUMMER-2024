#include <stdio.h>
#include <stdlib.h>
#include "BST.h"

void initBST(NodePtr *bst){
	*BST = NULL;
}

void insertProd(NodePtr *BST, Product elem){
	NodePtr *newNode = (NodePtr *)malloc(sizeof(NodeType));
	NodePtr *trav;
	
	for(trav = BST; )
	if(newNode != NULL){
		BST->item = elem;
		BST->left = NULL;
		BST->right = NULL;
	}
}

void deleteProd(NodePtr *BST, char prodname[]){
	
}
