#include <iostream>
#include <string>     // gives you string functions
using namespace std;

int main() {	
	string x, y, z;

	
	// white-space delimiter
	cin >> x;
	cout << "The string I entered is: " << x << endl;
	
	// '\n' delimiter (by default)
	cin.ignore();
	getline(cin, y);
	cout << "The next string is: " << y << endl;
	
	// '-' delimiter
	getline(cin, z, '-');
	cout << "The 3rd string is: " << z << endl;	
	
	
	// other string stuff
	// create strings
	string s1 = "yada";
	string s2("blah");  // another way to create a string
	string s3;
	cout << s1 << endl << s2 << endl;
	
	s3 = s1;  // string copy
	s3.assign(s1);  // identical string copy
	
	cout << s3[0] << endl;    // array index
	cout << s3.at(0) << endl;  // identical array index
	
	
	for (int x = 0; x < s2.length(); x++) { // loop through string
		cout << s1.at(x);
	}
	
}

/* Sample input:
tuna
motha fuckaaa
white-space
*/