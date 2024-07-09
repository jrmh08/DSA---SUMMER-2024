#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "BST.h"

void initBST(NodePtr *bst){
	*bst = NULL;
}

bool isMember(NodePtr *bst, Product elem){
	NodePtr *trav;
	
	for(trav = bst; *trav != NULL && strcmp(elem.prodName, (*trav)->item.prodName) != 0;){
		if(strcmp(elem.prodName, (*trav)->item.prodName) > 0){
			trav = &(*trav)->right;
		}else{
			trav = &(*trav)->left;
		}
	}
	return (*trav != NULL && strcmp(elem.prodName, (*trav)->item.prodName) == 0);
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

//1. Find the node to be deleted.
//2. If the node to be deleted has no children (it's a leaf), simply remove it.
//3. If the node to be deleted has one child, replace the node with its child.
//4. If the node to be deleted has two children:
//		-Find the in-order successor (smallest node in the right subtree) or in-order predecessor (largest node in the left subtree).
//		-Replace the node's value with the in-order successor or predecessor's value.
//		-Delete the in-order successor or predecessor node.
void deleteProd(NodePtr *bst, Product elem){
	NodePtr trav, temp;
	
	if(isMember(*bst, elem)){
		
	}
//	temp = trav;
//	trav = 
}

void visualizeBST(NodePtr bst){
	if(bst != NULL){
		visualizeBST(bst->left);
		printf("%s ", bst->item.prodName);
		visualizeBST(bst->right);
	}
}
