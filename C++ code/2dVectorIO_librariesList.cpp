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
using namespace std;


int main(){
	// input vector
	vector< vector<int> > arr(6,vector<int>(6));
	for(int arr_i = 0;arr_i < 6;arr_i++){
	   for(int arr_j = 0;arr_j < 6;arr_j++){
		  cin >> arr[arr_i][arr_j];
	   }
	}

	int temp, highSum;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			temp = 0;
			temp = arr[i][j]+arr[i][j+1]+arr[i][j+2]+arr[i+1][j+1] \
			+arr[i+2][j]+arr[i+2][j+1]+arr[i+2][j+2];    
			
			
			if ((i == 0) && (j == 0))
				highSum = temp;
			else if (temp > highSum)
				highSum = temp;
		}
	}    
	cout << highSum;

	return 0;
	
	// output vector
	for (int x = 0; x < arr[0].size(); x++) {
		for (int y = 0; y < arr.size(); y++)
			cout << arr[x][y];
		cout << endl;
	}
}
