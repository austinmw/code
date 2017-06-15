#ifndef LINKED_LIST_H_
#define LINKED_LIST_H_

typedef struct node_ {
	int data;
	struct node_ *next;
} Node;

Node* LLCreate(int data); // O(1)
int LLLength(Node *head); // O(n)
void LLInsert(Node **head, int data, int position); // O(n)
void LLDeleteNode(Node **head, int position); // O(n)
void LLDeleteList(Node **head); // O(n)

#endif // LINKED_LIST_H_


/* 
declaring head as a variable instead of a pointer would do shallow copies in C

The nodes need to be allocated on the heap (using "new"). This involves using pointers. Secondly, to traverse the list, you need to have a reference point you can move.

linked list 101: you store the address of the first element and each element has a pointer to another element of same type (or NULL, if it's the last one). That way you can easily point the head to another node in memory, just by overriding the value the variable head contains (which is a memory address).



How does 



*/