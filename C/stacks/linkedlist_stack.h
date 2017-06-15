#ifndef LINKEDLIST_STACK_H_
#define LINKEDLIST_STACK_H_

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Space complexity: O(n)

typedef struct Node {
	int data;
	struct Node *next;
} Node;

typedef struct Stack {
	int size;
	Node *top; // (head)
} Stack;


Stack* CreateStack() {
	Stack* S = malloc(sizeof(Stack));
	S->top = NULL;
	S->size = 0;
	if (!S)
		printf("Memory Error.\n");
	return S;
} // Time complexity: O(1)


void DeleteStack(Stack *S) {
	Node* temp = S->top;	
	while (temp) {
		Node* next = temp->next;
		free(temp);
		temp = next;
	}
	free(S);
} // Time complexity: O(n)


int Push(Stack *S, int data) { // return 1 if successful, 0 o/w
	if (!S) return 0;
	Node* N = malloc(sizeof(Node));
	if (!N) return 0;
	N->data = data;
	N->next = S->top;
	S->top = N;
	S->size++;
	return 1;	
} // Time complexity: O(1)

int Pop(Stack *S) {
	if (!S) {
		printf("Error: Stack is NULL.\n");
		return INT_MIN;
	}
	if (!S->top) {
		printf("Stack is empty.\n");
		return INT_MIN;
	}
	int val = S->top->data;
	Node *temp = S->top;
	S->top = S->top->next;
	S->size--;
	free(temp);
	return val;
} // Time complexity: O(1)

int Top(Stack *S) {
	if (S->size == 0) {
		printf("Stack is empty.\n");
		return INT_MIN;
	}
	else 
		return S->top->data;
} // Time complexity: O(1)

#endif // LINKEDLIST_STACK_H_