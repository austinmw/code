#include <iostream>
#include "Sally.h"
using namespace std;


int main(int argc, char *argv[]) {
	
	Sally sallyObj;
	sallyObj.printShiz();
	
	
	const int x = 3;
	// can create unmodifiable objects by using const keyword
	// constant objects require constant functions!
	const Sally constObj;
	constObj.constPrint();
	
}