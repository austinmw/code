#ifndef DOUBLY_ENDED_QUEUE_H_
#define DOUBLY_ENDED_QUEUE_H_

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct node {
	int data;
	struct node* next;
} Node;

typedef struct queue {
	Node* head;
	Node* tail;
	int size;
} Queue;

Queue* CreateDEQ() {
	Queue* Q = malloc(sizeof(Queue));
	if (!Q) {
		printf("Memory error\n");
		return NULL;
	}
	Q->head = NULL;
	Q->tail = NULL;
	Q->size = 0;
	return Q;
}

void PrintQueue(Queue *Q) {
	if (!Q) {
		printf("\nQueue not created.\n\n");
		return;
	}
	if (!Q->head) {
		printf("\nQueue is empty.\n\n");
		return;
	}
	printf("\nQueue head data: %d\n", Q->head->data);
	printf("Queue tail data: %d\n", Q->tail->data);
	printf("Queue size: %d\n", Q->size);
	printf("Front -> ");
	Node *temp;
	temp = Q->head;
	while(temp) {
		printf("%d -> ", temp->data);
		temp = temp->next;
	}
	printf("NULL\n\n");
}

void PushBack(Queue *Q, int data) {
	if (!Q) {
		printf("Can't add nodes until queue is created.\n");
		return;
	}
	Node* newNode = malloc(sizeof(Node));
	newNode->data = data;
	newNode->next = NULL;
	if (!Q->head) 
		Q->head = Q->tail = newNode;
	else {
		Q->tail->next = newNode;
		Q->tail = newNode;	
	}
	Q->size++;
	printf("New node with data %2d inserted to end of queue.\n", data);
	return;
}

void PushFront(Queue *Q, int data) {
	if (!Q) {
		printf("Can't add nodes until queue is created.\n");
		return;
	}
	Node* newNode = malloc(sizeof(Node));
	newNode->data = data;
	if (!Q->head) {
		newNode->next = NULL;
		Q->head = Q->tail = newNode;
	}
	else {
		newNode->next = Q->head;
		Q->head = newNode;
	}
	Q->size++;
	printf("New node with data %2d inserted to front of queue.\n", data);
	return;
}

int PopBack(Queue *Q) { // O(n) compared to other operations being O(1)?
	int data;
	if (!Q) {
		printf("Queue doesn't exist. Returning INT_MIN.\n");
		return INT_MIN;
	}
	if (!Q->head) {
		printf("Queue is empty. Returning INT_MIN.\n");
		return INT_MIN;
	}
	data = Q->tail->data;
	Node* temp = Q->head;
	for (int i=0; i < Q->size-2; i++) 
		temp = temp->next;	
	Q->tail = temp;
	free(Q->tail->next);
	Q->tail->next = NULL;
	Q->size--;
	return data;
}

int PopFront(Queue *Q) {
	int data;
	if (!Q) {
		printf("Queue doesn't exist. Returning INT_MIN.\n");
		return INT_MIN;
	}
	if (!Q->head) {
		printf("Queue is empty. Returning INT_MIN.\n");
		return INT_MIN;
	}
	data = Q->head->data;
	Node* temp = Q->head;
	Q->head = Q->head->next;
	free(temp);
	Q->size--;
	return data;
}


void DeleteQueue(Queue **Q) {
	if (*Q) {
		if ((*Q)->head) {
			Node  *temp, *iterator;
			iterator = (*Q)->head;
			while (iterator) {
				temp = iterator;
				iterator = iterator->next;
				free(temp);
			}
		}
		free(*Q);
		*Q = NULL;	
		printf("\nQueue deleted.\n\n");
	}
	return;
}




#endif // DOUBLY_ENDED_QUEUE_H_