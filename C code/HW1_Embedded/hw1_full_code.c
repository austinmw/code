# include <stdio.h>
# include <stdlib.h>
# include <string.h>

enum { MAXL = 64,  DWRD = 32 };

// Function declarations
FILE *xfopen (const char *fileName, const char *mode);
char **readfile (FILE *inputfp, size_t *numLines);
void *xcalloc (size_t n, size_t s);
void *xrealloc_dp (void *ptr, size_t *n);
void stringstointarray (unsigned int *decimals, size_t numLines, char **iflines);
void binstringconvert (unsigned *decimals, char (*binarystrings)[DWRD+1], int n);
// might not include all these, double check later


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
	
	// convert decimals to binary strings
	char (*binarystrings)[DWRD+1] = {NULL};
	int n = sizeof decimals/sizeof *decimals;
	binarystrings = calloc (n, sizeof *binarystrings);
	binstringconvert (decimals, binarystrings, n);

	// calculate number of 10's in binary number	
	int x, y = 0;
	unsigned int tenCount[n];
	for (x = 0; x < n; x++) {
		tenCount[x] = 0;
		for (y = 0; y <= DWRD - 2; y++) {	
			if ((binarystrings[x][y] == '1') && (binarystrings[x][y+1] == '0'))
				tenCount[x]++;			
		}	
	}

	// calculate binary mirror value
	unsigned long int mirrorValue[n];
	int w, z = 0;	
	for (w = 0; w < n; w++) {
		mirrorValue[w] = 0;
		for (z = 0; z <= 31; z++) {
			if (binarystrings[w][z] == '1') {
				mirrorValue[w] += 1UL << (z);
			}					
		}
	}

	// print to output file
	FILE * outfp = fopen (argv[2], "w");
	int k = 0;
	for (k = 0; k < n; k++) 
		fprintf(outfp, "%*lu\t%*d\n", 10, mirrorValue[k], 2, tenCount[k]);
	fclose (outfp);

	// free allocated memory
	free (binarystrings);	
	
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


// converts decimal array to 32-bit binary string array
void binstringconvert (unsigned *decimals, char (*binarystrings)[DWRD+1], int n)
{
	int c, i, k;
	for (i = 0; i < n; i++) {
		for (c = 31; c >= 0; c--)
		{
			k = decimals[i] >> c;
			if (k & 1)
				binarystrings[i][31-c] = '1';
			else
				binarystrings[i][31-c] = '0';
		}
		binarystrings[i][DWRD] = 0;  // nul-terminate 
	}
}





