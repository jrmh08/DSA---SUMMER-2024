#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Hash_Open.h"


void initDictOD(Dict *D){
	D->multiplier = 1;
	D->elems = (NodePtr*)malloc((MAX * D->multiplier) * sizeof(NodePtr));
	
	int x;
	for(x = 0; x < MAX; x++){
		D->elems[x] = NULL;
	}
	D->count = 0;
}

Dict createDictOD(){
	Dict d;
	d.multiplier = 1;
	d.elems = (NodePtr*)malloc((MAX * d.multiplier) * sizeof(NodePtr));
	
	int x;
	for(x = 0; x < MAX; x++){
		d.elems[x] = NULL;
	}
	d.count = 0;
	
	return d;
}

int hashOD(int val, int multiplier){
	return (val % (MAX*multiplier));
}

void insertOD(Dict *D, Word elem){
	int check = (MAX * D->multiplier) * 0.65;
	printf("the packing density is: %d\n\n", check);
	printf("multiplier is: %d\n\n", D->multiplier);
	int Hash = hashOD(elem.hashVal, D->multiplier);
	
	NodePtr newNode = (NodePtr)malloc(sizeof(Node));
	
	if(D->count < check){
		if(newNode != NULL){
			newNode->data = elem;
			newNode->next = D->elems[Hash];
			D->elems[Hash] = newNode;
			D->count++;
			printf("Inserting word success!\n");
		}
	}else{
		printf("Packing Density reached, rehashing...\n");
		*D = reHashOD(D);
		Hash = hashOD(elem.hashVal, D->multiplier);
		if(newNode != NULL){
			newNode->data = elem;
			newNode->next = D->elems[Hash];
			D->elems[Hash] = newNode;
			D->count++;
			printf("Inserting word success!\n");
		}
	}
}

Dict reHashOD(Dict *D){
	Dict reHashed;
	int oldMax = MAX * D->multiplier;
	D->multiplier++;
	reHashed.multiplier = D->multiplier;
	int newMax = MAX * reHashed.multiplier, x;
	reHashed.elems = (NodePtr*)malloc((newMax) * sizeof(NodePtr));
	for(x = 0; x < newMax; x++){
		reHashed.elems[x] = NULL;
	}
	reHashed.count = 0; 
	//the snippet above is for initializing the new dictionary with new size
	
	
	NodePtr trav;
	for(x = 0; x < oldMax; x++){
		trav = D->elems[x];
		while(trav != NULL){
			if(trav != NULL){
				insertOD(&reHashed, trav->data);
			}else{
				printf("Nothing more to insert/end of all nodes.\n");
			}
			trav = trav->next;
		}
	}
	return reHashed;
}

int deleteWordOD(Dict *D, Word elem){
	int Hash = hashOD(elem.hashVal, D->multiplier);
	int deleted = -1;
	printf("Hash Value is: %d", Hash);
	
	printf("\n\n");
	NodePtr trav, temp;
	for(trav = D->elems[Hash]; trav != NULL && strcmp(elem.word, trav->data.word) != 0; trav = trav->next){}
	if(trav != NULL){
		temp = trav;
		trav = trav->next;
		free(temp);
		D->count--;
		deleted = Hash;
	}else{
		printf("Word not found. Nothing was deleted.\n");
	}
	return deleted;
}

int wordSearch(Dict D, Word elem){
	int Hash = hashOD(elem.hashVal, D.multiplier);
	int found = -1;
	
	printf("\n\n");
	NodePtr trav;
	for(trav = D.elems[Hash]; trav != NULL && strcmp(elem.word, trav->data.word) != 0; trav = trav->next){}
	if(trav != NULL){
		found = Hash;
	}
	return found;
}

void displayOD(Dict D){
	NodePtr trav;
	int x, max = MAX * D.multiplier;
	
	printf("\n\n");
	for(x = 0; x < max; x++){
		printf("%d%5s", x, " ");
		trav = D.elems[x];
		while(trav != NULL){
			if(trav != NULL){
				printf("-->");
				printf(" %s ", trav->data.word);
			}
			trav = trav->next;
		}
		printf("\n");
	}
}

void visualizeOD(Dict D){
	NodePtr trav;
	int x, max = MAX * D.multiplier;
	
	printf("\n\n");
	printf("INDEX\tWORDS\n");
	printf("=======================\n");
	for(x = 0; x < max; x++){
		printf("[%d]%5s", x, " ");
		trav = D.elems[x];
		while(trav != NULL){
			if(trav != NULL){
				printf("-->");
				printf(" %s ", trav->data.word);
			}else{
				printf(" NULL");
			}
			trav = trav->next;
		}
		printf("\n");
	}
	printf("Number of animals in the Dictionary: %d\n", D.count);
}


