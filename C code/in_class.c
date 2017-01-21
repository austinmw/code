#include <stdio.h>
#include <stdlib.h>


void print_binary(uint32_t x)
{
    for (unsigned bit = 1u << 31; bit != 0; bit >>= 1)
	putchar((x & bit) ? '1' : '0');
}


int main(int argc, char *argv[]) {
	if (argc == 2) {
		// Get input argument and convert to int
		uint32_t input = atoi(argv[1]);
		
		// Get Hex
		char test[8] = "0";
		snprintf(test,8,"%X",input);
		printf("0x%s", test);
		printf("\t");
		
		// Fill Zeros
		int j;
		for (j=0; j<=7; j++) {
			if (test[j] == NULL)
				test[j] = '0';
		}
		
		// Print Big Endian		
		int i;
		printf("0x");
		for(i=1;i<=7;i=i+2) {
			printf("%c%c",test[i], test[i-1]);
		}
		printf("\t");
		
		// New number in decimal





		
		//int b = (test[0] << 8) | test[1];
		
		//printf("%d",b);
		
		return 0;
	}
	else return 0;
}






