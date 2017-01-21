#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
/* Sample input:
3
1 2 5
*/

// computes largest difference in vector
class Difference {
	private:
	vector<int> elements;
  
  	public:
  	int maximumDifference;

// Add your code here
Difference(vector<int> array){
	elements = array;
}
void computeDifference(){  
	int temp = 0;
	for (int i = 0; i < elements.size(); i++) {
		for (int j = i+1; j < elements.size(); j++){
			if(abs(elements[i] - elements[j]) > temp)
				temp = abs(elements[i] - elements[j]);       
		}         
	}    
	maximumDifference = temp;
}

}; // End of Difference class

int main() {
	int N;
	cin >> N;
	
	vector<int> a;
	
	for (int i = 0; i < N; i++) {
		int e;
		cin >> e;
		
		a.push_back(e);
	}
	
	Difference d(a);
	
	d.computeDifference();
	
	cout << d.maximumDifference;
	
	return 0;
}