////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// OPTIONAL ERROR CHECKING FUNCTIONS
/*
void *xcalloc (size_t numElements, size_t sizeElements)
{
	register void *memorypointer = calloc (numElements, sizeElements);  // (MAXL, sizeof *filebuffer);
	if (memorypointer == 0) {
		fprintf (stderr, "xcalloc() error: virtual memory exhausted.\n");
		exit (EXIT_FAILURE);
	}

	return memorypointer;
}

void *xrealloc_dp (void *ptr, size_t *n)
{
	void **p = ptr;
	void *tmp = realloc (p, 2 * *n * sizeof tmp);
	if (!tmp) {
		fprintf (stderr, "xrealloc_dp() error: virtual memory exhausted.\n");
		exit (EXIT_FAILURE);
	}
	p = tmp;
	memset (p + *n, 0, *n * sizeof tmp); // set new pointers NULL 
	*n *= 2;

	return p;
}

FILE *xfopen (const char *fileName, const char *mode)
{
	FILE *inputfp = fopen (fileName, mode);

	if (!inputfp) {
		fprintf (stderr, "xfopen() error: file open failed '%s'.\n", fileName);
		// return NULL;      // return or exit as desired 
		exit (EXIT_FAILURE);
	}

	return inputfp;
}
*/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// OTHER CODE PIECES
/*

// print string array
for (i = 0; i < numLines; i++)    
	printf ("%s\n", iflines[i]);


// print decimal array
printf("\n");
for (i = 0; i <= numLines-1; i++) 
	printf("%u\n", decimals[i]);
printf("\n");	


// print numbers and respective binary strings
for (j = 0; j < n; j++) 
	printf (" %10u : %s\n", decimals[j], binarystrings[j]);

// print 10-counts
int z = 0;
for (z = 0; z < n; z++)
	printf("\n%d", tenCount[z]);		


// print mirror decimal values
	int k = 0;
	for (k = 0; k < n; k++)
		printf("%lu\n", mirrorValue[k]);

// printing binary mirrors and 10-counts
int p = 0;
for (j = 0; j < n; j++) {
	for (p = DWRD - 1; p >= 0; p--) {
		printf ("%c", binarystrings[j][p]);
	}
	
	
	if ((tenCount[j] / 10) < 1) // need to fix this whitespace
		printf(" ");		
	printf("    \t%d\n", tenCount[j]);
}

// print binary mirrors and 10-counts
int p = 0;
for (j = 0; j < n; j++) {
	for (p = DWRD - 1; p >= 0; p--) {
		printf ("%c", binarystrings[j][p]);
	}
	
	printf("\t%d\n", tenCount[j]);
}		


// print mirror decimal values and ten counts
for (k = 0; k < n; k++) 
	printf("%*lu\t%*d\n", 10, mirrorValue[k], 2, tenCount[k]);



// printing using %z and %X
for (i = 0; i < numLines; i++)       // print lines 
	printf (" line[%2zu] : %s\n", i, iflines[i]);
// line size
printf("\n Number of lines: %zu\n", numLines);
// test print
printf(" First line as hex: %X", atoi(iflines[0]));
	 

*/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/* NOTES


You need to allocate space for the array of pointers to strings as well as the strings themselves. 
The first call to calloc() allocates the array of pointers to strings and each malloc() allocates the strings themselves:
Also, you didn't write a null terminator to the end of the strings. When you try to write it (printf("\n%s", binarystrings[0]);) 
it will keep reading through memory, past where you want the end to be. Writing a zero ('\0') at the end requires one additional 
character in the allocation, hence the +1 in the malloc() calls.

Notice the use of the sizeof() operator. You should never hard code memory sizes. In C, let the compiler figure out how big things are, 
don't try to guess. A pointer could be 4 bytes on a 32-bit system, and 8 bytes on a 64-bit system. 
Even if you know what system you have and how big it will be, use sizeof().
		
		
-----------------------------------------------------------------------------------------------------------------------


char *s Vs. char s[]: 
	char *s = "Hello world";
	will place Hello world in the read-only parts of the memory and making s a pointer to that, making any writing 
	operation on this memory illegal. 
	While doing:
	char s[] = "Hello world";
	puts the literal string in read-only memory and copies the string to newly allocated memory on the stack. Thus making
	s[0] = 'J';
	legal. 

size_t: type is the unsigned integer type that is the result of the sizeof operator (and the offsetof operator), 
		so it is guaranteed to be big enough to contain the size of the biggest object your system can handle 
		(e.g., a static array of 8Gb).

ssize_t: used for functions whose return value could either be a valid size, or a negative value to indicate an error. 
		 It is guaranteed to be able to store values at least in the range [-1, SSIZE_MAX] (SSIZE_MAX is system-dependent).

sizeof: In the programming languages C and C++, the unary operator sizeof generates the size of a variable or datatype, 
		measured in the number of char size 	storage units required for the type. As such, the construct sizeof (char) 
		is guaranteed to be 1.

fprintf: printf(...) is equivalent to fprintf(stdout,...). 
		 fprintf is used to output to stream.

calloc: calloc(...) is basically malloc + memset(if you want to 0 initialise the memory) 

register: a hint to the compiler that the variable will be heavily used and that you recommend it 
		  be kept in a processor register if possible.

getline: getline(&buffer,&size,stdin); 
		 The getline function reads an entire line from a stream, up to and including the next newline character. 
		 It takes three parameters. The first is a pointer to a block allocated with malloc or calloc. 
		 This parameter is of type char **; it will contain the line read by getline when it returns. 
	   	 The second parameter is a pointer to a variable of type size_t; this parameter specifies the size in bytes of the 
		 block of memory pointed to by the first parameter. The third parameter is simply the stream from which to read the line.

strdup: char *strdup(const char *s1); The strdup() function shall return a pointer to a new string, 
		which is a duplicate of the string pointed to by s1. The returned pointer can be passed to free(). 
		A null pointer is returned if the new string cannot be created.

realloc: void *realloc(void *ptr, size_t size) 
		 Parameters
		 ptr -- This is the pointer to a memory block previously allocated with malloc, calloc or realloc to be reallocated. 
		 If this is NULL, a new block is allocated and a pointer to it is returned by the function.
	   	 size -- This is the new size for the memory block, in bytes. If it is 0 and ptr points to an existing block of memory, 
		 the memory block pointed by ptr is deallocated and a NULL pointer is returned.
		 Return Value
		 This function returns a pointer to the newly allocated memory, or NULL if the request fails.





*/





















