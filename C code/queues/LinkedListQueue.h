#ifndef LINKED_LIST_QUEUE_H_
#define LINKED_LIST_QUEUE_H_

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

/*
Space complexity (for n EnQueue operations): O(n)
Time complexity of EnQueue(): O(1) (Average)
Time complexity of DeQueue(): O(1)
Time complexity of IsEmptyQueue(): O(1)
Time complexity of DeleteQueue(): O(1)
Time complexity of PrintQueue(): O(n)
*/

typedef struct node {
	int data;
	struct node *next;
} Node;

typedef struct queue {
	Node *front;
	Node *rear;
} Queue;

Queue* CreateQueue() {
	Queue *Q;
	Q = malloc(sizeof(Queue));
	if (!Q)
		return NULL;
	Q->front = Q->rear = NULL;
	return Q;
}

int IsEmptyQueue(Queue *Q) {
	return (Q->front == NULL);
}

void EnQueue(Queue *Q, int data) {
	Node* newNode = malloc(sizeof(Node));
	if (!newNode) {
		printf("Memory error creating new node for queue.\n");
		return;
	}
	newNode->data = data;
	newNode->next = NULL;	
	// no nodes
	if (Q->front == NULL && Q->rear == NULL) {
		Q->front = Q->rear = newNode;
		return;	
	}
	// one or more nodes
	else {
		Q->rear->next = newNode;
		Q->rear = newNode;
	}
	return;
}

int DeQueue(Queue *Q) {
	if (!Q->front) {
		printf("Queue is empty.\n");
		return INT_MIN;
	}
	Node* temp = Q->front;
	if (Q->front == Q->rear)
		Q->front = Q->rear = NULL;
	else
		Q->front = Q->front->next;
	int data = temp->data;
	free(temp);
	return data;
}

void PrintQueue(Queue *Q) {
	if (!Q) {
		printf("Queue not created.\n");
		return;
	}
	Node* temp = Q->front;
	printf("Front -> ");
	while (temp) {
		printf("%d -> ", temp->data);
		temp = temp->next;
	}
	printf("NULL\n\n");
}

void DeleteQueue(Queue **Q) {
	if (*Q) {
		Node *temp, *iterator;
		
		iterator = (*Q)->front;
		while(iterator) {
			temp = iterator->next;
			free(iterator);
			iterator = temp;
		}		
		free(*Q);
		*Q = NULL;
		printf("Queue deleted.\n");
	}
	return;
}

#endif // LINKED_LIST_QUEUE_H_