#include <stdio.h>


int main(int argc, char *argv[]) {



	typedef struct X { // first X is struct name
		int x; 
	} X; // second X is typedef name
	

	// usage
	X test;



	/* ------ alternative (separating the above) ------ */
	
	// part 1
	struct S { 
		int x; 
	};
	
	// part 2
	typedef struct S S;
	
	
	/* In the first line you are defining the identifier S within the struct name space 
	(not in the C++ sense). You can use it and define variables or function arguments of 
	the newly defined type by defining the type of the argument as struct S: */	
	void f( struct S argument ); // struct is required here

	/* The second line adds a type alias S in the global name space and thus allows 
	you to just write: */
	void f( S argument ); // struct keyword no longer needed

}