/* Sample input:
6
riya riya@gmail.com
julia julia@julia.me
julia sjulia@gmail.com
julia julia@gmail.com
samantha samantha@gmail.com
tanya tanya@gmail.com
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

vector<string> names;
int main(){
	int N;
	cin >> N;
	for(int a0 = 0; a0 < N; a0++){
		string firstName;
		string emailID;
		cin >> firstName >> emailID;
		size_t found = emailID.find("@gmail.com");
		if (found!=std::string::npos) {
	 		names.push_back(firstName);
		}
	}

	sort (names.begin(), names.end());
	for(int i = 0; i < names.size(); i++){
		cout << names[i] << endl;	
	}
	
	return 0;
}
