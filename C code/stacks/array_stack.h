#ifndef ARRAY_STACK_H_
#define ARRAY_STACK_H_

#include <stdio.h>
#include <stdlib.h>

// Space complexity: O(n)

typedef struct arraystack {
	int top;
	int capacity;
	int *array;
} ArrayStack;

ArrayStack* CreateStack(int capacity) {
	ArrayStack *S = malloc(sizeof(ArrayStack));
	if (!S)
		return NULL;
	S->capacity = capacity;
	S->top = -1;
	S->array = malloc(S->capacity * sizeof(int));
	if(!S->array)
		return NULL;
	return S;
} 

int isEmptyStack(ArrayStack *S) {
	return (S->top == -1); // 1 if true, 0 if false
} // Time complexity: O(1)

int isFullStack(ArrayStack *S) {
	 return (S->top == S->capacity -1); // 1 if true, 0 if false
} // Time complexity: O(1)

void Push(ArrayStack *S, int data) {
	if (isFullStack(S))
		printf("Error: Stack Overflow.\n");
	else
		S->array[++S->top] = data;	
} // Time complexity: O(1)

int Pop(ArrayStack *S) {
	if (isEmptyStack(S)) {
		printf("Stack is empty.\n");
		return 0;
	}
	else 
		return (S->array[S->top--]);
} // Time complexity: O(1)

void DeleteStack(ArrayStack **S) {
	if (*S) {
		if ((*S)->array) {
			free((*S)->array);
			(*S)->array = NULL;	
		}	
		free((*S));
		(*S) = NULL;
	}
	printf("Stack deleted.\n");
}

#endif // ARRAY_STACK_H_

