#include <iostream>
using namespace std;

#include <vector>

// C++14 allows Generalized/generic Lambda functions

int main() {
	
	// C++11 lambda (anonymouse function)
	auto func = [] (int input) { return input * input; };
	cout << func(10) << endl;
	
	
	// C++14 compile flag: -std=c++14
	auto func2 = [] (auto input) { return input * input; };
	cout << func2(5.5) << endl;
	
	// anonymous functions also useful:
	vector<int> some_list;
	int total = 0;
	
	for (int i=0;i<5;i++) 
		some_list.push_back(i);
		
	for_each(begin(some_list), end(some_list), [&total](int x) {
		total += x;
	});
	cout << total << endl;
	
	/* 
	std::for_each
	template <class InputIterator, class Function>
		Function for_each (InputIterator first, InputIterator last, Function fn); 
	Apply function to range 
	Applies function fn to each of the elements in the range [first,last).
	*/
	
	
}


/* 
[] is called the capture list, you can basically capture values defined previously 
in your code and make them visible from the body of the lambda. 


*/