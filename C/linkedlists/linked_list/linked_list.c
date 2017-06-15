#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"


// create a linked list
Node* LLCreate(int data) {
	Node *head = malloc(sizeof(Node));
	if ( head != NULL) {
		head->next = NULL;
		head->data = data;
	}
	return head;
}


// return linked list length
int LLLength(Node *head) {
	Node *current = head;
	int count = 0;
	
	while (current != NULL) {
		count++;
		current = current->next;
	}
	return count; // returns 0 if head == NULL
}


// insert into a linked list
void LLInsert(Node **head, int data, int position){
	// must update first element pointer in calling function, not just called 
	// function, so a double pointer is used
	int k = 1;
	Node *p, *q, *newNode;
	newNode = malloc(sizeof(Node));
	
	if (!newNode){
		printf("Memory Error");
		return;
	}
	
	newNode->data = data;
	p=*head;
	
	// Inserting at the beginning
	if (position == 1){
		newNode->next = p;
		*head = newNode;
	}
	// Traverse the list until the position where we want to insert
	else {
		while ((p != NULL) && (k<position)) {
			k++;
			q=p;
			p=p->next;
		}
		q->next = newNode; // more optimum way to do this
		newNode->next=p; 
	} // Space complexity: O(1), for creating one temporary variable
} // Time complexity: O(n), since, in the worst case, inserting at the end of the list


// delete a linked list node
void LLDeleteNode(Node **head, int position) {
	int k = 1;
	Node *p, *q;
	if(*head == NULL) {
		printf("List Empty\n");
		return;
	}
	p = *head;
	// Delete head node
	if (position == 1) {
		*head = (*head)->next;
		free(p);
		return;
	}
	// Traverse list until arrive at position to delete
	else {
		while ((p != NULL) && (k < position)) {
			k++;
			q = p;
			p = p->next;
		}	
		if (p == NULL) // At the end
			printf("Position does not exist.\n");
		else { // From the middle
			q->next = p->next;
			free(p);
		}
	}
}


// delete entire linked list
void LLDeleteList(Node **head) {
	Node *auxiliaryNode, *iterator;
	iterator = *head;
	while (iterator) { // while (iterator != NULL)
		auxiliaryNode = iterator->next;
		free(iterator);
		iterator = auxiliaryNode;
	}
	*head = NULL;
}







/*

How does head->next = NULL; and head->data = data; work after the malloc?

It doesnt have local variables like next and data.

next and data are just used to calculate the address relative to from where node is pointing. 

When you do node->data then the address is calculated as address pointed by node + (total  bytes required by any metadata for malloc) + 0 because data is the first member of node struct.

And when you do node->next then the address is calculated as address pointed by node + (total bytes required by any metadata for malloc) + sizeof(data) , because next is the second member of the node struct that comes after data member. 

*/





















