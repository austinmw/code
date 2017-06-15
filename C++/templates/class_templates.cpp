#include <iostream>
using namespace std;

// class templates

template <class T>
class Austin{
	T first, second;
	public:
		Austin(T a, T b){
			first = a;
			second = b;
		}
		T bigger();
};


// need this before every single function member outside of class template
// this is the stupid format:
template <class T>
T Austin<T>::bigger(){
	return (first>second?first:second);
}


int main() {
	
	// have to give it type, e.g. like vectors
	Austin<int> a(69, 105);
	cout << a.bigger() << endl;
	
	Austin<double> b(5.5, 6.5);
	cout << b.bigger() << endl;
}