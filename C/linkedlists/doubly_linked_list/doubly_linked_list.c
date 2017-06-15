#include <stdio.h>
#include <stdlib.h>
#include "doubly_linked_list.h"


/* Constructor for doubly linked list data structure with head, tail and count, creates one 
new node, increases count to 1, sets both the head and the tail to equal this new node,
returns the doubly linked list structure */
DLL* DLL_Create(int data) {
	DLL *dll = calloc(1, sizeof(DLL));
	if (!dll) {
		printf("Failed to create dll\n");
	}
	else {
		DLL_Node *newNode = calloc(1, sizeof(DLL_Node)); // newNode->prev/next set to NULL
		dll->head = newNode;
		dll->tail = newNode;
		newNode->data = data;
		dll->count = 1;
		printf("Doubly linked list created with one node set as both head and tail.\n");
	}
	return dll; // null initializes contents, returns address
}


// Print all information about doubly linked list (O(n), traverses twice)
void DLL_Print_Info(DLL *dll) {
	if (dll) {
		if (dll->head) {
			// print dll link representation
			DLL_Node *temp = dll->head;
			printf("DLL representation: NULL");
			do {
				printf(" <- %d ->", temp->data);
				temp = temp->next;
			}
			while (temp != NULL);
			printf(" NULL\n");
			
			// print length, head, tail
			printf("length: %d\n", dll->count);
			printf("head data: %d, head address: %p\n", dll->head->data, dll->head);
			printf("tail data: %d, tail address: %p\n", dll->tail->data, dll->tail);
			
			// check that ends of list point to NULL
			if ((!dll->head->prev) && (!dll->tail->next))
				printf("Both head->prev and tail->next point to NULL successfully\n");	
			else
				printf("Error, one or both ends of dll do not point to NULL\n");
			
			// print positions, data, and addresses
			int i = 1;
			temp = dll->head;
			do {
				printf("position: %d, data: %d\t", i, temp->data);	
				printf("prev addr: %p\t", temp->prev);
				if(!temp->prev)
					printf("\t\t");
				printf("current addr: %p\tnext addr: %p\n",temp, temp->next);	
				temp = temp->next;
				i++;
			}
			while (temp != NULL);	
			printf("\n\n");
		}
		else {
		printf("Doubly linked list has no nodes.\n");
		printf("dll->head: %p\n", dll->head);
		printf("dll->tail: %p\n", dll->tail); 
		printf("dll->count: %d\n\n\n", dll->count);
		
		}
	}
	else 
		printf("Error: DLL points to NULL.\n\n");
}


// Insert new node with desired data at desired position
void DLL_Insert(DLL *dll, int data, int position) {	
	if (dll) {
		int k = 1;
		DLL_Node *newNode, *temp;
		newNode = calloc(1, sizeof(DLL_Node));
		if (!newNode) { // if calloc didn't return an address 
			printf("Memory error");
		}
		newNode->data = data;
		
		if (dll->head) {
			if (position <= 0) {
				printf("Error: Insertion failed. Doubly linked list indexing starts at position 1.\n");
				free(newNode);
			}
			// insert at head
			else if (position == 1) {
				temp = dll->head;
				dll->head = newNode;
				dll->head->prev = NULL;
				dll->head->next = temp;		
				temp->prev = newNode;
				dll->count++;
				printf("New node inserted at head of doubly linked list.  ");
				printf("addr: %p, data: %d\n", newNode, newNode->data);
			}
			// insert between head and tail
			else if (position <= dll->count) {
				temp = dll->head;
				while((k != position) && (temp->next != NULL)) {
					temp = temp->next;
					k++;
				}
				temp->prev->next = newNode;
				newNode->prev = temp->prev;
				newNode->next = temp;
				temp->prev = newNode;
				dll->count++;
				printf("New node inserted at position %d of doubly linked list.  ", position);
				printf("addr: %p, data: %d\n", newNode, newNode->data);
			}
			// insert at tail
			else if (position > dll->count) {
				if (position > dll->count+1)
					printf("Desired position exceeds length+1. Inserting at tail (length+1) instead.\n");
				newNode->next = NULL;
				newNode->prev = dll->tail;
				dll->tail->next = newNode;
				dll->tail = newNode;
				dll->count++;
				printf("New node inserted at tail of doubly linked list.  ");
				printf("addr: %p, data: %d\n", newNode, newNode->data);
			}
		}
		else {// insert first node (previously empty)
			dll->head = newNode;
			dll->tail = newNode;
			dll->count++;
			printf("First node inserted at position 1.  ");
			printf("addr: %p, data: %d\n", newNode, newNode->data);
		}
	}
	else 
		printf("Error: DLL points to NULL.\n");
}


