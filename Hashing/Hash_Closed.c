#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "Hash_Closed.h"

#define MAX 10
#define EMPTY -1
#define DELETED -5

void initDictCD(CDict *D){
	D->multiplier = 1;
	int max = MAX * D->multiplier, x;
	D->elems = (Word*)malloc(max * sizeof(Word));
	
	for(x = 0; x < max; x++){
		D->elems[x] = EMPTY;
	}
	D->count = 0;
}

CDict createDictCD(){
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

bool isFull(CDict D){
	return (D.count == ((MAX * D.multiplier) 0.65));
}

int hashCD(int val, int multiplier){
	return (val % (MAX * multiplier));
}

void insertCD(CDict *D, Word elem){
	int Hash = hashCD(elem.hashVal, D->multiplier), flag = 0;
	if(!isFull){
		while(flag != 1)
		if(D->elems[Hash].data.word == EMPTY || D->elems[Hash].data.word == DELETED){
			D->elems[Hash] = elem;
			D->count++;
			flag = 1;
		}else if(Hash % (MAX * D->multiplier) > 0){
			Hash += 1;
		}else{
			Hash %= MAX * D->multiplier;
		}
	}else{
		reHash(D);
		Hash = hashCD(elem.hashVal, D->multiplier);
		while(flag != 1)
		if(D->elems[Hash].data.word == EMPTY || D->elems[Hash].data.word == DELETED){
			D->elems[Hash] = elem;
			D->count++;
			flag = 1;
		}else if(Hash % (MAX * D->multiplier) > 0){
			Hash += 1;
		}else{
			Hash %= MAX * D->multiplier;
		}
	}
}

Dict reHashCD(CDict *D){
	CDict newDict;
	int oldMax = D->multiplier;
	D->multiplier++;
	newDict.multiplier = D->multiplier;
	int max = MAX * D->multiplier, x;
	newDict.elems = (Word*)malloc(max * sizeof(Word));
	for(x = 0; x < max; x++){
		D->elems[x] = EMPTY;
	}
	D.count = 0;
	
	for(x = 0; x < oldMax; x++){
		if(D->elems[x].word != EMPTY || D->elems[x].word != DELETED){
			insertCD(&newDict, D->elems[x]);
		}
	}
	return newDict;
}

int deleteWordCD(CDict *D, Word elem);

int wordSearchCD(CDict D, Word elem);

void displayCD(CDict D);

void visualizeCD(CDict D);
