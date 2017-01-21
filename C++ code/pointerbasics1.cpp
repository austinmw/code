// USING POINTERS by J Carruthers with inputs from
//   D Densmore and D Castanon
//
// Summary
//  - pointers are tricky but provide amazing functionality. 
//  - use with caution only when necessary.
//  
// Pointers
//   - the * and & operators
//   - declaring using type *
//   - setting pointers to addresses
//   - changing the pointed to value
//   - using ++
//   - passing to functions "by value"

#include <iostream>
using namespace std;

void addthree (char * x); // function body is after

int main () {
	
	cout << "Some normal variables to play with" << endl;
	int i1=45,i2=5;
	char s[]="abcd";

	cout << i1 << " " << i2 << " " << s << endl;

	int * pi ; // make a pointer to int
	pi = & i2; // make it point to i2
	*pi = 42;  // whatever pi points to is now 42

	cout << "\n... after playing with a pointer to i2" << endl;
	cout << i1 << " " << i2 << " " << s << endl;

	char * pc;  // pointer to char 
	pc  = &s[1];  // point to the 2nd char in the array.
	*pc = 'Q';    // change the value.
	cout << "\n... after playing with a pointer to s[1]" << endl;
	cout << i1 << " " << i2 << " " << s << endl;

	pc++; // move the pointer to the next item.
	*pc='Z';

	cout << "\n... after incrementing the pointer, and assigning" << endl;
	cout << i1 << " " << i2 << " " << s << endl;
  
	s[0]=s[1]=s[2]=s[3]='a';
	cout << "\n... after making s all a's " << endl;
	cout << i1 << " " << i2 << " " << s << endl;

	pc=&s[0];
	addthree(pc);
	cout << "\n... after calling addthree (what happened to s?)" << endl;
	cout << i1 << " " << i2 << " " << s << endl;
	
	return 0;
}

void addthree(char * x) { // if you have an address, you can do terrible things
   *x = *x +3;
   x++;
   *x = *x +2;
}


int a = 5;
int b[];
int *p = &a;
int *p2 = b;






