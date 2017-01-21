// in C++, there is no exponentiation or power operator.
// ^ means bitwise xor
//

// enter the code to import the cmath library
// your code here l1

#include <iostream>
#include <limits>
#include <cmath>
#include <limits.h>

// write a function mypow(x,n) which calculates x^n i.e. x**n for
// and returns a long int.
//
long int mypow(int x, int n) {


	return  pow(x, n);
}


//your block above here
//...
//your block below here

using namespace std;
int main(){
	cout << "Numerical limits testing" << endl;

	// We can create 10^4 this way. Note: l1 must be correct!
	int i = pow(10,4);
	// What is the largest number we can create this way? Why?
	// your code here l2

cout << "Int max is : " << INT_MAX << endl;
// because i is type int


	//find and print out using constants/functions defined in <limits>
	// the following values
	// - the largest possible int
	// - the largest possible long int
	// - the smallest e such that 1+e != 1 for double

#include <float.h>

	cout << "largest int: " << INT_MAX << endl;
	cout << "largest long int: " << LONG_MAX << endl;
	cout << "the smallest e such that 1+e != 1 for double: ";
	cout <<  DBL_EPSILON  << endl;

	cout << "\neps test" << endl;

	// Demonstrate that 1+e/2 == 1 for double
	double test=1.0;
	double halfeps;

	//set halfeps to 0.5 of the smallest value as above.
	halfeps = DBL_EPSILON / 2;

	double new_test=test+halfeps;

	cout << "test 1= " << test << endl;
	cout << " e/2 = " << halfeps <<endl;
	cout << "new 1= " << new_test <<endl;
	cout << "new==test " << (new_test==test) << endl;

	cout << "\n2e test" << endl;
	//Try this again, but now add 2e to 1.
	double doubleeps = DBL_EPSILON * 2;
	double test2 = test + doubleeps;
	cout << "test 1= " << test << endl;
	cout << " e*2 = " << doubleeps <<endl;
	cout << "new 1= " << test2 <<endl;
	cout << "new==test " << (new_test==test2) << endl;

}
