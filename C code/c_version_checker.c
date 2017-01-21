#include <stdio.h>

int main(int argc, char *argv[]) {
	
	long x = __STDC_VERSION__;
	
	if (x == 199409)
		printf("C98 as amended in 1994\n");
	else if (x == 199901)
		printf("C99\n");
	else if (x == 201112)
		printf("C11\n");
	else
	printf("Not sure which C version %ld corresponds to.\n", x);
}