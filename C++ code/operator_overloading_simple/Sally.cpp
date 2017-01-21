#include <iostream>
#include "Sally.h"
using namespace std;

Sally::Sally()
{}

Sally::Sally(int a){
	num = a;
}

// return type, class::function name (operator+), parameter
Sally Sally::operator+(Sally aso){
	Sally brandNew;
	brandNew.num = num + aso.num;
	return(brandNew);
}