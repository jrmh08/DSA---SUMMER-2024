#ifndef HASH_CLOSED
#define HASH_CLOSED

typedef struct{
	char word[20];
	int hashVal;
}CWord;

typedef struct{
	CWord *elems;
	int count;
	int multiplier;
}CDict;

void initDictCD(CDict *D);
CDict createDictCD();
int hashCD(int val, int multiplier);
void insertCD(CDict *D, CWord elem);
CDict reHashCD(CDict *D);
int deleteWordCD(CDict *D, CWord elem);
int wordSearchCD(CDict D, CWord elem);
void displayCD(CDict D);
void visualizeCD(CDict D);


#endif
