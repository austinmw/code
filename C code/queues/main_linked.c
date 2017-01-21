#include <stdio.h>
#include <stdlib.h>
#include "LinkedListQueue.h"

int main() {
	
	// create empty queue
	Queue *Q = CreateQueue();
	
	// enqueue nodes, check
	for (int i = 0; i < 10; i++) {
		printf("Enqueued %d\n", i);
		EnQueue(Q, i);
		PrintQueue(Q);
	}
	
	// dequeue nodes, check
	for (int i = 0; i <= 10; i++) {
		printf("Dequeued: %d\n", DeQueue(Q));
		PrintQueue(Q);
	}
	
	// delete queue, check
	DeleteQueue(&Q);
	PrintQueue(Q);

	return 0;
}
