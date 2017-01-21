#ifndef BASIC_CIRCULAR_ARRAY_QUEUE_H_
#define BASIC_CIRCULAR_ARRAY_QUEUE_H_

#include <stdio.h>
#include <stdlib.h>

/*
Space complexity (for n EnQueue operations): O(n)
Time complexity of EnQueue(): O(1)
Time complexity of DeQueue(): O(1)
Time complexity of IsEmptyQueue(): O(1)
Time complexity of IsFullQueue(): O(1)
Time complexity of QueueSize(): O(1)
Time complexity of DeleteQueue(): O(1)
*/	

typedef struct arrayqueue {
	int front, rear;
	int capacity;
	int* array;	
} ArrayQueue;

ArrayQueue* Queue(int size) {
	ArrayQueue* Q = malloc(sizeof(ArrayQueue));
	if (!Q)
		return NULL;
	Q->capacity = size;
	Q->front = Q->rear = -1;
	Q->array = malloc(Q->capacity * sizeof(int));
	if (!Q->array)
		return NULL;
	return Q;
}

int IsEmptyQueue(ArrayQueue *Q) {
	return (Q->front == -1); // return 1 if empty 0 otherwise
}

int IsFullQueue(ArrayQueue *Q) {
	return ((Q->rear + 1) % Q->capacity == Q->front); // return 1 if empty 0 otherwise
}

int QueueSize(ArrayQueue *Q) {
	if (Q->front == -1 && Q->rear == -1)
		return 0;
	return (Q->capacity - Q->front + Q->rear +1) % Q->capacity; // says 1 when empty, fixed above
}

void QueueStatus(ArrayQueue *Q) {
	if (IsEmptyQueue(Q))
		printf("Queue is empty. Capacity is %d.\n\n", Q->capacity);
	else if (IsFullQueue(Q))
		printf("Queue is full. Capacity is %d.\n\n", Q->capacity);
	else {
		printf("Queue is neither empty nor full. Capacity is %d. ", Q->capacity);
		printf("Queue size is: %d\n\n", QueueSize(Q));
	}	
}

void EnQueue(ArrayQueue *Q, int data) {
	if (IsFullQueue(Q))
		printf("Queue Overflow.\n");
	else {
		Q->rear = (Q->rear+1) % Q->capacity; // at start: rear = (-1 + 1 = 0) % 8 = 0
		Q->array[Q->rear] = data; // array[0] = data
		if (Q->front == -1) // first entry
			Q->front = Q->rear; // front = 0
		printf("%d enqueued.\n", data);
	}
}

int DeQueue(ArrayQueue *Q) {
	int data = 0; // or element which does not exist in queue
	if (IsEmptyQueue(Q)) {
		printf("Queue is empty.\n");
		return 0;
	}
	else {
		data = Q->array[Q->front];
		if (Q->front == Q->rear)
			Q->front = Q->rear = -1;
		else Q->front = (Q->front+1) % Q->capacity; // e.g. 0+1 % 8 = 1;
	}
	return data;
}

void DeleteQueue(ArrayQueue *Q) {
	if (Q) {
		if (Q->array)
			free(Q->array);
		free(Q);
	}
	printf("Queue freed. set pointer to NULL.\n\n");
}

#endif // BASIC_CIRCULAR_ARRAY_QUEUE_H_