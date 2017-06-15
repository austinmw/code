#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
	
	srand(time(NULL));
	
	// print random numbers
	for (int i = 0; i < 1000; i++) 
		printf("%d\n", rand());
		
		
	// coin flips
	for (int i = 0; i < 1000; i++) {
		printf("%d\n",rand() < RAND_MAX/2?1:0);
	}
	
	
	// coin flip counts, distribution
	int x, heads = 0, tails = 0;
	double headDist, tailDist;
	for (int i = 0; i < 10; i++) {
		
		x = rand() < RAND_MAX/2?1:0;
		if (x == 1)
			heads++;
		else 
			tails++;
	}
	printf("heads: %d\ttails: %d\n", heads, tails);
	headDist = (double)heads/((double)heads+(double)tails);
	tailDist = 1 - headDist;
	printf("headDist: %f\ttailDist: %f\n", headDist, tailDist);
	
	
}