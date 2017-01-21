#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
/* 
	Preprocessor macros ("#define's") are a lexical replacement tool a la "search and replace". They are entirely agnostic of the programming language and have no understanding what you're trying to do. You can think of them as a glorified copy/paste mechanic -- occasionally that's useful, but you should use it with care. 

	Typedefs are a C language feature that lets you create aliases for types. This is extremely useful to make complicated compound types (like structs and function pointers) readable and handlable (in C++ there are even situations where you must typedef a type). 

	For (3): You should always prefer language features over preprocessor macros when that's possible! So always use typedefs for types, and constant values for constants. That way, the compiler can actually interact with you meaningfully. Remember that the compiler is your friend, so you should tell it as much as possible. Preprocessor macros do the exact opposite by hiding your semantics from the compiler.
*/
	
	
/*
#define defines macros.
typedef defines types.

Now saying that, here are a few differences:

With #define you can define constants that can be used in compile time. The constants can be used with #ifdef to check how the code is compiled, and specialize certain code according to compile parameters.
You can also use #define to declare miniature find-and-replace Macro functions.

typedef can be used to give aliases to types (which you could probably do with #define as well), but it's safer because of the find-and-replace nature of #define constants.
Besides that, you can use forward declaration with typedef which allows you to declare a type that will be used, but isn't yet linked to the file you're writing in.
*/

/*
typedef obeys scoping rules just like variables (can put outside of main for global though), 
whereas define stays valid until the end of the file (or until a matching undef).	
*/

/* Examples: */
	
typedef int a10[10];
a10 a, b, c; // create three 10-int arrays


// simple typedef
typedef unsigned long ulong;
// the following two objects have the same type
unsigned long l1;
ulong l2;


typedef int (*func_p) (int);
func_p fp; // func_p is a pointer to a function that
					// takes an int and returns an int


// more complicated typedef (\/ THE REFERENCE IS C++ NOT C)
typedef int int_t, *intp_t, (&fp)(int, ulong), arr_t[10];
 // the following two objects have the same type
int a1[10];
arr_t a2;
/* line is equivalent to:
typedef int int_t;              // simple int
typedef int *intp_t;            // pointer to int
typedef int (&fp)(int, ulong);  // reference to function returning int
typedef int arr_t[10];          // array of 10 ints
*/


#define TRUE  1
#define FALSE 0
printf( "Value of TRUE : %d\n", TRUE);
printf( "Value of FALSE : %d\n", FALSE);



typedef struct Books {
	char title[50];
	char author[50];
	char subject[100];
	int book_id;
} Book;

Book book;
 
strcpy( book.title, "C Programming");
strcpy( book.author, "Nuha Ali"); 
strcpy( book.subject, "C Programming Tutorial");
book.book_id = 6495407;
 
printf( "Book title : %s\n", book.title);
printf( "Book author : %s\n", book.author);
printf( "Book subject : %s\n", book.subject);
printf( "Book book_id : %d\n", book.book_id);

	
}