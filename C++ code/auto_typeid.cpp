#include <iostream>
using namespace std;

// compile flag: -std=c++14

auto fn(){
	return 5;
}

int main() {
	
	// c++ 14 auto return type feature
	cout << fn() << endl;;
	
	// typeid
	auto x = 2;	
	cout << typeid(x).name() << endl;
	
	auto y = 3.1;
	cout << typeid(y).name() << endl;
	
	auto z = "hola";
	cout << typeid(z).name() << endl;
	
	auto a = 'g';
	cout << typeid(a).name() << endl;
	
}