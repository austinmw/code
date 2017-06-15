#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bits.h"

enum { MAXL = 64 };

// Function declarations
char **readfile (FILE *inputfp, size_t *numLines);
void stringstointarray (unsigned int *decimals, size_t numLines, char **iflines);

unsigned int BinaryMirror(unsigned int);

int main (int argc, char **argv) {

	char **iflines = NULL;
	size_t i, numLines = 0;
	FILE *inputfp = argc > 1 ? fopen (argv[1], "r") : stdin;

	// read file into dynamically allocated 'iflines' 
	if (!(iflines = readfile (inputfp, &numLines))) return 1;

	// close file
	if (inputfp != stdin) fclose (inputfp);  
	
	// convert strings to decimals
	unsigned int decimals[numLines];
	stringstointarray (decimals, numLines, iflines);

	// convert decimals to binary mirrors
	unsigned int mirrors[numLines];
	for (i = 0; i < numLines; i++)	
		mirrors[i] = BinaryMirror(decimals[i]);
	
	// count number of 10's in binary number
	unsigned int tencount[numLines];
	for (i = 0; i < numLines; i++)
		tencount[i] = SequenceCount(decimals[i]);

	// print to output file
	FILE * outfp = fopen (argv[2], "w");
	int k = 0;
	for (k = 0; k < numLines; k++) 
		fprintf(outfp, "%*u\t%*d\n", 10, mirrors[k], 2, tencount[k]);
	fclose (outfp);
	
	// free allocated memory 
	for (i = 0; i < numLines; i++)    
		free (iflines[i]);
	free (iflines);
	
	return 0;		
}

// return allocated pointer to array of pointers containing * lines from 'inputfp'
char **readfile (FILE *inputfp, size_t *numLines)
{
	if (!inputfp) return NULL;

	char **filebuffer = NULL;
	char *line = NULL;
	size_t maxl = MAXL, nbytes = 0;
	ssize_t nchar = 0;

	// allocate MAXL pointers 
	filebuffer = calloc (MAXL, sizeof *filebuffer);

	while ((nchar = getline (&line, &nbytes, inputfp)) != -1)
	{   // remove newline or carriage return
		while (nchar && (line[nchar-1] == '\n' || line[nchar-1] == '\r'))
			line[--nchar] = 0;

		filebuffer[(*numLines)++] = strdup (line); // allocate & copy 

		// realloc as required 
		if (*numLines == maxl) filebuffer = realloc (filebuffer, maxl);
	}
	free (line);  // free getline allocated memory 

	return filebuffer;
}

// converts string array to decimal array
void stringstointarray (unsigned int *decimals, size_t numLines, char **iflines) 
{
	size_t i = 0;
	char *ptr;
		
	for (i = 0; i <= numLines-1; i++) 	
		decimals[i] = strtoul(iflines[i], &ptr, 10);		
}