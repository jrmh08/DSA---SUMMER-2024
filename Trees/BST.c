#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "BST.h"

void initBST(NodePtr *bst){
	*bst = NULL;
}

bool isMember(NodePtr *bst, Product elem){
	NodePtr *trav;
	
	for(trav = bst; *trav != NULL && strcmp(elem.prodName, (*trav)->item.prodName) != 0;){
//		if(strcmp(elem.prodName, (*trav)->item.prodName) > 0){
//			trav = &(*trav)->right;
//		}else{
//			trav = &(*trav)->left;
//		}
		trav = (strcmp(elem.prodName, (*trav)->item.prodName) > 0)? &(*trav)->right : &(*trav)->left;
	}
	return (*trav != NULL);
}

void insertProd(NodePtr *bst, Product elem){
	NodePtr newNode = (NodePtr)malloc(sizeof(NodeType));
	NodePtr *trav;
	
	if(newNode != NULL){
		newNode->item = elem;
		newNode->left = newNode->right = NULL;
		
		for(trav = bst; *trav != NULL;){
			trav = (strcmp(elem.prodName, (*trav)->item.prodName) > 0)? &(*trav)->right : &(*trav)->left;
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
	NodePtr *trav, temp, *found;
	
	if(isMember(bst, elem)){
		printf("\nDeleting %s\n", elem.prodName);
		for(trav = bst; *trav != NULL && strcmp(elem.prodName, (*trav)->item.prodName) != 0;){
			if(strcmp(elem.prodName, (*trav)->item.prodName) > 0){
				trav = &(*trav)->right;
			}else{
				trav = &(*trav)->left;
			}
		}              
		if(*trav != NULL){
			temp = *trav;
			if(temp->left != NULL || temp->right != NULL){
				if((*trav)->left != NULL){
					found = &(*trav)->left;
					for(found = trav; *found != NULL;){
						found = &(*found)->right;
					}
					(*found)->item.expDate = temp->item.expDate;
					strcpy(temp->item.prodName, (*found)->item.prodName);
					(*found)->item.prodPrice = temp->item.prodPrice;
					(*found)->item.prodQty = temp->item.prodQty;
					free(*found);
				}else{
					found = &(*trav)->right;
				}
			}
			free(temp);
			printf("\nDelete Success!\n");
		}                        
	}else{
		printf("\nDelete Failed!");
	}
}

void DFS_preorder(NodePtr bst){
	if(bst != NULL){
		printf("%s ", bst->item.prodName);
		DFS_preorder(bst->left);
		DFS_preorder(bst->right);
	}
}

void DFS_inorder(NodePtr bst){
	if(bst != NULL){
		DFS_inorder(bst->left);
		printf("%s ", bst->item.prodName);
		DFS_inorder(bst->right);
	}
}

void DFS_postorder(NodePtr bst){
	if(bst != NULL){
		DFS_postorder(bst->left);
		DFS_postorder(bst->right);
		printf("%s ", bst->item.prodName);
	}
}

void visualizeBST(NodePtr bst){
	if(bst != NULL){
		visualizeBST(bst->left);
		printf("%s ", bst->item.prodName);
		visualizeBST(bst->right);
	}
}
