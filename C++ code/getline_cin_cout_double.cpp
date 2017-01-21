#include <iostream>
#include <iomanip> // IO Manipulators: for setprecision()
using namespace std;

int main() {
	int i = 4;
	double d = 4.0;
	string s = "HackerRank ";
	
	
	// Declare second integer, double, and String variables.
	int j;
	double k;
	string ss;
	// Read and save an integer, double, and String to your variables.
	cin>>j>>k;
	getline(cin, ss); // newline char after double
	getline(cin, ss);
	// Print the sum of both integer variables on a new line.
	cout << i+j << endl;
	// Print the sum of the double variables on a new line.
	cout << fixed << setprecision(1) << d+k << endl;
	// Concatenate and print the String variables on a new line
	// The 's' variable above should be printed first.
   cout << s << ss << endl;
	
	return 0;
}