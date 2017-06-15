#include <stdio.h>
#include <stdlib.h>
#include "doubly_linked_list.h"

/* advantages: two-way navigation
   disadvantages: more space (extra pointer for each node), slower insertion 
	    	      and deletion (more pointer operations) */

int main(int argc, char *argv[]) {
	
	// create doubly-linked list with one node, check
	DLL *dll =  DLL_Create(5); 	// allocate memory and give location to dll
	printf("length: %d\n", DLL_Length(dll)); // macro for length (uses dll->count)
	DLL_Print_Info(dll);

	// delete only node
	DLL_Delete_Node_Position(dll, 1);
	DLL_Print_Info(dll);

	// insert new node into empty list (as both head and tail), check
	DLL_Insert(dll, 4, 1);
	DLL_Print_Info(dll);

	// insert new node at head, check
	DLL_Insert(dll, 7, 1);
	DLL_Print_Info(dll);

	// insert new node at position 2 (middle), check
	DLL_Insert(dll, 42, 2);
	DLL_Print_Info(dll);

	// insert new node at tail, check
	DLL_Insert(dll, 99, 4);
	DLL_Print_Info(dll);

	// insert another new node at tail, check
	DLL_Insert(dll, 6, 10);
	DLL_Print_Info(dll);
	
	// insert node at position 0 error check
	DLL_Insert(dll, 6, 0);
	DLL_Print_Info(dll);

	// insert new node at position 3, check
	DLL_Insert(dll, 555, 3);
	DLL_Print_Info(dll);	

	// push_front new node, check
	DLL_Push_Front(dll, 8);
	DLL_Print_Info(dll);	

	// push_back new node, check
	DLL_Push_Back(dll, 101);
	DLL_Print_Info(dll);	
	
	// remove node error check
	DLL_Delete_Node_Position(dll, 0);
	DLL_Print_Info(dll);	

	// remove first node, check
	DLL_Delete_Node_Position(dll, 1);
	DLL_Print_Info(dll);	

	// remove tail node, check
	DLL_Delete_Node_Position(dll, DLL_Length(dll));
	DLL_Print_Info(dll);	

	// remove middle node, check
	DLL_Delete_Node_Position(dll, 2);
	DLL_Print_Info(dll);	
	
	// erase all but 1 node	
	int stop = dll->count -1;
	for (int i = 0; i < stop; i++) {
		DLL_Delete_Node_Position(dll, 1);
	}
	DLL_Print_Info(dll);
	
	// delete last node	
	DLL_Delete_Node_Position(dll, 1);
	DLL_Print_Info(dll);

	// insert 10 new nodes with data 1 through 10, check
	for (int i = 1; i <= 10; i++){
		DLL_Insert(dll, i, i);
	}
	DLL_Print_Info(dll);

	// erase entire list, check (error expected, no info on because list is gone)
	DLL_Erase(&dll);
	DLL_Print_Info(dll);
	
	// recreate doubly linked list
	dll = DLL_Create(1);
	for(int i = 2; i <= 10000; i++)
		DLL_Push_Back(dll, i);
	DLL_Print_Info(dll);
	
	// redestroy entire list
	DLL_Erase(&dll);
	DLL_Print_Info(dll);
	
}