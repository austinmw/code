#include <stdio.h>
#include <stdlib.h>
#include "BasicCircularArrayQueue.h"

int main() {
	
	// create queue, status
	ArrayQueue* Q = Queue(8);
	QueueStatus(Q);
	
	// enqueue, status
	for (int i = 1; i <= 9; i++) {
		EnQueue(Q, i);
		QueueStatus(Q);	
	}

	// dequeue, return value, status
	for (int i = 1; i <= 9; i++) {
		int data = DeQueue(Q);
		printf("Data returned: %d\n", data);
		QueueStatus(Q);	
	}
	
	// delete queue
	DeleteQueue(Q);
	Q = NULL;
	
	return 0;
}