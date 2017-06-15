#include <iostream>
#include <stdio.h>

using namespace std;




int factorial(int n) 
// recursive factorial
{	
	if (n == 1) 
		return 1;
	else 
		return n*factorial(n-1);
}




int main(int argc, char *argv[]) {
	
	cout << factorial(5) << endl;
}