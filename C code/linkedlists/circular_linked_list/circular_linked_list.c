#include <stdio.h>
#include <stdlib.h>
#include "circular_linked_list.h"


CLL_Node* CLL_Create(int data) {
	CLL_Node *head = calloc(1, sizeof(CLL_Node));
	head->data = data;
	head->next = head;
	printf("First node with data %d inserted into circularly linked list.\n", data);
	return head;
}


int CLL_Length(CLL_Node *head) {
	CLL_Node *current = head;
	int count = 0;
	if (!head)
		return count;
	do {
		current = current->next;
		count++;
	}
	while (current != head);
	return count;
}


void CLL_Print(CLL_Node *head) {
	CLL_Node *temp = head;
	if (temp) {
		printf("Circular linked list contents: ");
		do {		
			printf("%d  ", temp->data);
			temp = temp->next;			
		}
		while(temp != head);
		printf("\n\n");
	}
	else
		printf("Circularly linked list is empty.\n\n");
}


void CLL_Push_Front(CLL_Node **head, int data) {
	CLL_Node *temp = *head;
	CLL_Node *newNode = calloc(1, sizeof(CLL_Node));
	if (!newNode) {
		printf("Memory error. New node not created.\n");
		return;
	}
	if (!(*head)) {
		newNode->data = data;
		newNode->next = newNode;
		*head = newNode;
		printf("First node with data %d inserted into circularly linked list.\n", data);
		return;
	}
	else {
		newNode->data = data;
		newNode->next = *head;
		while(temp->next != *head) {
			temp = temp->next;
		}
		temp->next = newNode;
		*head = newNode;
	}
	printf("New node with data %d inserted as head of circularly linked list.\n", data);
}


void CLL_Push_Back(CLL_Node **head, int data) {
	CLL_Node *temp = *head;
	CLL_Node *newNode = calloc(1, sizeof(CLL_Node));
	if (!newNode) {
		printf("Memory error. New node not created.\n");
		return;
	}
	if (!(*head)) {
		newNode->data = data;
		newNode->next = newNode;
		*head = newNode;
		printf("First node with data %d inserted into circularly linked list.\n", data);
		return;
	}
	else {
		newNode->data = data;
		newNode->next = *head;
		while(temp->next != *head) {
			temp = temp->next;
		}
		temp->next = newNode;
	}
	printf("New node with data %d inserted as tail of circularly linked list.\n", data);
}


int CLL_Pop_Front(CLL_Node **root) {
	// CLL_Node ** root = &head;
	// &root = & root
	// root = & head pointer 
	// *root = & head struct
	// **root = actual struct
	CLL_Node *temp = *root, *current = *root;
	if(*root == NULL) {
		printf("Error. Circularly linked list is empty. Returning 0.\n");
		return 0;
	}
	int data = (*root)->data;
	if (current->next == *root) {
		free(*root);
		*root = NULL;
		return data;
	}
	while (current->next != *root) {
		current = current->next;
	}
	current->next = (*root)->next;
	*root = (*root)->next;
	free(temp);
	return data;
}


int CLL_Pop_Back(CLL_Node **root) {
	CLL_Node *temp = *root, *current = *root;
	if(*root == NULL) {
		printf("Error. Circularly linked list is empty. Returning 0.\n");
		return 0;
	}
	if (current->next == *root) {
		int data = (*root)->data;
		free(*root);
		*root = NULL;
		return data;
	}
	while (current->next != *root) {
		temp = current;
		current = current->next;
	}
	int data = current->data;
	temp->next = *root;
	free(current);
	return data;
}
	
	
	







	