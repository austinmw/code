/* Complexity
Time: Worst/Average/Best: O(nlogn)     merge_sort: logn, merge: n
Space: Worst: O(n)
*/

#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int> &numbers, vector<int> &temp_numbers, int left, int mid, int right);
int l = 0, r = 0, m = 0;

void merge_sort(vector<int> &numbers, vector<int> &temp_numbers, int left, int right){     
	int mid;	
	
	if (right > left) { // If array size > 1
		mid = (left+right)/2;
		cout << "LEFT SORT" << endl;
		l++;
		merge_sort(numbers, temp_numbers, left, mid);   
		cout << "RIGHT SORT"  << endl;
		r++;
		merge_sort(numbers, temp_numbers, mid+1, right); 
		cout << "MERGE" << endl;
		m++;
		merge(numbers, temp_numbers, left, mid+1, right);	
	} // else: return back to one level up (implicit)
}

void merge(vector<int> &numbers, vector<int> &temp_numbers, int left, int mid, int right){
	int i, left_end, size, temp_pos;
	left_end = mid - 1;
	temp_pos = left;
	size = right-left + 1;
	
	while ((left <= left_end) && (mid <= right)) {
		if (numbers[left] <= numbers[mid]) {
			temp_numbers[temp_pos] = numbers[left];
			temp_pos++;
			left++;
		}	
		else {
			temp_numbers[temp_pos] = numbers[mid];
			temp_pos++;
			mid++;
		}
	}
	while (left <= left_end) {
		temp_numbers[temp_pos] = numbers[left];
		left++;
		temp_pos++;
	}
	while (mid <= right) {
		temp_numbers[temp_pos] = numbers[mid];
		mid++;
		temp_pos++;
	}
	for (i = 0; i < size; i++) {
		numbers[right] = temp_numbers[right];
		right--;
	}
}

int main(int argc, char *argv[]) {
	
	vector<int> numbers, temp_numbers;
	int x, n;
	
	// setup
	cout << "Enter numbers to sort separated by spaces. ";
	cout << "Press Ctrl+D when you are finished.\n\n";
	while(cin >> x) {
		numbers.push_back(x);
	}
	n = numbers.size();
	temp_numbers.resize(n);
	cout << "\nCount: " << n << endl << "Numbers to be sorted: ";
	for (int i = 0; i < n; i++)
		cout << numbers[i] << " ";
	cout << endl << endl << "Steps taken:\n";
		
	// sort
	merge_sort(numbers, temp_numbers, 0, n-1);

	// print
	cout << endl << "Sorted array: ";
	for (int i = 0; i < n; i++)
		cout << numbers[i] << " ";
	cout << endl << endl << "left sorts: " << l << "  right sorts: ";
	cout << r << "  merges: " << m << endl;	
	return 0;
}



/* Example 


		4 3 2 1
		
     4 3		2 1 
	
4		3		2		1

   	3 4			1 2
		
		1 2 3 4


left split
left split -> return one up
right -> return one up
merge -> return to top
right 
left -> return one up
right -> return one up
merge -> return to top
merge

*/