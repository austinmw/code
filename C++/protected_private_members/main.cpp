#include <iostream>
#include "Mother.h"
#include "Daughter.h"
using namespace std;


int main() {

	// private & protected members video
	//Daughter tina;
	//tina.doSomething();

	

	// derived class constructors and deconstructors video
	//Mother mom;
	Daughter dina;
	// Daughter does not inherent constructor/deconstructor from Mother class
	// however, the Mother constructor still runs
	// Program says:
	// I have 1 Daughter object I need to make
	// very first thing it does is invoke base class's constructor
	// then invokes Daughter's constructor
	// basically whenever you run a class it sets up all its base classes first
	// goes from top-most class constructor on down to make sure everything will
	// work inside lower class
}