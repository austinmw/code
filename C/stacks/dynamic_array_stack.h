#ifndef DYNAMIC_ARRAY_STACK_H_
#define DYNAMIC_ARRAY_STACK_H_

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Space complexity: O(n)

typedef struct dynarraystack {
	int top;
	int capacity;
	int *array;
} DynArrayStack;

DynArrayStack* CreateStack() {
	DynArrayStack* S = malloc(sizeof(DynArrayStack));
	if (!S) {
		printf("Error: Could not create stack.\n");
		return NULL;
	}
	S->capacity = 1;
	S->top = -1;
	S->array = malloc(S->capacity * sizeof(int));
	if (!S->array) {
		printf("Error: could not create stack.\n");
		return NULL;
	}	
	return S;	
} // Time complexity: O(1)

int isFullStack(DynArrayStack *S) {
	return (S->top == S->capacity-1);
} // Time complexity: O(1)

void DoubleStack(DynArrayStack *S) {
	S->capacity *= 2;
	if(!(S->array = realloc(S->array, S->capacity*sizeof(int))))
		printf("Realloc failed.\n");
} 

void Push(DynArrayStack *S, int data) {
	if (isFullStack(S))
		DoubleStack(S);
	S->array[++S->top] = data;
} // Time complexity: O(1) (amortized)

int isEmptyStack(DynArrayStack *S) {
	return S->top == -1;
} // Time complexity: O(1)

int Top(DynArrayStack *S) {
	if(isEmptyStack(S))
		return INT_MIN;
	return S->array[S->top];		
} // Time complexity: O(1)

int Pop(DynArrayStack *S) {
	if (isEmptyStack(S)) {
		printf("Array is empty. Returning INT_MIN.\n");
		return INT_MIN;
	}
	return S->array[S->top--];
} // Time complexity: O(1)

void DeleteStack(DynArrayStack *S) {
 	if (S) {
		if (S->array)
			free(S->array);
		free(S);
		printf("Stack deleted.\n");
	}
}


#endif // DYNAMIC_ARRAY_STACK_H_
