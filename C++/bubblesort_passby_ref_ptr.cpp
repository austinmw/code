/* Sample input: 
10
2 20 49 19 4 0 48 38328 2 1
*/
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

// usage: can pass null pointer, cannot pass null reference


// PASS BY REFERENCE:
void BubbleSort(vector<int> &a) {
	int n = a.size(), numberOfSwaps = 0;	
	for (int i = 0; i < n; i++) {	
		for (int j = 0; j < n - 1; j++) {
			if (a[j] > a[j + 1]) {
				swap(a[j], a[j + 1]);
				numberOfSwaps++;
			}
		}
		if (numberOfSwaps == 0) {
			break;
		}
	}
}

int main(){
	// input size and array
	int n;
	cin >> n;
	vector<int> a(n);
	for(int a_i = 0;a_i < n;a_i++){
	   cin >> a[a_i];
	}
	// sort
	BubbleSort(a);
	// print
	for (auto i = a.begin(); i != a.end(); ++i)
		cout << *i << ' '; 

	return 0;
}



/* 
// PASS BY POINTER:	
void BubbleSort(vector<int> *a) {
	int n = a->size(), numberOfSwaps = 0;	
	for (int i = 0; i < n; i++) {	
		for (int j = 0; j < n - 1; j++) {
			if ((*a)[j] > (*a)[j + 1]) {
				swap((*a)[j], (*a)[j + 1]);
				numberOfSwaps++;
			}
		}
		if (numberOfSwaps == 0) {
			break;
		}
	}
}

int main(){
	// input size and array
	int n;
	cin >> n;
	vector<int> a(n);
	for(int a_i = 0;a_i < n;a_i++){
	   cin >> a[a_i];
	}
	// sort
	BubbleSort(&a);
	// print
	for (auto i = a.begin(); i != a.end(); ++i)
		cout << *i << ' '; 

	return 0;
}
*/



/* 
//SUBMITTED CODE:	
int BubbleSort(vector<int> &a) {
	int n = a.size(), numberOfSwaps = 0;	
	for (int i = 0; i < n; i++) {	
		for (int j = 0; j < n - 1; j++) {
			if (a[j] > a[j + 1]) {
				swap(a[j], a[j + 1]);
				numberOfSwaps++;
			}
		}
		if (numberOfSwaps == 0) {
			break;
		}
	}
	return numberOfSwaps;
}

int main(){
	int n, swaps = 0;
	cin >> n;
	vector<int> a(n);
	for(int a_i = 0;a_i < n;a_i++){
	   cin >> a[a_i];
	}
	swaps = BubbleSort(a);
	cout << "Array is sorted in " << swaps << " swaps." << endl;
	cout << "First Element: " << a.front() << endl;
	cout << "Last Element: " << a.back() << endl;
	return 0;
}
*/