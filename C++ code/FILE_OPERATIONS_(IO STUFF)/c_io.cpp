#include <cstdio>
#include <iostream>
using namespace std;

/* 
<cstdio> (stdio.h)  (header)
C library to perform Input/Output operations
(C++ alternative is <fstream>, or can still use <cstdio>)

Input and Output operations can also be performed in C++ using the C Standard Input and Output Library 
(cstdio, known as stdio.h in the C language). This library uses what are called streams to operate with 
physical devices such as keyboards, printers, terminals or with any other type of files supported by the system. 
Streams are an abstraction to interact with these in an uniform way; All streams have similar properties 
independently of the individual characteristics of the physical media they are associated with.

Streams are handled in the cstdio library as pointers to FILE objects. A pointer to a FILE object uniquely 
identifies a stream, and is used as a parameter in the operations involving that stream.

There also exist three standard streams: stdin, stdout and stderr, which are automatically created and opened 
for all programs using the library. 

Stream properties 
Streams have some properties that define which functions can be used on them and how these will treat the data 
input or output through them. Most of these properties are defined at the moment the stream is associated 
with a file (opened) using the fopen function:
Read/Write Access
Specifies whether the stream has read or write access (or both) to the physical media they are associated with. 
Text / Binary
Text streams are thought to represent a set of text lines, each one ending with a new-line character. 
Depending on the environment where the application is run, some character translation may occur with text streams 
to adapt some special characters to the text file specifications of the environment. A binary stream, on the other 
hand, is a sequence of characters written or read from the physical media with no translation, having a one-to-one 
correspondence with the characters read or written to the stream.
Buffer
A buffer is a block of memory where data is accumulated before being physically read or written to the associated 
file or device. Streams can be either fully buffered, line buffered or unbuffered. On fully buffered streams, 
data is read/written when the buffer is filled, on line buffered streams this happens when a new-line character 
is encountered, and on unbuffered streams characters are intended to be read/written as soon as possible.
Orientation
On opening, streams have no orientation. As soon as an input/output operation is performed on them, they become 
either byte-oriented or wide-oriented, depending on the operation performed (generally, functions defined in <cstdio> 
are byte-oriented, while functions in <cwchar> are wide-oriented). See cwchar for more info.


Indicators 
Streams have certain internal indicators that specify their current state and which affect the behavior of some 
input and output operations performed on them:
Error indicator
This indicator is set when an error has occurred in an operation related to the stream. This indicator can be 
checked with the ferror function, and can be reset by calling either to clearerr, freopen or rewind.
End-Of-File indicator
When set, indicates that the last reading or writing operation performed with the stream reached the End of File. 
It can be checked with the feof function, and can be reset by calling either to clearerr or freopen or by calling 
to any repositioning function (rewind, fseek and fsetpos).
Position indicator
It is an internal pointer of each stream which points to the next character to be read or written in the next 
I/O operation. Its value can be obtained by the ftell and fgetpos functions, and can be changed using the repositioning 
functions rewind, fseek and fsetpos.
*/

/* ~~~~~~~~~~~~~~~ OPERATIONS ON FILES  ~~~~~~~~~~~~~~~ */
/* ~~~~~~~~~~~~~~~ OPERATIONS ON FILES  ~~~~~~~~~~~~~~~ */

// remove	
int remove_fn()
{// DELETES FILE FROM DIRECTORY (if it exists)
	if (remove("samplefile.txt") != 0) 
		perror("Error deleting file");
	else
		puts("File successfully deleted");
	return 0;
}


//	rename
int rename_fn()
{// RENAMES oldname.txt (if file exists)
	int result;
	char oldname[] = "oldname.txt";  
	char newname[] = "newname.txt";
	result = rename(oldname, newname); 
	if (result == 0)
		puts ("File successfully renamed");
	else
		perror("Error renaming file");
	return 0;
}


/* ~~~~~~~~~~~~~~~ FILE ACCESS ~~~~~~~~~~~~~~~ */
/* ~~~~~~~~~~~~~~~ FILE ACCESS ~~~~~~~~~~~~~~~ */
// SCANS: no letter: stdin, s: string, f: stream (file)


// fopen, fclose
int fopen_fclose_fn()
{
	FILE * pFile;
	pFile = fopen ("myfile.txt","w+"); // w+ creates if doesn't already exist
	fprintf (pFile, "fclose example\n");
	fclose (pFile);
	return 0;
	/* fopen flags: 
	r = read mode only    
	r+ = read/write mode
	w = write mode only
	w+ = read/write mode, if the file already exists override it (empty it)
	t = convert \n to \r\n
	a = append
	*/
}


//  fflush 
char mybuffer[80];
int fflush_fn()
{
	FILE * pFile;
	pFile = fopen ("example.txt","w+");
	if (pFile == NULL) perror ("Error opening file");
	else {
	  fputs ("test\n",pFile);
	  fflush (pFile);    // flushing or repositioning required
	  fgets (mybuffer,80,pFile);
	  puts (mybuffer);
	  fclose (pFile);
    }
	// another example so this is printed without needing '\n'
	//printf("Enter input stuff (flush test): ");
	//fflush(stdout);
	return 0;
}


