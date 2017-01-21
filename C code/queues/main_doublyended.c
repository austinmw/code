#include <stdio.h>
#include "DoublyEndedQueue.h"

int main() {
		
	Queue* Q = CreateDEQ();
	
	// PushBack, check
	for (int i = 0; i<10;i++)
		PushBack(Q, i+1);
	PrintQueue(Q);

	// PushFront, check
	for (int i = 0; i>=-10;i--)
		PushFront(Q, i);
	PrintQueue(Q);

	// PopBack, check
	for (int i=0; i<10;i++)
		printf("PopBack: %d\n", PopBack(Q));
	PrintQueue(Q);
	
	// PopFront, check
	for (int i = 0; i <= 11; i++)
		printf("PopFront: %d\n", PopFront(Q));
	PrintQueue(Q);
	
	// DeleteQueue
	DeleteQueue(&Q);
	
	return 0;
}