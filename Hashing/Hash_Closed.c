#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Hash_Closed.h"

#define MAX 10
#define EMPTY -1
#define DELETED -5

void initDictCD(Dict *D){
	D->multiplier = 1;
	int max = MAX * D->multiplier, x;
	D->elems = (Word*)malloc(max * sizeof(Word));
	
	for(x = 0; x < max; x++){
		D->elems[x] = EMPTY;
	}
	D->count = 0;
}

Dict createDictCD(){
	CDict D;
	D.multiplier = 1;
	int max = MAX * D.multiplier, x;
	D.elems = (Word*)malloc(max * sizeof(Word));
	
	for(x = 0; x < max; x++){
		D.elems[x] = EMPTY;
	}
	D.count = 0;
	return D;
}

int hashCD(int val, int multiplier){
	
}

void insertCD(Dict *D, Word elem);

Dict reHashCD(Dict *D);

int deleteWordCD(Dict *D, Word elem);

int wordSearchCD(Dict D, Word elem);

void displayCD(Dict D);

void visualizeCD(Dict D);
