#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
// could also use vector<pair<A, B> >
// Map in C++ (dictionary in python)

int main() {
	int n;
	long number;
	string name, input;
	map<string,long> phonebook;
	map<string,long>::iterator it;
	
	// number of inputs
	cin>>n;
	// input name number pairs
	for (int i = 0; i < n; i++) {
		cin>>name>>number;
		phonebook[name]=number;
	}
	// continually input names to check for membership
	while (cin>>input) {
		it = phonebook.find(input);
		if (it == phonebook.end()) 
			cout << "Not found\n";
		else 
			cout << input << "=" << it->second << endl;
	}
	return 0;
}
