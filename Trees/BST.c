#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "BST.h"

#define SIZE 15

void initBST(NodePtr *bst){
	*bst = NULL;
}

bool isMember(NodePtr *bst, Product elem){
	NodePtr *trav;
	
	for(trav = bst; *trav != NULL && strcmp(elem.prodName, (*trav)->item.prodName) != 0;){
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
	NodePtr *trav;
	
	if(isMember(bst, elem)){
		for(trav = bst; *trav != NULL && strcmp((*trav)->item.prodName, elem.prodName) != 0; ){
			trav = (strcmp((*trav)->item.prodName, elem.prodName) > 0)? &(*trav)->left : &(*trav)->right;
		}
	}
	
	if(*trav != NULL){
		NodePtr temp;
		temp = *trav;
		
		if(temp->left == NULL || temp->right == NULL){ // for one or no child
			*trav = (temp->left != NULL)? temp->left : temp->right;
			free(temp);
		}else{ 
			temp->item = deleteMax(&temp->left);
		}
	}
}

Product deleteMax(NodePtr *bst){
	NodePtr *trav, temp;
	Product retval;
	
	for(trav = bst;  *trav != NULL && (*trav)->right != NULL; trav = &(*trav)->right){}
	
	if(*trav != NULL){
		temp = *trav;
		retval = (*trav)->item;
		*trav = temp->left;
		free(temp);
	}
}

void BFS(NodePtr bst){
	NodePtr tempQueue[SIZE], current;
	int front = 1, rear = 0;
	
	if(bst != NULL){
		for(tempQueue[++rear] = bst; front !=  (rear + 1) & SIZE;){
			current = tempQueue[front];
			front  = (front +1) % SIZE;
			
			if(current != NULL){
				printf("%s ", current->item.prodName);
				
				rear = (rear + 1) % SIZE;
				tempQueue[rear] = current->left;
				rear = (rear + 1) % SIZE;
				tempQueue[rear] = current->right;
			}
		}
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
