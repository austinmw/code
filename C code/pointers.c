#include <stdio.h>
// http://www.cplusplus.com/doc/tutorial/pointers/

/* An interesting property of pointers is that they can be used to access the variable they point to directly. This is done by preceding the pointer name with the dereference operator (*). The operator itself can be read as "value pointed to by". e.g. baz = *foo; */

/* Note that the asterisk (*) used when declaring a pointer only means that it is a pointer (it is part of its type compound specifier), and should not be confused with the dereference operator, but which is also written with an asterisk (*). They are simply two different things represented with the same sign. */


int main(int argc, char *argv[]) {
	
	// Example:
	int myvar;
	int* myptr = &myvar;
	
	// Is the same as:
	int myvar2;
	int* myptr2;
	myptr2 = &myvar2;	
	
	
	//NOT EQUAL TO:
	/*
	int myvar;
	int * myptr;
	*myptr = &myvar; (*)
	*/
	
	// The asterisk (*) in the pointer declaration (line 2) only indicates 
	// that it is a pointer, it is not the dereference operator (as in line 3)
	
	int x = 5;
	int * ptr = &x; // ptr points to address of x
	printf("x = %d\n", x);
	printf("int * ptr = &x\n");
	// *ptr ("value pointed to by ptr" [dereference operator])
	// *ptr = 5, ptr = addr of x, &ptr = addr of ptr
	printf("*ptr = %d\nptr = %p = &x = %p\n&ptr = %p\n\n", *ptr, ptr, &x, &ptr);
	
	
	// pointer initialized to another pointer
	int* bar = ptr; // bar points to ptr previously set equal to &x
	printf("int * bar = ptr\n");
	// value pointed to by ptr = &x, 5
	printf("*bar = value pointed to by ptr = &x = %d\n", *bar); 
	printf("&bar = address of bar = %p\n", &bar); // address of bar
	printf("value of bar = ptr = &x = %p\n\n", bar); // value of bar = ptr = &x	
	
	
	// pointers to pointers
	char a;
	char * b;
	char ** c;
	a = 'z';
	b = &a; // *b = 'z', b = &a, &b = b's addr
	c = &b; // c = &b, &c = c's addr, *c = &a
	
	printf("char a\n");
	printf("char * b\n");
	printf("char ** c\n");
	printf("a = %c\n", a);
	printf("b = &a = %p\n", &a);
	printf("c = &b = %p\n", &b);
	printf("*b = %c\n", *b);
	printf("b = %p\n", b);
	printf("&b = %p\n", &b);
	printf("*c = %p = &a = %p\n", *c, &a);
	printf("c = %p = &b = %p\n", c, &b);
	printf("&c = %p\n", &c);	
	printf("**c = %c\n", **c);
	
	
	// NULL pointer
	int * n = NULL; // liteally means pointing to nowhere
	
	
}