// Insert new node with desired data at head
void DLL_Push_Front(DLL *dll, int data) {
	if (dll) {
		DLL_Node *newNode, *temp;
		newNode = calloc(1, sizeof(DLL_Node));
		if (!newNode) { // if calloc didn't return an address 
			printf("Memory error");
		}
		newNode->data = data;
		temp = dll->head;
		dll->head = newNode;
		dll->head->prev = NULL;
		dll->head->next = temp;		
		temp->prev = newNode;
		dll->count++;
		printf("New node inserted at head of doubly linked list.  ");
		printf("addr: %p, data: %d\n", newNode, newNode->data);
	}
	else {
		printf("Error: DLL points to NULL.\n");
	}
}


// Insert new node with desired data at tail
void DLL_Push_Back(DLL *dll, int data) {
	if (dll) {
		DLL_Node *newNode, *temp;
		newNode = calloc(1, sizeof(DLL_Node));
		if (!newNode) { // if calloc didn't return an address 
			printf("Memory error");
		}
		newNode->data = data;
		newNode->next = NULL;
		newNode->prev = dll->tail;
		dll->tail->next = newNode;
		dll->tail = newNode;
		dll->count++;
		printf("New node inserted at tail of doubly linked list.  ");
		printf("addr: %p, data: %d\n", newNode, newNode->data);
	}
	else {
		printf("Error: DLL points to NULL.\n");
	}	
}


// Delete node at desired position
void DLL_Delete_Node_Position(DLL *dll, int position) {
	// error check
	if (position <= 0) 
		printf("Error: Deletion failed. Doubly linked list indexing starts at position 1.\n");
	else if(position > dll->count)
		printf("Error: Deletion failed. No node is at position %d. List length is %d.\n", position, dll->count);
	// delete only node	
	else if ((dll->count == 1) && (position == 1)) { // This correct?????
		DLL_Node *temp = dll->head;
		free(temp);
		dll->head = NULL;
		dll->tail = NULL;
		dll->count--;
		printf("Deleted last node left in doubly linked list.\n");	
	}	
	// delete head node
	else if (position == 1) {
		DLL_Node *temp = dll->head;
		dll->head = dll->head->next;
		if (dll->head != NULL) {
			dll->head->prev = NULL;	
		}
		free(temp);	
		dll->count--;		
		printf("Deleted head node from doubly linked list.\n");	
	}
	// delete intermediate node
	else if (position < dll->count) {
		int k = 1;
		DLL_Node *temp = dll->head;
		while((k != position) && (temp->next != NULL)) {
			temp = temp->next;
			k++;
		}
		temp->prev->next = temp->next;
		temp->next->prev = temp->prev;
		free(temp);
		dll->count--;
		printf("Deleted node that was at position %d from doubly linked list.\n", position);
	}
	// delete tail node
	else if (position == dll->count) {
		DLL_Node *temp = dll->tail;
		dll->tail = dll->tail->prev;
		if (dll->tail != NULL) {
			dll->tail->next = NULL;
		}
		free(temp);
		dll->count--;
		printf("Deleted tail node from doubly linked list.\n");	

	}
	else
		printf("Unknown error occurred. Deletion failed.\n");
}




// Delete node at desired address
void DLL_Delete_Node_Address(DLL *dll, DLL_Node *node) {
}





// Erase entire doubly linked list
void DLL_Erase(DLL **dll) {
	if (*dll) {
		if ((*dll)->head) {
			DLL_Node *temp = (*dll)->head;
			for (int i=1; i<(*dll)->count;i++){
				temp = temp->next;
				free(temp->prev);
			}		
			free(temp);
			(*dll)->head = NULL;
			(*dll)->tail = NULL;	
			(*dll)->count = 0;
			// free dll, then set to NULL (stackoverflow recommended way, so you don't accidentally access)
			free(*dll);
			(*dll) = NULL;
			printf("Erased doubly linked list.\n");
		}
		else 
			printf("Head points to NULL.\n");
	}
	else 
		printf("DLL already points to NULL.\n");
}






// Clear data of each node 
void DLL_Clear() {
	
}



void DLL_Shift_Left() {
	
}

void DLL_Shift_Right(){
	
}