// freopen
int freopen_fn()
{// FILE * freopen ( const char * filename, const char * mode, FILE * stream );
	freopen ("myfile.txt","w",stdout);
	printf ("1This sentence is redirected to a file.\n");
	fclose (stdout);
	return 0;
}


// setbuf
int setbuf_fn() // set stream buffer
{/*Buffered input streams read data from a memory area known as a buffer; the native input API is called only when the buffer is empty. Similarly, buffered output streams write data to a buffer, and the native output API is called only when the buffer is full.*/
	char buffer[BUFSIZ];
	FILE *pFile1, *pFile2;

	pFile1=fopen ("myfile1.txt","w");
	pFile2=fopen ("myfile2.txt","a");

	setbuf ( pFile1 , buffer );
	fputs ("This is sent to a buffered stream",pFile1);
	fflush (pFile1); // without waiting for it to fill

	setbuf ( pFile2 , NULL );
	fputs ("This is sent to an unbuffered stream",pFile2);

	fclose (pFile1);
	fclose (pFile2);

	return 0;
}


// setvbuf
int setvbuf_fn() // change stream buffering
{// int setvbuf ( FILE * stream, char * buffer, int mode, size_t size );
	FILE *pFile;
	pFile=fopen ("myfile.txt","w");
	setvbuf ( pFile , NULL , _IOFBF , 1024 );
	// File operations here
	fclose (pFile);
	return 0;
}


/* ~~~~~~~~~~~~~~~ FORMATTED INPUT/OUTPUT ~~~~~~~~~~~~~~~ */
/* ~~~~~~~~~~~~~~~ FORMATTED INPUT/OUTPUT ~~~~~~~~~~~~~~~ */



//fprintf
int fprintf_fn() // Write formatted data to stream (file)
{ /* int fprintf ( FILE * stream, const char * format, ... );
%-10.10s : left-justified (-), minimum of ten characters (10), maximum of ten characters (.10), string (s).
Assuming that we have entered John, Jean-Francois and Yoko as the 3 names, myfile.txt would contain:
Name 1 [John      ] 
Name 2 [Jean-Franc] 
Name 3 [Yoko      ] */
FILE * pFile;
	int n;
	char name [100];

	pFile = fopen ("myfile.txt","w");
	for (n=0 ; n<3 ; n++)
	{
	  puts ("please, enter a name: ");
	  gets (name);
	  fprintf (pFile, "Name %d [%-10.10s]\n",n+1,name);
	}
	fclose (pFile);

	return 0;
}


//fscanf (1)
int fscanf_stdin_fn() 
{// Read formatted data from stream (file)
	int age, weight;
	printf("Enter age and weight: ");
	fscanf(stdin, "%d %d", &age, &weight);

	printf("\nYou entered: %d %d\n", age, weight);
	return 0;
}


// fscanf (2)
int fscanf_file_fn ()
{
	char str [80];
	float f;
	FILE * pFile;

	pFile = fopen ("myfile.txt","w+");
	fprintf (pFile, "%f %s", 3.1416, "PI");
	rewind (pFile);
	fscanf (pFile, "%f", &f);
	fscanf (pFile, "%s", str);
	fclose (pFile);
	printf ("I have read: %f and %s \n",f,str);
	return 0;
}

/* There are a few behavior differences in the two approaches. If you use fgets() + sscanf(), 
you must enter both values on the same line, whereas fscanf() on stdin (or equivalently, scanf()) 
will read them off different lines if it doesn't find the second value on the first line you entered.

But, probably the most important differences have to do with handling error cases and the mixing of 
line oriented input and field oriented input.

If you read a line that you're unable to parse with sscanf() after having read it using fgets() your 
program can simply discard the line and move on. However, fscanf(), when it fails to convert fields, 
leaves all the input on the stream. So, if you failed to read the input you wanted, you'd have to go 
and read all the data you want to ignore yourself.

The other subtle gotcha comes in if you want to mix field oriented (ala scanf()) with line oriented 
(e.g. fgets()) calls in your code. When scanf() converts an int for example, it will leave behind a \n 
on the input stream (assuming there was one, like from pressing the enter key), which will cause a 
subsequent call to fgets() to return immediately with only that character in the input. This is a really 
common issue for new programmers.

So, while you are right that you can just use fscanf() like that, you may be able to avoid some headaches 
by using fgets() + sscanf(). */

// fgets & sscanf
int fgets_sscanf_fn() // alternative approach: fgets() & sscanf()
{// sscanf: Read formatted data from string
		int age, weight;
		printf("Enter age and weight: ");
		char line[20];
		fgets(line, sizeof(line), stdin);		
		sscanf(line, "%d %d", &age, &weight);
		printf("\nYou entered: %d %d\n", age, weight);
		return 0;
}


// printf
int printf_fn()
/* For printf, the * allows you to specify minimum field width through an extra parameter, 
i.e. printf("%*d", 4, 100); specifies a field width of 4 */
{
	printf ("Characters: %c %c \n", 'a', 65);
	printf ("Decimals: %d %ld\n", 1977, 650000L);
	printf ("Preceding with blanks: %10d \n", 1977);
	printf ("Preceding with zeros: %010d \n", 1977);
	printf ("Some different radices: %d %x %o %#x %#o \n", 100, 100, 100, 100, 100);
	printf ("floats: %4.2f %+.0e %E \n", 3.1416, 3.1416, 3.1416);
	printf ("Width trick: %*d \n", 5, 10);
	printf ("%s \n", "A string");
	return 0;
}


