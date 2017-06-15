#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int factorial(int N){
   if (N <= 1) 
	   return N;
	else 
		return N * factorial(N-1); 
}

int main() {
	/* Enter your code here. Read input from STDIN. Print output  
	return 0;*/
	int N;
	cin>>N;
	cout << factorial(N);
	
}
