#include <iostream>
using namespace std;

// TEMPLATE SPECIALIZATION: a way to make a class that has a different implementation
// when a specific type is passed into it



// class template
template <class T>
class Spunky{
	public:
		Spunky(T x){ // everything but characters
			cout << x << " is not a character!" << endl;
		}
};



// template specialization
template<>
class Spunky<char>{
	public:
		Spunky(char x) {
			cout << x << " is indeed a character!" << endl;	
		}
};



int main() {
	
	Spunky<int> a(5);
	Spunky<int> b('c');
	Spunky<double> c(5.2);
	Spunky<char> d('f');
	Spunky<char> e(90);
}