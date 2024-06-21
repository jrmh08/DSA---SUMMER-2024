#ifndef SETS_ARRAY
#define SETS_ARRAY

#define MAX 10

typedef int SET[MAX];

void initSet(SET *A);
void insertVal(SET A, int ndx);
void deleteVal(SET A, int ndx);
SET* Intersection(SET A, SET B);
SET* Union(SET A, SET B);
void display(SET A);

#endif















