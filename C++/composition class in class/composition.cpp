#include "Birthday.h"
#include "People.h"
#include <iostream>
using namespace std;


// a class can have objects of another class as its members
// this is composition


int main() {
	
	Birthday birthObj(12, 22, 1989);
	
	People meObj("Austin", birthObj);
	
	meObj.printInfo();
	
}