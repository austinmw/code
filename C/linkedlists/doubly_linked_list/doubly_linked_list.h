#ifndef DOUBLY_LINKED_LIST_H_
#define DOUBLY_LINKED_LIST_H_

typedef struct dll_node {
	int data;
	struct dll_node *prev;
	struct dll_node *next;
} DLL_Node;

typedef struct DLL_ {
	int count;
	DLL_Node *head;
	DLL_Node *tail;
} DLL;

#define DLL_Length(A) ((A)->count) // O(1)
DLL *DLL_Create(); // O(1)
void DLL_Print_Info(DLL *dll); // O(n)	{c1*n + c2*n + c3}
void DLL_Insert(DLL *dll, int data, int position); // O(n)
void DLL_Push_Front(DLL *dll, int data); // O(1)
void DLL_Push_Back(DLL *dll, int data); // O(1) 

// still working on these:
void DLL_Delete_Node_Position(DLL *dll, int position); // O(n)
void DLL_Delete_Node_Address(DLL *dll, DLL_Node *node); // O(1)?? prob still O(n) actually, double check this
void DLL_Erase(DLL **dll);
void DLL_Clear();
DLL_Node *DLL_Pop_Front();
DLL_Node *DLL_Pop_Back();

#endif // DOUBLY_LINKED_LIST_H_