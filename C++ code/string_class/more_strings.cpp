#include <iostream>
#include <string>
using namespace std;

int main() {
	
	// substring
	string s1("Testing string stuff");
	cout << s1.substr(15, 5) << endl;
	
	// swap
	string one("apples ");
	string two("beans ");
	cout << one << two << endl;
	one.swap(two);
	cout << one << two << endl;
	
	// find 
	string s2("hello austin did you forget how to search strings? austin");
	cout << s2.find("austin") << endl; // returns starting index
	cout << s2.rfind("austin") << endl; // reverse find
	
	// erase
	string s3("hi my name is austin and I love bacon");
	s3.erase(20); // (inclusive)
	cout << s3 << endl;
	
	// replace
	string s4("this is a string i am going to replace");
	s4.replace(10, 6, "blah");
	cout << s4 << endl;
	
	// insert
	string s5("i am going to insert something");
	s5.insert(14, "quickly ");
	cout << s5 << endl;
	
}