#include <iostream>

using namespace std;
int main(int argc, char *argv[]) {
	
	
	/* Local arrays are created on the stack, and have automatic storage duration -- you don't 
	need to manually manage memory, but they get destroyed when the function they're in ends. 
	They necessarily have a fixed size: */

		int a[10];
		
		
	/* Arrays created with operator new[] have dynamic storage duration and are stored on 
	the heap (technically the "free store"). They can have any size, but you need to allocate 
	and free them yourself since they're not part of the stack frame: */

		int* b = new int[10];
		delete[] b;
	
	
		// dynamic size
		int n;
		int* c = new int[n];
		delete[] c;
	
}



/* Summary: The difference between dynamic arrays and fixed or compile-time arrays

Compile-time arrays are determined in advance (when the program is compiled) and are 
part of a functions stack frame. They are allocated before the main function runs. 

dynamic arrays are allocated at runtime with the "new" keyword (or the malloc family from C) 
and their size is not known in advance. dynamic allocations are not automatically cleaned up 
until the program stops running.
	
*/