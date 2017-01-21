#include "Sally2.h"
#include <iostream>
using namespace std;

// member initializers
// : tells c++ that we're going to be working w member intializer syntax
Sally::Sally(int a, int b) 
: regVar(a), 
constVar(b)
{
}

void Sally::print(){
	cout << "regular var is: " << regVar << " const var is: " << constVar << endl;
}