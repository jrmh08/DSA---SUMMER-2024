#ifndef HASH_CLOSED
#define HASH_CLOSED

typedef struct{
	char word[20];
	int hashVal;
}Word;

typedef struct{
	Word *elems;
	int count;
	int multiplier;
}CDict;

void initDictCD(Dict *D);
Dict createDictCD();
int hashCD(int val, int multiplier);
void insertCD(Dict *D, Word elem);
Dict reHashCD(Dict *D);
int deleteWordCD(Dict *D, Word elem);
int wordSearchCD(Dict D, Word elem);
void displayCD(Dict D);
void visualizeCD(Dict D);


#endif
