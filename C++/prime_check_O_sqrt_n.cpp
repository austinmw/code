/* Sample input:
	3
	12
	5
	7
*/
	
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


// O(sqrt(n))
void PrimeCheck(int n) {
	if (n == 1) {
		printf("Not prime\n");
		return;
	}
	
	for (int i = 2; i < sqrt(n); i++) {
		if (n%i == 0) {
			printf("Not prime\n");
			return;
		}
	}
	printf("Prime\n");
	return;
}



int main() {	
	int T, n;
	cin >> T;
	
	for (int i = 0; i<T; i++) {
		cin >> n;
		PrimeCheck(n);
	
	}	
	return 0;
}
