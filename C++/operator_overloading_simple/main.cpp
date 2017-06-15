#include <iostream>
#include "Sally.h"
using namespace std;

int main(int argc, char *argv[]) {
	
	Sally a(34);
	Sally b(21);
	Sally c;
	
	c = a + b;
	cout << c.num;
}