// scanf
int scanf_fn() // Read formatted data from stdin
{// int scanf ( const char * format, ... );
	char str [80];
	int i;
	printf ("Enter your family name: ");
	scanf ("%79s",str);  
	printf ("Enter your age: ");
	scanf ("%d",&i);
	printf ("Mr. %s , %d years old.\n",str,i);
	printf ("Enter a hexadecimal number: ");
	scanf ("%x",&i);
	printf ("You have entered %#x (%d).\n",i,i);
	return 0;	
} 


/* SPRINTF takes no argument specifying the maximum number of bytes to write; it simply takes a destination buffer, a format string, and a bunch of arguments. Therefore, it may write more bytes than your buffer has space for, and in so doing write arbitrary code. . . . With SNPRINTF, a fixed, clear maximum is set regardless of changes in the format string or input types. http://stackoverflow.com/questions/7315936/which-of-sprintf-snprintf-is-more-secure */


// snprintf
int snprintf_fn() // Write formatted output to sized buffer
{// int snprintf ( char * s, size_t n, const char * format, ... );
	char buffer [100];
	int cx;
	cx = snprintf ( buffer, 100, "The half of %d is %d", 60, 60/2 );
	if (cx>=0 && cx<100)      // check returned value
		snprintf ( buffer+cx, 100-cx, ", and the half of that is %d.", 60/2/2 );
	puts (buffer);
	return 0;	
}


// sprintf
int sprintf_fn() // Write formatted data to string
{// int sprintf ( char * str, const char * format, ... );
	char buffer [50];
	int n, a=5, b=3;
	n=sprintf (buffer, "%d plus %d is %d", a, b, a+b);
	printf ("[%s] is a string %d chars long\n",buffer,n);
	return 0;	
}


// sscanf
/* For scanf, the * indicates that the field is to be read but ignored, so that i.e. 
scanf("%*d %d", &i) for the input "12 34" will ignore 12 and read 34 into the integer i. */
int sscanf_fn() // Read formatted data from string
{// int sscanf ( const char * s, const char * format, ...);
	char sentence []="Rudolph is 12 years old";
	char str [20];
	int i;
	// wants addresses to put, str is addr of str[0]
	sscanf (sentence,"%s %*s %d",str,&i);
	printf ("%s -> %d\n",str,i);
	return 0;
}


// vprintf
/* vprintf() (and friends) allow to use va_list as argument, 
which is useful when your function has a variable amount of arguments */
void vfprintf_fn2(FILE * stream, const char * format, ...)
{ // support fn for vfprintf_fn1
	va_list args;
	va_start (args, format);
	vfprintf (stream, format, args);
	va_end (args);
}
int vfprintf_fn1() // Write formatted data from variable argument list to stream (file)
{// int vfprintf ( FILE * stream, const char * format, va_list arg );
	FILE * pFile;
	pFile = fopen ("myfile.txt","w");
	vfprintf_fn2 (pFile,"Call with %d variable argument.\n",1);
	vfprintf_fn2 (pFile,"Call with %d variable %s.\n",2,"arguments");
	fclose (pFile);
	return 0;
}


// vfscanf
/* vfscanf() function works just like the fscanf()function, except that arg_ptr points 
to a list of arguments whose number can vary from call to call in the program. These arguments 
should be initialized by va_start for each call. */
void vfscanf_fn2 (FILE * stream, const char * format, ...)
{ // support fn for vfscanf_fn1
	va_list args;
	va_start (args, format);
	vfscanf (stream, format, args);
	va_end (args);
}
int vfscanf_fn1() // Read formatted data from stream into variable argument list
{// int vfscanf ( FILE * stream, const char * format, va_list arg );
	FILE * pFile;
	int val;
	char str[100];
	pFile = fopen ("myfile.txt","r");
	if (pFile!=NULL) {
		vfscanf_fn2 ( pFile, " %s %d ", str, &val );
		printf ("I have read %s and %d", str, val);
		fclose (pFile);
	}
	return 0;	
}


// vprintf
void vprintf_fn2 ( const char * format, ... )
{ // support fn for vprintf_fn1
	va_list args;
	va_start (args, format);
	vprintf (format, args);
	va_end (args);
}
int vprintf_fn1() // Print formatted data from variable argument list to stdout
{// int vprintf ( const char * format, va_list arg );
	vprintf_fn2 ("Call with %d variable argument.\n",1);
	vprintf_fn2 ("Call with %d variable %s.\n",2,"arguments");
	return 0;
}


// vscanf
void vscanf_fn2 ( const char * format, ... )
{// support fn for vscanf_fn1
	va_list args;
	va_start (args, format);
	vscanf (format, args);
	va_end (args);
}
int vscanf_fn() // Read formatted data into variable argument list
{// int vscanf ( const char * format, va_list arg );
	int val;
	char str[100];
	printf ("Please enter a number and a word: ");
	fflush (stdout);
	vscanf_fn2 (" %d %99s ", &val, str);
	printf ("Number read: %d\nWord read: %s\n", val, str);
	return 0;
}


