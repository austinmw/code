#ifndef SKIPLIST_H_
#define SKIPLIST_H_

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

// number of lists
// If you have a 1/X chance of picking the next highest level, 
//then the max level should be log base X of N, the list size. (1/2 chance ==> lg(N).
int MAXLEVEL = 16; 


// node with pointers
typedef struct Node {
	int data;
	struct Node *next[1]; // or C99 using flexible array members: *next[]
} Node;


// skiplist
typedef struct SkipList {
	Node *header;
	int level;
	int count;
} SkipList;


// initialize skip list
SkipList* initSkipList() {	
	int i;
	SkipList *list = calloc(1, sizeof(SkipList));
	if (!list) {
		printf("Memory Error\n");
		exit(1);
	}
	//list->level = 0;	
	if ((list->header = calloc(1, sizeof(Node) + MAXLEVEL*sizeof(Node*))) == 0) {
		printf("Memory Error\n");
		exit(1);
	}	
	for (i = 0; i <= MAXLEVEL; i++)
		list->header->next[i] = list->header;	// circular? or change these all to NULL?
	printf("Skip list initialized.\n");
	//srand(time(NULL));
	return list;
}

// change MAXLEVEL to log2(expected list length)
void expectedSize(int size) {
	MAXLEVEL = ceil(log2(size));
	printf("\nMAXSIZE set to %d\n\n", MAXLEVEL);
}

// insert into skip list, return pointer to node
Node* insertElement(SkipList *list,int data) {
	int i, newLevel;
	Node* temp = list->header;
	Node *update[MAXLEVEL+1];
	// find where data belongs
	for (i = list->level; i >= 0; i--) {
		while(temp->next[i] != list->header && temp->next[i]->data < data)
			temp = temp->next[i];
		update[i] = temp;
	}
	temp = temp->next[0];
	// if element already exists, just return it (no duplicates)
	if (temp != list->header && temp->data == data)
		return temp;
	// determine level (coin flips till failure or max level reached)
	for (newLevel = 0; (rand() < RAND_MAX/2) && (newLevel < MAXLEVEL); newLevel++); // Pr(4) == Pr(5)??
	if (newLevel > list->level) {
		for (i = list->level + 1; i <= newLevel; i++)
			update[i] =  list->header;
		list->level = newLevel;
	}
	// make new  node
	if ((temp = calloc(1, sizeof(Node) + newLevel*sizeof(Node*))) == 0) {
		printf("Memory Error\n");
		exit(1);
	}
	temp->data = data;
	list->count++;
	// update next links
	for (i = 0; i <= newLevel; i++) {
		temp->next[i] = update[i]->next[i];
		update[i]->next[i] = temp;
	}
	printf("Element %d inserted into list. (level %d)\n", data, newLevel); 
	return temp;
}


// delete node containing data
void deleteElement(SkipList *list, int data) {
	int i;
	Node *update[MAXLEVEL+1], *temp;
	temp = list->header;
	for (i = list->level; i >= 0; i--) {
		while (temp->next[i] != list->header && temp->next[i]->data < data)
			temp = temp->next[i];
		update[i] = temp;
	}
	// move to (possible) node to delete
	temp = temp->next[0];
	// if doesn't exist
	if (temp == list->header || temp->data != data) {
		printf("Element %d doesn't exist.\n", data);	
		return;
	}
	// adjust next pointers
	for (i = 0; i <= list->level; i++) {
		if (update[i]->next[i] != temp) break;
		update[i]->next[i] = temp->next[i];
	}
	free (temp);
	printf("Element %d deleted from list.\n", data);
	list->count--;
	// adjust header level
	while ((list->level > 0) && (list->header->next[list->level] == list->header)) // double check
		list->level--;
}


// find node containing data
Node* findElement(SkipList *list, int data){
	int i, count = 0;
	Node *temp = list->header;
	for (i = list->level; i >= 0; i--) {
		while (temp->next[i] != list->header && temp->next[i]->data < data) {
			temp = temp->next[i];
			count++;
		}
	}
	temp = temp->next[0];
	if (temp != list->header && temp->data == data) {
		printf("Element %d found and returned.\n", data);
		//printf("Count: %d\n", count); // to see number of steps taken for search
		return (temp);
	}
	printf("Element %d not found.\n", data);
	return 0;
}


/* Dynamic array for use in printSkipList() function */
typedef struct {
	int *array;
	size_t used;
	size_t size;
} Array;
void initArray(Array *a, size_t initialSize) {
	a->array = malloc(initialSize * sizeof(int));
	a->used = 0;
	a->size = initialSize;
}
void insertArray(Array *a, int element) {
	if (a->used == a->size) {
		a->size *= 2;
		a->array = realloc(a->array, a->size * sizeof(int));
	}
	a->array[a->used++] = element;
}
void freeArray(Array *a) {
	free(a->array);
	a->array = NULL;
	a->used = a->size = 0;
}


// print skip-list info and representational figure (only useful for small lists)
void printSkipList(SkipList *list) {
	int i, j, k, pos = 0, prevPos = 0, diff, numDigits;
	Node* temp = list->header;
	Array a;
	// fill dynamic array with level 0 elements
	initArray(&a, 10);
	while (temp->next[0] != list->header) {
		temp = temp->next[0];
		insertArray(&a, temp->data);
	}
	temp = list->header;
	// print number of levels, number of elements
	printf("\nNumber of levels in skip-list: %d\n", list->level + 1);
	printf("Number of elements in skip-list: %d\n", list->count);
	printf("Skip-list figure: \n");
	// print figure of data
	for (i = list->level; i >= 0; i--) {
		pos = 0, prevPos = 0;
		while (temp->next[i] != list->header) {
		numDigits = 0;		
			temp = temp->next[i];
			while (temp->data != a.array[pos]) {
				
				if (a.array[pos] != 0)
					numDigits += floor (log10 (abs (a.array[pos]))) + 1;
				else numDigits++;
				pos++;
			}
			pos++;
			diff = (pos - prevPos) - 1;	
			if (diff >= 1) {
				for (j = 0; j < (4*diff)+numDigits; j++) 
						printf(" ");	
			}			
			printf("%d -> ", temp->data);
			prevPos = pos;
		}
		temp = list->header;
		printf("\n");		
	}
	printf("\n\n");
	freeArray(&a);
}


#endif // SKIPLIST_H_












