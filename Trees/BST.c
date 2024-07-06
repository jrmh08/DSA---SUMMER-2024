#include <stdio.h>
#include <stdlib.h>
#include "BST.h"

void initBST(NodePtr *bst){
	*bst = NULL;
}

void insertProd(NodePtr *bst, Product elem){
	NodePtr newNode = (NodePtr)malloc(sizeof(NodeType));
	NodePtr *trav;
	
	
	
	if(newNode != NULL){
		newNode->item = elem;
		newNode->left = newNode->right = NULL;
		
		for(trav = bst; *trav != NULL;){
			if(strcmp(elem.prodName, (*trav)->item.prodName) > 0){
				trav = &(*trav)->right;
			}else{
				trav = &(*trav)->left;
			}
		}
		*trav = newNode;
	}
}

void deleteProd(NodePtr *bst, char prodname[]){
	
}

void visualizeBST(NodePtr bst){
	if(bst != NULL){
		visualizeBST(bst->left);
		printf("%s ", bst->item.prodName);
		visualizeBST(bst->right);
	}
}
