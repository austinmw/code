#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readinput()
{
#define CHUNK 200
   char* input = NULL;
   char tempbuf[CHUNK];
   size_t inputlen = 0, templen = 0;
   do {
	   fgets(tempbuf, CHUNK, stdin);
	   templen = strlen(tempbuf);
	   inputlen += templen;
	   input = realloc(input, inputlen+1);
	   strcat(input, tempbuf);
	} while (templen==CHUNK-1 && tempbuf[CHUNK-2]!='\n');
	return input;
}

int main()
{
	char* result = readinput();
	printf("And the result is: %s\n", result);
	free(result);
	return 0;
}

/* Note that this is a simplified example with no error checking; in real life you will have to make sure the input is OK by verifying the return value of fgets. 

Also note that at the end if the readinput routine, no bytes are wasted; the string has the exact memory size it needs to have. */