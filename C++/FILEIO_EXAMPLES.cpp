#include <iostream> // cin, cout, cerr, clog, wide chars (chinese, etc.)
#include <string> //C++ (C-style strings [char arrays] are in <cstring>)










using namespace std;

// #include <iostream>
void iostream_fn(){
	int in, out;
	cin >> in;
	out = in;
	cout << out;
	;
}

// #include <string>
void string_fn(){
	cin.ignore(); // move past previous '\0'
	string s;
	getline(cin, s);
	cout << s;
}

// #include <cstdlib>





// #include <fstream>
// #include <sstream>

/*
const int x(42);
stringstream ss;
ss << "My favorite number is: " << x << std::endl;
Here stringstream automatically converts x to a string and appends it. I do not need to call atoi. Stringstream will convert all the basic types automatically for you. It is great for that purpose.
*/







int main(int argc, char *argv[]) {
	iostream_fn();
	cout << endl;
	string_fn();
	cout << endl;
	cstdio_fn();
}
/* Sample input:
	5
	blah
*/