// vsnprintf
void vsnprintf_fn2 ( const char * format, ... ) // (prints error)
{// support fn for vsnprintf_fn1
	char buffer[256];
	va_list args;
	va_start (args, format);
	vsnprintf (buffer,256,format, args);
	perror (buffer);
	va_end (args);
}
int vsnprintf_fn1() // Write formatted data from variable argument list to sized buffer 
{// int vsnprintf (char * s, size_t n, const char * format, va_list arg );
	FILE * pFile;
	char szFileName[]="myfile.txt";

	pFile = fopen (szFileName,"r");
	if (pFile == NULL)
	  vsnprintf_fn2 ("Error opening '%s'",szFileName);
	else
	{
	  // file successfully open
	  fclose (pFile);
	}
	return 0;	
}


// vsprintf
void vsprintf_fn2 ( const char * format, ... ) // (prints error)
{
	char buffer[256];
	va_list args;
	va_start (args, format);
	vsprintf (buffer,format, args);
	perror (buffer);
	va_end (args);
}
int vsprintf_fn1() // Write formatted data from variable argument list to string
{// int vsprintf (char * s, const char * format, va_list arg );
	FILE * pFile;
	char szFileName[]="myfile.txt";
	pFile = fopen (szFileName,"r");
	if (pFile == NULL)
		vsprintf_fn2 ("Error opening '%s'",szFileName);
	else
	{
		// file successfully open
		fclose (pFile);
	}
	return 0;	
}

// vsscanf
void vsscanf_fn2( const char * str, const char * format, ... ) // (get matches)
{// support fn for vsscanf_fn1
	va_list args;
	va_start (args, format);
	vsscanf (str, format, args);
	va_end (args);
}
int vsscanf_fn1() // Read formatted data from string into variable argument list
{// int vsscanf ( const char * s, const char * format, va_list arg );
	int val;
	char buf[100];
	vsscanf_fn2 ( "99 bottles of beer on the wall", " %d %s ", &val, buf);
	printf ("Product: %s\nQuantity: %d\n", buf, val);
	return 0;	
}


/* ~~~~~~~~~~~~~~~ CHARACTER INPUT/OUTPUT ~~~~~~~~~~~~~~~ */
/* ~~~~~~~~~~~~~~~ CHARACTER INPUT/OUTPUT ~~~~~~~~~~~~~~~ */


// fgetc
int fgetc_fn() // Get character from stream (file)
{// int fgetc ( FILE * stream );
	FILE * pFile;
	int c;
	int n = 0;
	pFile=fopen ("myfile.txt","r");
	if (pFile==NULL) perror ("Error opening file");
	else
	{
		do {
			c = fgetc (pFile);
			if (c == '$') n++;
		} while (c != EOF);
		fclose (pFile);
		printf ("The file contains %d dollar sign characters ($).\n",n);
	}
	return 0;	
	/* 
This program reads an existing file called myfile.txt character by character and 
uses the n variable to count how many dollar characters ($) the file contains */
}


// fgets   (use earlier with sscanf)
int fgets_fn() // Get string from stream
{// char * fgets ( char * str, int num, FILE * stream );
FILE * pFile;
	char mystring [100];
	pFile = fopen ("myfile.txt" , "r");
	if (pFile == NULL) perror ("Error opening file");
	else {
	  if ( fgets (mystring , 100 , pFile) != NULL )
		 puts (mystring);
	  fclose (pFile);
	}
	return 0;	
}


// fputc
int fputc() // Write character to stream
{// int fputc ( int character, FILE * stream );
	FILE * pFile;
	char c;
	pFile = fopen ("alphabet.txt","w");
	if (pFile!=NULL) {
		for (c = 'A' ; c <= 'Z' ; c++)
			fputc ( c , pFile );
		fclose (pFile);
	}
	return 0;
}


// fputs
int fputs() // Write string to stream
{// int fputs ( const char * str, FILE * stream );
	FILE * pFile;
	char sentence [256];
	printf ("Enter sentence to append: ");
	fgets (sentence,256,stdin);
	pFile = fopen ("mylog.txt","a");
	fputs (sentence,pFile);
	fclose (pFile);
	return 0;
}

/* fgetc() and getc() are usually equivalent, but with some special case differences. 
The difference between getc and fgetc is that getc can be implemented as a macro, 
whereas fgetc cannot be implemented as a macro. This means three things:

-The argument to getc should not be an expression with side effects.
-Since fgetc is guaranteed to be a function, we can take its address. This allows us to pass 
the address of fgetc as an argument to another function.
-Calls to fgetc probably take longer than calls to getc, as it usually takes more time to call a function.
*/


// getc
int getc_fn() // Get character from stream
{// int getc ( FILE * stream );
	FILE * pFile;
	int c;
	int n = 0;
	pFile=fopen ("myfile.txt","r");
	if (pFile==NULL) perror ("Error opening file");
	else {
		do {
			c = getc (pFile);
			if (c == '$') n++;
		} while (c != EOF);
		fclose (pFile);
		printf ("File contains %d$.\n",n);
	}
	return 0; // counts $'s in file
}


