#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;



int main() {
	int n, l;
	string s;
	cin >> n;
	
	getline(cin,s);
	for (int i = 0; i < n; i++) {
	   getline(cin, s);
	   l = s.length();
	   char r[l];
	   for (int j = 0; j < l; j++) {
		   r[l-j-1] = s[j];
	   } 
	    
		for (int x = 0; x < l; x++)
			cout << r[x];
		cout << endl;
		
	}
	
	
	
	/* Enter your code here. Read input from STDIN. Print output to STDOUT */   
	return 0;
}
