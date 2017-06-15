#include <iostream>
#include "People.h"
#include "Birthday.h"
using namespace std;


// anytime you're working with a class inside of another class, you need
// to use a member initializer list

People::People(string x, Birthday bo)
: name(x), dateOfBirth(bo)
{
}


void People::printInfo()
{
	cout << name << " was born on ";
	dateOfBirth.printDate();
}