#ifndef HASH_OPEN
#define HASH_OPEN

#define MAX 10

//OPEN HASHING
typedef struct{
	char word[20];
	int hashVal;
}Word;

typedef struct node{
	Word data;
	struct node* next;
}Node, *NodePtr;

typedef struct{
	NodePtr *elems;
	int count;
	int multiplier;
}Dict;

void initDictOD(Dict *D);
Dict createDictOD();
int hashOD(int val, int multiplier);
void insertOD(Dict *D, Word elem);
Dict reHashOD(Dict *D);
int deleteWordOD(Dict *D, Word elem);
int wordSearchOD(Dict D, Word elem);
void displayOD(Dict D);
void visualizeOD(Dict D);



#endif
