#include <iostream>
#include <limits>

using namespace std;
int main() 
{
	cout << "Maximum integer size in C++ is: ";
	cout << INT_MAX;
	cout << " because the compiler stores ints in 4 bytes of memory, ";
	cout << "which is 8x4 bits = 32. (2^32)-1 combinations is ";
	cout << UINT_MAX << " which is the unsigned int max, so you divide ";
	cout << "by 2 for positive and negative." << endl << endl;
	
	
	cout << "Floats are also stored in 4 bytes. Chars are stored in ";
	cout << "1 byte of memory." << endl << endl;
	cout << "Each byte of memory is referenced by its ADDRESS." << endl;
	
	
	
}