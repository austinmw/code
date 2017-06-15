#include <time.h>
#include <stdio.h>


void function() {
	int i;
	for (i = 0; i < 1000; i++) {
		printf("%d ", i);
	}
}


int main()
{
	time_t start, end;
	start = clock();
	
	// Function here
	function();	
	
	
	end = clock();
	printf("\n\nTime taken: %lf\n", ((double)(end-start)/CLOCKS_PER_SEC));

	return(0);
}