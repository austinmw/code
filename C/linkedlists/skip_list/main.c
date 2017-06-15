#include <stdio.h>
#include <stdlib.h>
#include "skiplist.h"

#include <time.h>

int main() {

	// initialize
	SkipList *list = initSkipList();
		

	// insert 5
	insertElement(list, 5);
	// doesn't find 3
	findElement(list, 3);
	// finds 5
	Node *x = findElement(list, 5);
	// delete 5
	deleteElement(list, 5);
	// now doesn't find 5
	findElement(list, 5);
	printf("\n");
	
	
	// scale MAXLEVEL appropriately for expected list size
	expectedSize(20);
	// insert [0:100:1900]
	int i;
	for (i = 0; i < 20; i++) 
		insertElement(list, i*100);
	// check find function
	for (i = 0; i < 20; i++) 
		findElement(list, i*100);
	// print figure
	printSkipList(list);
	// delete, print after each deletion
	for (i = 0; i < 20; i++) {
		deleteElement(list, i*100);
		printSkipList(list);
	}	
		
		
	
	
	return 0;
}