// getchar
int getchar_fn() // Get character from stdin
{// int getchar ( void );
	int c;
	puts ("Enter text. Include a dot ('.') in a sentence to exit:");
	do {
		c=getchar();
		putchar (c);
	} while (c != '.');
	return 0;
}


// gets
int gets_fn() // Get string from stdin
{// char * gets ( char * str );
	char string [256];
	printf ("Insert your full address: ");
	gets (string);     // warning: unsafe (see fgets instead)
	printf ("Your address is: %s\n",string);
	return 0;
}

// putc and fputc are equivalent, except that putc may be implemented as a macro in some libraries. 


// putc
int putc_fn() // Write character to stream
{// int putc ( int character, FILE * stream );
	FILE * pFile;
	char c;

	pFile=fopen("alphabet.txt","wt");
	for (c = 'A' ; c <= 'Z' ; c++) {
		putc (c , pFile);
		}
	fclose (pFile);
	return 0;
}


// putchar
int putchar_fn() // Write character to stdout
{// int putchar ( int character );
	char c;
	for (c = 'A' ; c <= 'Z' ; c++) 
		putchar (c);
	return 0;
}


// puts      
int puts_fn() // Write string to stdout
{// int puts ( const char * str );
	char string [] = "Hello world!";
	puts(string);
	return 0;
} // simpler than printf(), automatically appends a '\n'
/* Besides formatting, puts() returns a nonnegative integer if successful or EOF if unsuccessful; 
   while printf() returns the number of characters printed (not including the trailing null). */


int ungetc_fn() // Unget character from stream
{// int ungetc ( int character, FILE * stream );
	FILE * pFile;
	int c;
	char buffer [256];
	pFile = fopen ("myfile.txt","rt");
	if (pFile==NULL) perror ("Error opening file");
	else while (!feof (pFile)) {
		c=getc (pFile);
		if (c == EOF) break;
		if (c == '#') ungetc ('@',pFile);
		else ungetc (c,pFile);
		if (fgets (buffer,255,pFile) != NULL)
			fputs (buffer,stdout);
		else break;
	}
	return 0;
} 
/* The getc and ungetc are used to "peek ahead" and put it back if there is some special case in handling characters
This example opens an existing file called myfile.txt for reading and prints its lines, 
but first gets the first character of every line and puts it back into the stream replacing any starting # by an @. */



/* ~~~~~~~~~~~~~~~ DIRECT INPUT/OUTPUT ~~~~~~~~~~~~~~~ */
/* ~~~~~~~~~~~~~~~ DIRECT INPUT/OUTPUT ~~~~~~~~~~~~~~~ */

// fread
int fread_fn() // Read block of data from stream
{// size_t fread ( void * ptr, size_t size, size_t count, FILE * stream );
	FILE * pFile;
	long lSize;
	char * buffer;
	size_t result;

	pFile = fopen ( "myfile.bin" , "rb" );
	if (pFile==NULL) {fputs ("File error",stderr); exit (1);}

	// obtain file size:
	fseek (pFile , 0 , SEEK_END);
	lSize = ftell (pFile);
	rewind (pFile);

	// allocate memory to contain the whole file:
	buffer = (char*) malloc (sizeof(char)*lSize);
	if (buffer == NULL) {fputs ("Memory error",stderr); exit (2);}

	// copy the file into the buffer:
	result = fread (buffer,1,lSize,pFile);
	if (result != lSize) {fputs ("Reading error",stderr); exit (3);}

	/* the whole file is now loaded in the memory buffer. */
	// terminate
	fclose (pFile);
	free (buffer);
	return 0;
}
/* Reads an array of [count] elements, each one with a size of [size] bytes, from the [stream]and stores them 
in the block of memory specified by [ptr].
The position indicator of the stream is advanced by the total amount of bytes read.
The total amount of bytes read if successful is (size*count). 
The total number of elements successfully read is returned.
If this number differs from the count parameter, either a reading error occurred or the end-of-file was reached while reading. 
In both cases, the proper indicator is set, which can be checked with ferror and feof, respectively. */

// fwrite
int fwrite_fn() // Write block of data to stream
{// size_t fwrite ( const void * ptr, size_t size, size_t count, FILE * stream );
	FILE * pFile;
	char buffer[] = { 'x' , 'y' , 'z' };
	pFile = fopen ("myfile.bin", "wb");
	fwrite (buffer , sizeof(char), sizeof(buffer), pFile);
	fclose (pFile);
	return 0;
}
/* There are certain transformations that can take place when outputting in ASCII 
(e.g. outputting neline+carriage-return when the outputted character is new-line) -- 
depending on your platform. Such transformations will not take place when using binary format ('b') */




/* ~~~~~~~~~~~~~~~ FILE POSITIONING ~~~~~~~~~~~~~~~ */
/* ~~~~~~~~~~~~~~~ FILE POSITIONING ~~~~~~~~~~~~~~~ */


