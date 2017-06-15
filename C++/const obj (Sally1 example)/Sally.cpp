#include <iostream>
#include "Sally.h"
using namespace std;


Sally::Sally(){
	cout << "i am the constructor!" << endl;
}

Sally::~Sally(){
	cout << "i am the deconstructor!" << endl;
}

void Sally::printShiz(){
	cout << "i am a regular function" << endl;
}

void Sally::constPrint() const{
	cout << "i am a constant function" << endl;
}