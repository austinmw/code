/* Sample inputs:
3
za
*/

// stand vitamins network adapter shorts

#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;
// there is also the throw (with no arguments) or throw() keyword

// catching an exception without loops/conditionals
int main(){
	string S;
	char *end;
	long x;
	cin >> S;
	try {
		cout << stoi(S) << endl;
	} 
	catch(const invalid_argument &e) { // & means passing by reference
	// this means you pass var by reference and not by value so you can manipulate the value of var outside the function.
	// catch(...) is catch-all handler activated for any exception
	// also catch(const invalid_argument) (or invalid_argument&, without any parameter) works
		cout << "Bad String\n" << endl;;
	}
	return 0;
}


/*
// version with conditionals
int main(){
	string S;
	char *end;
	long x;
	cin >> S;
	const char *cstr = S.c_str();
	x = strtol(cstr,&end,10);
	
	if (*end == '\0')
		cout << x;
	else
		cout << "Bad string";
	
	return 0;
}

*/