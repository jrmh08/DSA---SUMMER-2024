#include <stdio.h>
#include <stdlib.h>
#include "Hash_Open.h"
#include "Hash_Closed.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	CDict animals;
	initDictCD(&animals);
	
	CWord w1 = {"zebra", 15};
	CWord w2 = {"penguin", 28};
	CWord w3 = {"dog", 25};
	CWord w4 = {"cat", 13};
	CWord w5 = {"jaguar", 39};
	CWord w6 = {"goat", 50};
	CWord w7 = {"deer", 91};
	CWord w8 = {"cheetah", 31};
	CWord w9 = {"lion", 2};
	CWord w10 = {"tiger", 49};
	CWord w11 = {"parrot", 64};
	CWord w12 = {"giraffe", 51};
	CWord w13 = {"elephant", 44};
	CWord w14 = {"hamster", 99};
	CWord w15 = {"monkey", 48};
	CWord w16 = {"rabbit", 69};
	CWord w17 = {"bulldog", 80};
	insertCD(&animals, w1);
	insertCD(&animals, w2);
	insertCD(&animals, w3);
	insertCD(&animals, w4);
	visualizeCD(animals);
	insertCD(&animals, w5);
	insertCD(&animals, w6);
	insertCD(&animals, w7);
	insertCD(&animals, w8);
	insertCD(&animals, w9);
	insertCD(&animals, w10);
	insertCD(&animals, w11);
	insertCD(&animals, w12);
	insertCD(&animals, w13);
	insertCD(&animals, w14);
	insertCD(&animals, w15);
	insertCD(&animals, w16);
	insertCD(&animals, w17);
	visualizeCD(animals);
	displayCD(animals);
	
	printf("Searching for: %s\n", w12.word);
	printf("Found at index: %d\n\n", wordSearchCD(animals, w12));
		
	printf("Deleted at index: %d\n", deleteWordCD(&animals, w17));
	visualizeCD(animals);
	
	
	return 0;
}
