#include <iostream>
#include "Mother.h"
#include "Daughter.h"
using namespace std;

void Daughter::doSomething(){
	publicv = 1; // no errors when running main.cpp
	protectedv = 2; // no errors when running main.cpp, so we know protected
	// works with inheritance
	// privatev = 3; // ERRORS: error: 'privatev' is a private member of 'Mother' (NOT      	                                                                       // Daughter)
}


// now daughter class has own unique constructor/deconstructor
Daughter::Daughter(){
	cout << "I am the daughter constructor!" << endl;
}

Daughter::~Daughter(){
	cout << "daughter deconstructor" << endl;
}
