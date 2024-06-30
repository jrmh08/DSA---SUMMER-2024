#include <stdio.h>
#include <stdlib.h>
#include "Hash_Open.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	Dict animals;
	initDictOD(&animals);
	
	Word w1 = {"zebra", 15};
	Word w2 = {"penguin", 28};
	Word w3 = {"dog", 25};
	Word w4 = {"cat", 13};
	Word w5 = {"jaguar", 39};
	Word w6 = {"goat", 50};
	Word w7 = {"deer", 91};
	Word w8 = {"cheetah", 31};
	Word w9 = {"lion", 2};
	Word w10 = {"tiger", 49};
	Word w11 = {"parrot", 64};
	Word w12 = {"giraffe", 51};
	Word w13 = {"elephant", 44};
	Word w14 = {"hamster", 99};
	Word w15 = {"monkey", 48};
	Word w16 = {"rabbit", 69};
	Word w17 = {"bulldog", 80};
	insertOD(&animals, w1);
	insertOD(&animals, w2);
	insertOD(&animals, w3);
	insertOD(&animals, w4);
	insertOD(&animals, w5);
	insertOD(&animals, w6);
	insertOD(&animals, w7);
	insertOD(&animals, w8);
	insertOD(&animals, w9);
	insertOD(&animals, w10);
	insertOD(&animals, w11);
	insertOD(&animals, w12);
	insertOD(&animals, w13);
	insertOD(&animals, w14);
	insertOD(&animals, w15);
	insertOD(&animals, w16);
	visualizeOD(animals);
	
	printf("Searching for: %s\n", w12.word);
	printf("Found at index: %d\n\n", wordSearch(animals, w12));
	
	printf("Deleted at index: %d\n", deleteWordOD(&animals, w11));
	visualizeOD(animals);
	
	
	return 0;
}
