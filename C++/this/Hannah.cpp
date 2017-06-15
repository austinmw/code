#include <iostream>
#include "Hannah.h"
using namespace std;

Hannah::Hannah(int num)
:h(num) // set private var to constructor input
{
}

void Hannah::printCrap(){
	cout << "h=" << h << endl; // assumes current obj
	cout << "this->=" << this->h << endl;  // explicitly saying current object
	cout << "(*this).h=" << (*this).h << endl; // dereferencing a pointer
}

// the keyword 'this' stores address of current object that you're working with
