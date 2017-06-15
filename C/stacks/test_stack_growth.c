#include <stdio.h>
#include <stdlib.h>



void stackGrowth(int *temp) {
	int temp2;
	printf("\nAddress of first local variable: %p", temp);
	printf("\nAddress of second local variable: %p", &temp2);
	if (temp < &temp2) 
		printf("\nSTack is growing downwards");
	else
		printf("\nStack is growing upwards");
	
}

int testStackGrowth() {
	int temporary;
	stackGrowth(&temporary);
	exit(0);
}

int main(int argc, char *argv[]) {
	
	testStackGrowth();
	
}