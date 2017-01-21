#include <iostream>

using namespace std;
int main(int argc, char *argv[]) {
	long x = __cplusplus;
	
	if (x == 1)
		cout << "pre-C++98";
	else if (x == 199711)
		cout << "C++98 (or C++98 TR1)";
	else if (x == 201103)
		cout << "C++11";
	else if (x == 201402)
		cout << "C++14";
	else 
		cout << "Not sure which C++ version";
}