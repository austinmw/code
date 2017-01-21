#include <stdio.h>
#include <stdlib.h>

// Node
typedef struct node {
	int data;
	struct node *next;
} Node;

// Block of nodes
typedef struct linkedblock {
	struct linkedblock *next;
	Node *head;
	int nodeCount;
} LinkedBlock;

// Number of nodes per block
int blockSize = 4;

///////////////////////////////////////////////////////////////////////////////

// Create an empty block
LinkedBlock* newLinkedBlock(){
	LinkedBlock* block = malloc(sizeof(LinkedBlock));
	block->next = NULL;
	block->head = NULL;
	block->nodeCount = 0;
	return block;
}

// Create a node
Node* newNode(int data){
	Node* temp = malloc(sizeof(Node));
	temp->data = data;
	temp->next = NULL;
	return temp;
}













///////////////////////////////////////////////////////////////////////////////

int main() {	
	
	return 0;	
}