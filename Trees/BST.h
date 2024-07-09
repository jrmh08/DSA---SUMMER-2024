#ifndef BST
#define BST

typedef struct{
	int day, month, year;
}Date;

typedef struct{
	char prodName[20];
	float prodPrice;
	int prodQty;
	Date expDate;
}Product;

typedef struct node{
	Product item;
	struct node *left, *right;
}NodeType, *NodePtr;

//ADD //
//DELETE
//TRAVERSAL: below
//BFS (QUEUES) 
//DFS -INORDER -POSTORDER -PREORDER

void initBST(NodePtr *bst);
bool isMember(NodePtr *bst, Product elem);
void insertProd(NodePtr *bst, Product elem);
void deleteProd(NodePtr *bst, Product elem);
void visualizeBST(NodePtr bst);


#endif
