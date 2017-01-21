#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum { MAXL = 64 };

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



int main (int argc, char **argv) {

	char **iflines = NULL;
	size_t i, numLines = 0;
	FILE *inputfp = argc > 1 ? fopen (argv[1], "r") : stdin;

	// read file into dynamically allocated 'iflines' 
	if (!(iflines = readfile (inputfp, &numLines))) return 1;

	// close file
	if (inputfp != stdin) fclose (inputfp);  
	
}