#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "array_stack.h"
//#include "linkedlist_stack.h"
//#include "dynamic_array_stack.h"

int main() {
	
	
	// Basic Array Stack Implementation 	
	// #include "array_stack.h"
	
	// create stack and set capacity
	ArrayStack* S = CreateStack(100000);
	
	// fill stack
	for (int i = 1; i <= 100000; i++)
		Push(S, i);
		
	// try pushing past capacity, check error
	Push(S, 42);	

	// pop all elements of stack
	for (int i = 0; i < 100000; i++)
		printf("%d\n", Pop(S));
		
	// try popping empty stack, check error
	Pop(S);

	// stack is empty but still has pointer
	printf("address of stack: %p\n", S);
	
	// delete stack, check pointer again
	DeleteStack(&S);
	printf("address of stack: %p\n", S);
	



/*	
	// Dynamic Array Stack Implementation	
	// #include "dynamic_array_stack.h"
	
	// create stack
	DynArrayStack *S = CreateStack();
	
	// fill stack
	for (int i = 1; i <= 10; i++)
		Push(S, i);
	
	// try pushing past capacity, no error (realloc's)
	Push(S, 42);
	
	// top of stack
	printf("Top of stack is %d\n", Top(S));
	
	// pop all elements of stack
	while (Top(S) != INT_MIN) {
		printf("popped: %d\n", Pop(S));
	}
	
	// delete stack, check pointer again
	DeleteStack(S);
*/

/*
	// Linked List Stack Implementation
	// #include "linkedlist_stack.h"
	
	// create stack
	Stack *S = CreateStack();
	
	// push
	for (int i = 0; i < 10; i++)
		Push(S, i);
	
	// check top
	printf("%d\n\n", Top(S));
	
	// pop until empty
	while(Top(S) != INT_MIN) 
		printf("%d\n", Pop(S));
	
	// try to see top, check that stack is empty
	printf("%d\n\n", Top(S));
	
	// try to pop, check that stack is empty
	printf("%d\n", Pop(S));
	
	// delete, set to NULL
	DeleteStack(S);
	S = NULL;
*/	
	
	
	return 0;
}
