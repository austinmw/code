#include <stdio.h>
#include <stdlib.h>







int main(int argc, char *argv[]) {
	
	
	
	FILE *fp;
	int size = 11;
	char ** buffer = malloc(size);
	
	// Open file for reading
	fp = fopen("sampleinput.txt", "r");
	if(fp == NULL) 
	{
		perror("Error opening file");
		return(-1);
	}
	
	// Error check buffer
	if (buffer == NULL)
	{
		perror("Error allocating memory");
		return(-1);
	}
	
	printf("%c", buffer[0][0]);
	
	
	
	
	return(0);	
}

// need to free(buffer) when done with it
