#include<stdio.h>
#include<stdlib.h>
#include "Sets.h"

//CREATE A PROGRAM TO FIND THE UNION AND INSTERSECTION OF 2 SETS
// - FUNCTIONS THAT ACCEPT 2 SETS AND RETURNS THE RESULTING UNION AND INTERSECTION
// - FUNCTIONS TO ADD OR DELETE VALUES IN THE SET
// - KEEP THE INTEGRITY OF THE 2 INITIAL SETS WHEN FINDING UNION AND INTERSECTION
// - DISPLAY UNIONS AND INTERSECTIONS

void initSet(SET *A){
	int x;
	
	for(x = 0; x < MAX; x++){
		(*A)[x] = 0;
	}
}

void insertVal(SET A, int ndx){
	if(ndx < MAX){
		A[ndx] = 1;
		printf("insert value success\n");
	}
}

void deleteVal(SET A, int ndx){
	if(ndx < MAX){
		A[ndx] = 0;
		printf("delete value success\n");
	}
}

SET* Intersection(SET A, SET B){
	int x;
	SET *C = (SET *)malloc(sizeof(SET));
	
	if(C != NULL){
		for(x = 0; x < MAX; x++){
			(*C)[x] = A[x] & B[x];
		}
	}
	return C;
}

SET* Union(SET A, SET B){
	int x;
	SET *C = (SET *)malloc(sizeof(SET));
	
	if(C != NULL){
		for(x = 0; x < MAX; x++){
			(*C)[x] = A[x] | B[x];
		}
	}
	return C;
}

void display(SET A){
	int x;
	
	printf("The Set is: ");
	for(x = 0; x < MAX; x++){
		printf("%d ", A[x]);
	}
	printf("\n\n");
}