/*     ftell/fseek vs. fsetpos/fgetpos:
	
ftell/fseek are more convenient, because they use a long int offset, but 
their usage is limited to files smaller than 2 GB, if long int's are 32 
bits. When dealing with files which might be larger than 2 GB (assuming 
the underlying OS supports them), the only way to handle them portably 
is to use the newer fgetpos/fsetpos. which use an object of system-defined 
type fpos_t to store the file position and can handle arbitrarily
large files.  */


// fgetpos
int fgetpos_fn() // Get current position in stream
{// int fgetpos ( FILE * stream, fpos_t * pos );
	FILE * pFile;
	int c;
	int n;
	fpos_t pos;
	pFile = fopen ("myfile.txt","r");
	if (pFile==NULL) perror ("Error opening file");
	else {
	  c = fgetc (pFile);
	  printf ("1st character is %c\n",c);
	  fgetpos (pFile,&pos);
	  for (n=0;n<3;n++)
	  {
		  fsetpos (pFile,&pos);
		  c = fgetc (pFile);
		  printf ("2nd character is %c\n",c);
	  }
	  fclose (pFile);
	}
	return 0;
}


// fseek
int fseek_fn() // Reposition stream position indicator
{// int fseek ( FILE * stream, long int offset, int origin );
	FILE * pFile;
	pFile = fopen ( "example.txt" , "wb" );
	fputs ( "This is an apple." , pFile );
	fseek ( pFile , 9 , SEEK_SET );
	fputs ( " sam" , pFile );
	fclose ( pFile );
	return 0;
} /* After this code is successfully executed, the file example.txt contains: This is a sample
Sets the position indicator associated with the stream to a new position.
For streams open in binary mode, the new position is defined by adding offset to a reference position 
specified by origin.
For streams open in text mode, offset shall either be zero or a value returned by a previous call to ftell,
and origin shall necessarily be SEEK_SET.
If the function is called with other values for these arguments, support depends on the particular system 
and library implementation (non-portable).
The end-of-file internal indicator of the stream is cleared after a successful call to this function, 
and all effects from previous calls to ungetc on this stream are dropped. 
On streams open for update (read+write), a call to fseek allows to switch between reading and writing. 
PARAMETERS:
stream
Pointer to a FILE object that identifies the stream.
offset 
Binary files: Number of bytes to offset from origin.
Text files: Either zero, or a value returned by ftell. 
origin
Position used as reference for the offset. It is specified by one of the following constants 
defined in <cstdio> exclusively to be used as arguments for this function:
Constant	Reference position
SEEK_SET	Beginning of file 
SEEK_CUR	Current position of the file pointer
SEEK_END	End of file * 
* Library implementations are allowed to not meaningfully support SEEK_END (therefore, code using it has no real standard portability). */


// fsetpos
int fsetpos_fn() // Set position indicator of stream
{// int fsetpos ( FILE * stream, const fpos_t * pos );
	FILE * pFile;
	fpos_t position;
	pFile = fopen ("myfile.txt","w");
	fgetpos (pFile, &position);
	fputs ("That is a sample",pFile);
	fsetpos (pFile, &position);
	fputs ("This",pFile);
	fclose (pFile);
	return 0;
} // after execution: This is a sample


// ftell
int ftell_fn() // Get current position in stream
{// long int ftell ( FILE * stream );
	FILE * pFile;
	long size;
	pFile = fopen ("myfile.txt","rb");
	if (pFile==NULL) perror ("Error opening file");
	else
	{
		fseek (pFile, 0, SEEK_END);   // non-portable
		size=ftell (pFile);
		fclose (pFile);
		printf ("Size of myfile.txt: %ld bytes.\n",size);
	}
	return 0;
} // This program prints out the size of myfile.txt in bytes (where supported).


// rewind
int rewind_fn() // Set position of stream to the beginning
{// void rewind ( FILE * stream );
	int n;
	FILE * pFile;
	char buffer [27];
	pFile = fopen ("myfile.txt","w+");
	for ( n='A' ; n<='Z' ; n++)
		fputc ( n, pFile);
	rewind (pFile);
	fread (buffer,1,26,pFile);
	fclose (pFile);
	buffer[26]='\0';
	puts (buffer);
	return 0;
} /* A file called myfile.txt is created for reading and writing and filled with the alphabet. 
     The file is then rewinded, read and its content is stored in a buffer, that then is written 
     to the standard output. */



/* ~~~~~~~~~~~~~~~ ERROR-HANDLING ~~~~~~~~~~~~~~~ */
/* ~~~~~~~~~~~~~~~ ERROR-HANDLING ~~~~~~~~~~~~~~~ */



// clearerr
int clearerr_fn() // Clear error indicators
{// void clearerr ( FILE * stream );
	FILE * pFile;
	pFile = fopen("myfile.txt","r");
	if (pFile==NULL) perror ("Error opening file");
	else {
		fputc ('x',pFile);
		if (ferror (pFile)) {
			printf ("Error Writing to myfile.txt\n");
			clearerr (pFile);
		}
		fgetc (pFile);
		if (!ferror (pFile))
			printf ("No errors reading myfile.txt\n"); 
		fclose (pFile);
	}
	return 0;
} /* This program opens an existing file called myfile.txt for reading and causes an I/O error 
trying to write on it. That error is cleared using clearerr, so a second error checking returns false.
Output:
Error Writing to myfile.txt
No errors reading myfile.txt  */


