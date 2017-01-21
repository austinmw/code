#include <stdio.h>
#include <stdlib.h>
#include "circular_linked_list.h"

int main(int argc, char *argv[]) {

	// create empty CLL, check length and print functions
	CLL_Node* head = NULL;
	printf("CLL length: %d\n", CLL_Length(head));
	CLL_Print(head);
	
	// create head node, check length and contents
	head = CLL_Create(5);
	printf("CLL length: %d\n", CLL_Length(head));
	CLL_Print(head);
	
	// push new node to head of list, check
	CLL_Push_Front(&head, 2);
	printf("CLL length: %d\n", CLL_Length(head));
	CLL_Print(head);
	
	// push new node to tail of list, check
	CLL_Push_Back(&head, 42);
	printf("CLL length: %d\n", CLL_Length(head));
	CLL_Print(head);
	
	// pop node from head of list, check
	int n = CLL_Pop_Front(&head);
	printf("Poped from front: %d\n", n);
	printf("CLL length: %d\n", CLL_Length(head));
	CLL_Print(head);
	
	// pop node from tail of list, check
	n = CLL_Pop_Back(&head);
	printf("Poped from back: %d\n", n);
	printf("CLL length: %d\n", CLL_Length(head));
	CLL_Print(head);
	
	// pop (front) last node from list, check
	n = CLL_Pop_Front(&head);
	printf("Poped from front: %d\n", n);
	printf("CLL length: %d\n", CLL_Length(head));
	CLL_Print(head);
	
	// push new node to head of list, check
	CLL_Push_Front(&head, 7);
	printf("CLL length: %d\n", CLL_Length(head));
	CLL_Print(head);
	
	// pop (back) last node from list, check
	n = CLL_Pop_Back(&head);
	printf("Poped from front: %d\n", n);
	printf("CLL length: %d\n", CLL_Length(head));
	CLL_Print(head);

	// wipe list
	free(head);
	head = NULL;
	
	// recreate list
	head = CLL_Create(50);
	printf("CLL length: %d\n", CLL_Length(head));
	CLL_Print(head);
	
	// pop (back) last node from list, check
	n = CLL_Pop_Back(&head);
	printf("Poped from front: %d\n", n);
	printf("CLL length: %d\n", CLL_Length(head));
	CLL_Print(head);
	
	// wipe list
	free(head);
	head = NULL;
	
	// create circularly linked list with 100 nodes, check
	for (int i = 1; i <= 100; i++) {
		CLL_Push_Back(&head, i);
	}
	printf("CLL length: %d\n", CLL_Length(head));
	CLL_Print(head);
	
	// delete entire list
	while(CLL_Pop_Back(&head));
	
	// wipe list
	free(head);
	head = NULL;
}