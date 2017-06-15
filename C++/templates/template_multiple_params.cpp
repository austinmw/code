#include <iostream>
using namespace std;


// multiple parameter types
// one capital letter is standard style
template <class T, class U>
T smaller(T a, U b) {
	return (a<b?a:b);
}



int main() {

	int x = 89;
	double y = 56.78;
	
	cout << smaller(x, y) << endl;
}