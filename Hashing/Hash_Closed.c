#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "Hash_Closed.h"

#define MAX 10
#define EMPTY "null"
#define DELETED "del"

void initDictCD(CDict *D){
	D->multiplier = 1;
	int max = MAX * D->multiplier, x;
	D->elems = (CWord*)malloc(max * sizeof(CWord));
	
	for(x = 0; x < max; x++){
		strcpy(D->elems[x].word, EMPTY);
	}
	D->count = 0;
}

CDict createDictCD(){
	CDict D;
	D.multiplier = 1;
	int max = MAX * D.multiplier, x;
	D.elems = (CWord*)malloc(max * sizeof(CWord));
	
	for(x = 0; x < max; x++){
		strcpy(D.elems[x].word, EMPTY);
	}
	D.count = 0;
	return D;
}

bool isFull(CDict D){
	return (D.count == (MAX * D.multiplier) * 0.65);
}

int hashCD(int val, int multiplier){
	return (val % (MAX * multiplier));
}

void insertCD(CDict *D, CWord elem){
	int Hash = hashCD(elem.hashVal, D->multiplier), flag = 0, x;
	int check = (MAX * D->multiplier) * 0.65;
	printf("the checking count is: %d\n", check);
	if(D->count < check){
		while(flag != 1){
			if(strcmp(D->elems[Hash].word, EMPTY) == 0 || strcmp(D->elems[Hash].word, DELETED) == 0){
				D->elems[Hash] = elem;
				D->count++;
				printf("Inserting elem success.\n");
				flag = 1;
			}else if(Hash % (MAX * D->multiplier) == 0){
				Hash %= MAX * D->multiplier;
			}else{
				Hash += 1;
			}
		}
	}else{
		*D = reHashCD(D);
		Hash = hashCD(elem.hashVal, D->multiplier);
		while(flag != 1){
			if(strcmp(D->elems[Hash].word, EMPTY) == 0 || strcmp(D->elems[Hash].word, DELETED) == 0){
				D->elems[Hash] = elem;
				D->count++;
				printf("Inserting elem success.\n");
				flag = 1;
			}else if(Hash % (MAX * D->multiplier) == 0){
				Hash %= MAX * D->multiplier;
			}else{
				Hash += 1;
			}
		}
	}
//	printf("THE COUNT IS: %d\n", D->count);
}

CDict reHashCD(CDict *D){
	CDict newDict;
	int oldMax = MAX * D->multiplier;
	D->multiplier++;
	newDict.multiplier = D->multiplier;
	int max = MAX * D->multiplier, x;
	newDict.elems = (CWord*)malloc(max * sizeof(CWord));
	for(x = 0; x < max; x++){
		strcpy(newDict.elems[x].word, EMPTY);
	}
	newDict.count = 0;
	
	for(x = 0; x < oldMax; x++){
		if(strcmp(D->elems[x].word, EMPTY) != 0 || strcmp(D->elems[x].word, DELETED) != 0){
			insertCD(&newDict, D->elems[x]);
		}
	}
	return newDict;
}

int deleteWordCD(CDict *D, CWord elem);

int wordSearchCD(CDict D, CWord elem);

void displayCD(CDict D);

void visualizeCD(CDict D){
	int x, max = MAX * D.multiplier;
	
	printf("INDEX%10s\n", "WORD");
	for(x = 0; x < max; x++){
		printf(" [%2d]%11s\n", x, D.elems[x].word);
	}
}