// feof  (PUT ADDITIONAL SHIT IN HERE!!!!!)
int feof_fn() // Check end-of-file indicator
{// int feof ( FILE * stream );
	FILE * pFile;
	int n = 0;
	pFile = fopen ("myfile.txt","rb");
	if (pFile==NULL) perror ("Error opening file");
	else
	{
		while (fgetc(pFile) != EOF) {
			++n;
		}
		if (feof(pFile)) {
			puts ("End-of-File reached.");
			printf ("Total number of bytes read: %d\n", n);
		}
		else puts ("End-of-File was not reached.");
		fclose (pFile);
	}
	return 0;
}
/* 

Every FILE stream has an internal flag that indicates whether the caller has tried to read past 
the end of the file already. feof returns that flag. The flag does not indicate whether the current 
file position is as the end of the file, only whether a previous read has tried to read past the end of the file.
This means that if you do while(!feof(pFile)) getc(), getc() will actually read the special value for EOF, which
is the same for end-offile and error. 


You can get a better understanding of how feof works, by knowing how it's implemented. 
Here is a simplified version of how the 7th Edition Unix stdio library implements feof. 
Modern libraries are very similar, adding code offering thread-safety, increased efficiency,
and a cleaner implementation.

extern  struct  _iobuf { 
	char    *_ptr;
	int     _cnt; 
	char    *_base; 
	char    _flag;
	char    _file; 
} _iob[_NFILE];

#define _IOEOF  020 
  
#define feof(p)         (((p)->_flag&_IOEOF)!=0)

#define getc(p)         (--(p)->_cnt>=0? *(p)->_ptr++&0377:_filbuf(p)) 

int 
_filbuf(FILE *iop) 
{

	iop->_ptr = iop->_base; 
	iop->_cnt = read(fileno(iop), iop->_ptr, BUFSIZ);
	if (iop->_cnt == 0) { 
			iop->_flag |= _IOEOF; 
			return(EOF);
	}
	return(*iop->_ptr++ & 0377); 
}

The stdio library maintains with each file a structure containing an internal buffer pointed by _base. 
The current character in the buffer is pointed by _ptr and the number of characters available is 
contained in _cnt. The getc macro, which is the base for a lot of higher-level functionality, like scanf, 
tries to return a character from the buffer. If the buffer is empty, it will call _filbuf to fill it.
_filbuf in turn will call read. If read returns 0, which means that no more data is available, _filbuf 
will set the _IOEOF flag, which feof checks each time you call it to return true.

As you can understand from the above, feof will return true the first time you try to read a character 
past the end of the file (or a library function tries in your behalf). This has subtle implications on 
the behavior of various functions. Consider a file containing a single character: the digit 1. After 
you read that character with getc, feof will return false, because the _IOEOF flag is unset; nobody has 
yet tried to read past the end of the file. Calling getc again will result in a call to read, the setting 
of the _IOEOF flag, and this will cause feof to return true. However, after reading the number from the same 
file using fscanf("%d", &n), feof will immediately return true, because fscanf will have tried to read 
additional digits of the integer.

How does feof() actually know when the end of file is reached?
Whatever else the C++ library does, eventually it has to read from the file. 
Somewhere in the operating system, there is a piece of code that eventually handles that read. 
It obtains from the filesystem the length of the file, stored the same way the filesystem stores 
everything else. Knowing the length of the file, the position of the read, and the number of bytes to 
be read, it can make the determination that the low-level read hits the end of the file.

When that determination is made, it is passed up the stack. Eventually, it gets to the standard library 
which records internally that the end of file has been reached. When a read request into the library 
tries to go past that recorded end, the EOF flag is set and feof will start returning true.

How EOF is detected is OS/FS-specific and has nothing to do whatsoever with the C library/language. 
The OS has some interface to read data from files. The C library is just a bridge between the OS and 
the program, so you don't have to change your program if you move to another OS. The OS knows how the
files are stored in its filesystem, so it knows how to detect EOF. My guess is that typically it is 
performed by comparing the current position to the length of the file, but it may be not that easy 
and may involve a lot of low-level details (for example, what if the file is on a network drive?). */

// ferror
int ferror_fn() // Check error indicator
{// int ferror ( FILE * stream );
	FILE * pFile;
	pFile=fopen("myfile.txt","r");
	if (pFile==NULL) perror ("Error opening file");
	else {
		fputc ('x',pFile);
		if (ferror (pFile))
			printf ("Error Writing to myfile.txt\n");
		fclose (pFile);
	}
	return 0;
} /* This program opens an existing file called myfile.txt in read-only mode but tries to write 
     a character to it, generating an error that is detected by ferror. 
Checks if the error indicator associated with stream is set, returning a value different 
from zero if it is.
This indicator is generally set by a previous operation on the stream that failed, and is cleared 
by a call to clearerr, rewind or freopen. */


