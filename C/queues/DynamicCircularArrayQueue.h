#ifndef DYNAMIC_CIRCULAR_ARRAY_QUEUE_H_
#define DYNAMIC_CIRCULAR_ARRAY_QUEUE_H_

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

/*
Space complexity (for n > 10 EnQueue operations): O(n)
Time complexity of EnQueue(): O(1) (Average)
Time complexity of DeQueue(): O(1)
Time complexity of QueueSize(): O(1)
Time complexity of IsEmptyQueue(): O(1)
Time complexity of IsFullQueue(): O(1)
Time complexity of DeleteQueue(): O(1)
*/

typedef struct dynarrayqueue {
	int front, rear;
	int capacity;
	int *array;
} DynArrayQueue;

DynArrayQueue* CreateDynQueue() {
	DynArrayQueue* Q = malloc(sizeof(DynArrayQueue));
	if (!Q) {
		printf("Failed to create queue. NULL returned.\n");
		return NULL;
	}
	Q->capacity = 1;
	Q->front = Q->rear = -1;
	Q->array = malloc(Q->capacity * sizeof(int));
	if(!Q->array) {
		printf("Failed to create queue. NULL returned.\n");
		return NULL;
	}
	return Q;
}

int IsEmptyQueue(DynArrayQueue *Q){
	// no memory is allocated to queue
	if(!Q){
		return 1;
	}
	else{
		// no element in queue
		return (Q->front == -1);
	}
}

int IsFullQueue(DynArrayQueue *Q){
	return ((Q->rear+1) % Q->capacity == Q->front);
}

int QueueSize(DynArrayQueue *Q){
	int size = 0;
	// no element in queue
	if(Q->front == -1)
		size = 0;
	else if (Q->front <= Q->rear) 
		size = Q->rear - Q->front + 1;
	else 
		size = Q->capacity - Q->front + Q->rear + 1;
	return size;
}

void ResizeQueue(DynArrayQueue *Q){
	int size = Q->capacity;
	int i;
	Q->capacity *= 2;
	Q->array = realloc(Q->array, sizeof(int) * Q->capacity);
	if(!Q->array){
		printf("Memory Error\n");
		return;
	}
	// queue is in rotated format
	if(Q->front > Q->rear){
		for(i=0; i<Q->front; i++)
			Q->array[i+size] = Q->array[i];
		Q->rear = Q->rear+size;
	}
}

void EnQueue(DynArrayQueue *Q, int data){
	// if queue is full, double its size
	if(IsFullQueue(Q))
		ResizeQueue(Q);
	Q->rear = (Q->rear+1) % Q->capacity;
	Q->array[Q->rear] = data;
	// adding first element
	if(Q->front == -1)
		Q->front = Q->rear;
}

int DeQueue(DynArrayQueue *Q){
	int data;
	// queue empty, return error code
	if(IsEmptyQueue(Q)){
		return INT_MIN;
	}
	else{
		data = Q->array[Q->front];
		// only one element in queue
		if(Q->front == Q->rear)
			Q->front = Q->rear = -1;
		else
			Q->front = (Q->front + 1) % Q->capacity;
	}
	return data;
}

void DeleteQueue(DynArrayQueue **Q){
	if(*Q){
		if((*Q)->array)
			free((*Q)->array);
		free(*Q);
		*Q = NULL;
	}
}
 
void PrintQueue(DynArrayQueue *Q){
	int f=0, size, i;
	printf("Queue contents: ");
	if(Q && Q->array){
		f = Q->front;
		size = QueueSize(Q);
		for(i=0 ; i<size ; i++){
			printf("%d ",*(Q->array+f));
			f = (f+1) % Q->capacity;
		}
	}
	printf("\n");
}

void QueueStatus(DynArrayQueue *Q) {
	printf("Front: %d    Rear: %d \n", Q->front, Q->rear);
	if (IsEmptyQueue(Q))
		printf("Queue is empty. Current capacity is %d.\n\n", Q->capacity);
	else if (IsFullQueue(Q)) {
		printf("Queue is full. Current capacity is %d. ", Q->capacity);
		printf("Queue size is: %d\n\n", QueueSize(Q));
	}
	else {
		printf("Queue is neither empty nor full. Current capacity is %d. ", Q->capacity);
		printf("Queue size is: %d\n\n", QueueSize(Q));
	}	
}

#endif // DYNAMIC_CIRCULAR_ARRAY_QUEUE_H_