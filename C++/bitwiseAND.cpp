/* Sample input 
3
5 2
8 5
2 2
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


int main(){
	int t;
	cin >> t;
	for(int a0 = 0; a0 < t; a0++){
		int high = 0;
		int n;
		int k;
		int a;
		cin >> n >> k;
		
		// solution here		
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j < i; j++) {
				a = i&j;
				if ((a < k) && (a > high))
					high = a;
			}
		}
		cout << high << endl;
	}
	return 0;
}