// perror
int perror_fn() // Print error message
{// void perror ( const char * str );
	FILE * pFile;
	pFile=fopen ("unexist.ent","rb");
	if (pFile==NULL)
		perror ("The following error occurred");
	else
		fclose (pFile);
	return 0;
} /* If the file unexist.ent does not exist, something similar to this may be expected as program output:
	 The following error occurred: No such file or directory
Interprets the value of errno as an error message, and prints it to stderr (the standard error output stream,
usually the console), optionally preceding it with the custom message specified in str.

errno is an integral variable whose value describes the error condition or diagnostic information produced 
by a call to a library function (any function of the C standard library may set a value for errno, even if 
not explicitly specified in this reference, and even if no error happened), see errno for more info.

The error message produced by perror is platform-depend. */




/* ~~~~~~~~~~~~~~~~~~~~ MACROS ~~~~~~~~~~~~~~~~~~~~ */
/* ~~~~~~~~~~~~~~~~~~~~ MACROS ~~~~~~~~~~~~~~~~~~~~ */
/* All of these are constants, except for NULL, which is a macro that expands to a null pointer constant

BUFSIZE (Buffer size): This macro constant expands to an integral expression with the size of the buffer 
used by the setbuf function.

EOF (End-of-File): It is a macro definition of type int that expands into a negative integral constant 
expression (generally, -1).
It is used as the value returned by several functions in header <cstdio> to indicate that the End-of-File 
has been reached or to signal some other failure conditions.
It is also used as the value to represent an invalid character. 
In C++, this macro corresponds to the value of char_traits<char>::eof(). 

FILENAME_MAX (Maximum length of file names): This macro constant expands to an integral expression 
corresponding to the size needed for an array of char elements to hold the longest file name string 
allowed by the library. Or, if the library imposes no such restriction, it is set to the recommended 
size for character arrays intended to hold a file name.
	
FOPEN_MAX (Potential limit of simultaneous open streams): This macro constant expands to an integral 
expression that represents the maximum number of files that can be opened simultaneously.
Particular library implementations may count files opened by tmpfile towards this limit. Implementations 
may also allow more files to be opened beyond this limit.
FOPEN_MAX shall be greater than 7 on all systems.
	
L_tmpnam (Minimum length for temporary file name): This macro constant expands to an integral expression 
corresponding to the size needed for an array of char elements to hold the longest file name string 
possibly generated by tmpnam.
	
NULL (Null pointer): A null pointer constant can be converted to any pointer type (or pointer-to-member type), 
which acquires a null pointer value. This is a special value that indicates that the pointer is not pointing 
to any object.
	
TMP_MAX (Number of temporary files): This macro expands to the minimum number of unique temporary file names 
that are guaranteed to be possible to generate using tmpnam.
This value cannot be lower than 25. 
Particular library implementations may count file names used by files created with tmpfile towards this limit. 
*/



/* ~~~~~~~~~~~~~~~~~~~~ TYPES ~~~~~~~~~~~~~~~~~~~~ */
/* ~~~~~~~~~~~~~~~~~~~~ TYPES ~~~~~~~~~~~~~~~~~~~~ */ /*

FILE     
(Object containing information to control a stream)
Object type that identifies a stream and contains the information needed to control it, including a 
pointer to its buffer, its position indicator and all its state indicators.

FILE objects are usually created by a call to either fopen or tmpfile, which both return a pointer to 
one of these objects.

The content of a FILE object is not meant to be accessed from outside the functions of the <cstdio> and 
<cwchar> headers; In fact, portable programs shall only use them in the form of pointers to identify 
streams, since for some implementations, even the value of the pointer itself could be significant to 
identify the stream (i.e., the pointer to a copy of a FILE object could be interpreted differently than 
a pointer to the original).

Its memory allocation is automatically managed: it is allocated by either fopen or tmpfile, and it is 
the responsibility of the library to free the resources once either the stream has been closed using 
fclose or the program terminates normally.

On inclusion of the <cstdio> header file, three objects of this type are automatically created, and 
pointers to them are declared: stdin, stdout and stderr, associated with the standard input stream, 
standard output stream and standard error stream, respectively.



fpos_t     
(Object containing information to specify a position within a file)
This type of object is used to specify a position within a file. An object of this type is capable of 
specifying uniquely any position within a file.

The information in fpos_t objects is usually filled by a call to fgetpos, which takes a pointer to an 
object of this type as argument.

The content of an fpos_t object is not meant to be read directly, but only to be used as an argument 
in a call to fsetpos.



size_t     
(Unsigned integral type)
Alias of one of the fundamental unsigned integer types. 

It is a type able to represent the size of any object in bytes: size_t is the type returned by the 
sizeof operator and is widely used in the standard library to represent sizes and counts.

In <cstdio>, it is used as the type of some parameters in the functions fread, fwrite and setvbuf, 
and in the case of fread and fwrite also as its returning type.

The size_t type is the unsigned integer type that is the result of the sizeof operator 
(and the offsetof operator), so it is guaranteed to be big enough to contain the size of the 
biggest object your system can handle (e.g., a static array of 8Gb).

The size_t type may be bigger than, equal to, or smaller than an unsigned int, and your 
compiler might make assumptions about it for optimization.
*/



/* ######################### MAIN ######################### */
/* ######################### MAIN ######################### */

int main(int argc, char *argv[]) {	
	
	return 0;	
}

