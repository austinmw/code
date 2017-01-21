c#include <iostream>
using namespace std;


// template definition
template <class name>  // build generic type of data
name addCrap(name a, name b) {
	return a+b;
}


int main () {

	int x = 7, y = 43, z;
	z = addCrap(x, y);
	cout << z << endl;

	double a = 5, b = 10, c;
	c = addCrap(a, b);
	cout << c << endl;
	
	// error, 2 different types
	//int j = 7;
	//double k = 8;
	//j = addCrap(j, k);
	
	
	
}