#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;



int main() {
	int n, l, f;
	string s;
	cin >> n;
	
	
	getline(cin,s);
	for (int i = 0; i < n; i++) {
	   // get and set
	   f = 1;
	   getline(cin, s);
	   l = s.length();
	   // reverse
	   char r[l];
	   for (int j = 0; j < l; j++) {
		   r[l-j-1] = s[j];
	   } 
	   // check
	   for (int x = 1; x < l; x++) { 
	       if (!(abs(s[x] - s[x-1]) == abs(r[x] - r[x-1])))
		      f = 0;
	   }    
		// print
		if (f == 1)
			   cout << "Funny" << endl;
		else
			   cout << "Not Funny" << endl;
	}
	
	return 0;
}

/*
Objective 
Today we're expanding our knowledge of Strings and combining it with what we've already learned about operators and loops. Check out the Tutorial tab for learning materials and an instructional video!

Task 
Suppose you have a String, SS, of length NN that is indexed from 00 to N−1N−1. You also have some String, RR, that is the reverse of String SS. SS is funny if the condition |S[i]−S[i−1]|=|R[i]−R[i−1]||S[i]−S[i−1]|=|R[i]−R[i−1]| is true for every character ii from 11 to N−1N−1.

Note: For some String SS, S[i]S[i] denotes the ASCII value of the ithith 00-indexed character in SS. The absolute value of an integer, xx, is written as |x||x|.

Input Format

The first line contains an integer, TT (the number of test cases). 
Each line ii of the TT subsequent lines contain a String, SS.

Constraints

1≤T≤101≤T≤10
2≤length of S≤100002≤length of S≤10000
Output Format

For each String SjSj (where 0≤j≤T−10≤j≤T−1), print whether it is 𝙵𝚞𝚗𝚗𝚢Funny or 𝙽𝚘𝚝 𝙵𝚞𝚗𝚗𝚢Not Funny on a new line.

Sample Input

2
acxz
bcxz
Sample Output

Funny
Not Funny
Explanation

Test Case 0: S="acxz"S="acxz" 
|c−a|=2=|x−z||c−a|=2=|x−z| 
|x−c|=21=|c−x||x−c|=21=|c−x| 
|z−x|=2=|a−c||z−x|=2=|a−c| 
As each comparison is equal, we print 𝙵𝚞𝚗𝚗𝚢Funny.

Test Case 1: S="bcxz"S="bcxz" 
|c−b|=1|c−b|=1, but |x−z|=2|x−z|=2 
At this point, we stop evaluating SS (as |c−b|≠|x−z||c−b|≠|x−z|) and print 𝙽𝚘𝚝 𝙵𝚞𝚗𝚗𝚢Not Funny.
*/