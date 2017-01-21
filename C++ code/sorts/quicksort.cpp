// Quicksort:
// Time Complexity: Best: O(nlog(n)), Average: O(nlog(n)), Worst: O(n^2)
// Space Complexity: Worst: O(log(n))

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


vector <int>quicksort(vector<int> unsortedarray)
{
	int n = unsortedarray.size() - 1;
	int pivot = unsortedarray[n];
	int wall = 0;
	
	if (n <= 1){
		return unsortedarray;
	}
	
	
	for(int currentElement = wall; currentElement < n; currentElement++) {
		
		if (unsortedarray[currentElement] < pivot) {
			
			iter_swap(unsortedarray.begin() + wall, unsortedarray.begin() + currentElement);
			
			wall++;
			
			
			// test print
			for (int z = 0; z < unsortedarray.size(); z++)
			{
				cout << unsortedarray[z] << " ";
			}
			cout << endl;
		}
				
	}
	
	
	iter_swap(unsortedarray.begin() + wall, unsortedarray.begin() + n);
	wall++;
	pivot = unsortedarray[n];
	
	// test print
	cout << endl;
	for (int z = 0; z < unsortedarray.size(); z++)
	{
		cout << unsortedarray[z] << " ";
	}
	cout << endl;
	
	
	
	vector<int> left (unsortedarray.begin(), unsortedarray.begin() + wall);
	vector<int> right (unsortedarray.begin() + wall, unsortedarray.end());
	
	// test print left and right vectors
	cout << endl;
	for (int z = 0; z < left.size(); z++)
	{
		cout << left[z] << " ";
	}
	cout << endl;
	for (int z = 0; z < right.size(); z++)
	{
		cout << right[z] << " ";
	}
	cout << endl;
	
	
	vector<int> test(left);
	test = quicksort(left);
	
	
	return unsortedarray;
}

using namespace std;
int main(int argc, char *argv[]) {
	
	vector<int> unsortedarray = {5, 4, 1, 0, 2, 3};
	cout << "5 4 1 0 2 3" << endl << endl;
	quicksort(unsortedarray);
}