#include <stdio.h>
#include <stdlib.h>
#include "DynamicCircularArrayQueue.h"

int main() {
	
	// create queue
	printf("Create queue\n");
	DynArrayQueue *Q = CreateDynQueue();
	PrintQueue(Q);
	QueueStatus(Q);
	
	// enqueue 10, check
	for (int i = 1; i <= 10; i++) {
		printf("EnQueue %d\n", i);
		EnQueue(Q, i);
		PrintQueue(Q);
		QueueStatus(Q);
	}
	
	// 	dequeue 5, check
	for (int i = 1; i <= 5; i++) {	
		printf("DeQueue %d\n", DeQueue(Q));
		PrintQueue(Q);
		QueueStatus(Q);
	}
	
	// enqueue 10, check
	for (int i = 11; i <= 20; i++) {
		printf("EnQueue %d\n", i);
		EnQueue(Q, i);
		PrintQueue(Q);
		QueueStatus(Q);
	}

	// 	dequeue 15, check
	for (int i = 1; i <= 15; i++) {	
		printf("DeQueue %d\n", DeQueue(Q));
		PrintQueue(Q);
		QueueStatus(Q);
	}

	// delete queue
	printf("Deleting Queue\n");
	DeleteQueue(&Q);
	PrintQueue(Q);
	
	return 0;
}


