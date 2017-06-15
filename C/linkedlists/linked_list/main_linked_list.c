#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

int main() {

	// create root node 
	Node *root = LLCreate(5); // root points to a pointer to a node 
	// so 'root' should be the address of the head node, so &root would be its 
	// own address (the pointer), not the address of the head node created
	printf("length: %d\n", LLLength(root));
	printf("data (1): %d\n\n", root->data);
	// 5 -> NULL
	
	
	// insert new node AFTER the 1st, print length, print new node data
	LLInsert(&root, 10, 2);
	printf("length: %d\n", LLLength(root));
	printf("data (2): %d\n\n", root->next->data);
	// 5 -> 10 -> NULL
	
	
	// insert new node BEFORE the first, print length, print new node data
	LLInsert(&root, 7, 1);
	printf("length: %d\n", LLLength(root));
	printf("data (1): %d\n\n", root->data);
	// 7 -> 5 -> 10 -> NULL
	

	// delete head node
	LLDeleteNode(&root, 1);
	printf("length: %d\n", LLLength(root));
	printf("data (1): %d\n\n", root->data);
	// 5 -> 10 -> NULL


	// delete tail node
	LLDeleteNode(&root, 2);
	printf("length: %d\n", LLLength(root));
	printf("data (1): %d\n", root->data);
	printf("root->next: %p\n\n", root->next);
	// 5 -> NULL

	
	// insert new node AFTER the 1st, print length, print new node data
	LLInsert(&root, 42, 2);
	printf("length: %d\n", LLLength(root));
	printf("data (2): %d\n", root->next->data);
	printf("root->next->next: %p\n\n", root->next->next);
	// 5 -> 42 -> NULL

	// insert new node at tail
	LLInsert(&root, 99, LLLength(root)+1); // insert position = length + 1
	printf("length: %d\n", LLLength(root));
	printf("data (3): %d\n", root->next->next->data);
	printf("root->next->next->: %p\n\n", root->next->next->next);
	// 5 -> 42 -> 99 -> NULL


	// delete entire linked list
	LLDeleteList(&root);
	printf("length: %d\n", LLLength(root));
		
}