#include <stdio.h>
#include <stdlib.h>


typedef struct node {
	int data;
	struct node *next;
} Node;


void function(Node **root);


int main(int argc, char *argv[]) {
	
	Node *head = calloc(1, sizeof(Node));
	// &root = just &root
	// root = & of calloc'ed block
	// *root = struct pointed to by root
	// could point to a different struct Node by *root = newNode
	
	head->data = 5; 
	// data member of struct pointed to by root = 5 ( same as (*root).data = 1 )

	function(&head); 
	// passing in &root

	printf("%d", head->data);	
	// check
}


void function(Node **root) { // Node ** root = &head;
	
	// &root = &root
	// root = &head
	// *root = &struct
	// **root = actual struct
	
	// To change the value of the structs data member:
	// Option 1:
	(**root).data = 3; // same as (*root)->data = 3;
	
	// Option 2:
	(*root)->data = 4; // same as (**root).data = 4;
	
	// Option 3:
	Node *temp = *root;
	temp->data = 6; // same as (*temp).data = 6;
	// now,
	// &temp = &temp
	// temp = *root = &struct
	// *temp = actual struct;
	
	
	// What does root->data equal? Nothing: same as (*root).data, *root is an address, doesn't have data member
}