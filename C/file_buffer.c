#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	char* buffer;
	size_t result;
	long lSize;
	FILE *pFile;

	pFile = fopen("sampleinput.txt","r");
	if (pFile==NULL) {fputs ("File error",stderr); exit (1);}

	// obtain file size:
	fseek (pFile , 0 , SEEK_END);
	lSize = ftell (pFile);
	rewind (pFile);
	buffer = malloc(lSize);

	// copy the file into the buffer:
	result = fread (buffer,1,lSize,pFile);
	if (result != lSize) {fputs ("Reading error 2",stderr); exit (3);}

	/* the whole file is now loaded in the memory buffer. */
	fclose (pFile);
	
	
	printf("%s",buffer);
}