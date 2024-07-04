#ifndef HASH_OPEN
#define HASH_OPEN

#define MAX 10

//OPEN HASHING
typedef struct{
	char word[20];
	int hashVal;
}OWord;

typedef struct node{
	OWord data;
	struct node* next;
}Node, *NodePtr;

typedef struct{
	NodePtr *elems;
	int count;
	int multiplier;
}ODict;

void initDictOD(ODict *D);
ODict createDictOD();
int hashOD(int val, int multiplier);
void insertOD(ODict *D, OWord elem);
ODict reHashOD(ODict *D);
int deleteWordOD(ODict *D, OWord elem);
int wordSearchOD(ODict D, OWord elem);
void displayOD(ODict D);
void visualizeOD(ODict D);



#endif
