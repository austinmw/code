#include <stdio.h>

int main(int argc, char *argv[])
{
	for (int i = strlen(argv[1]) - 1; i >= 0; i--){		
		printf("%c", argv[1][i]);
	}
	printf("EC535\n");
	
	
	int input = atoi(argv[1]);
	printf("%d", input);
	return 0;
}