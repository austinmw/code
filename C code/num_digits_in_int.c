#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char *argv[]) {
	
	int x = 320;
	
	
	int numDigits = floor (log10 (abs (x))) + 1;
	
	printf("number of digits in %d: %d\n", x, numDigits);
	
	
}