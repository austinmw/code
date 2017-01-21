//Insertion Sort: 
//Time Complexity: Best: O(n), Average: O(n^2), Worst: O(n^2)
//Space Complexity: Worst: O(1)
	
#include <iostream>
#include <stdlib.h>

using namespace std;

void insertion_sort (int arr[], int length){
	 	int j, temp;
		
	for (int i = 0; i < length; i++){
		j = i;
		
		while (j > 0 && arr[j] < arr[j-1]){
			  temp = arr[j];
			  arr[j] = arr[j-1];
			  arr[j-1] = temp;
			  j--;
			  }
		}
}

int main(){
	
	int a[] = {1, 5, 6, 2, 8, 1, 4, 0};
	int n = (sizeof(a)/sizeof(*a));  // size in bytes of array / size in bytes of type
	//cout << sizeof(a) << " " << sizeof(*a) << " " << n << endl;
	insertion_sort(a, n);
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
	return 0;
}

/*
Although it is one of the elementary sorting algorithms with O(n2) worst-case time, insertion sort is the algorithm of choice either when the data is nearly sorted (because it is adaptive) or when the problem size is small (because it has low overhead).

For these reasons, and because it is also stable, insertion sort is often used as the recursive base case (when the problem size is small) for higher overhead divide-and-conquer sorting algorithms, such as merge sort or quick sort.

Insertion sort is another sorting algorithm, which operates by inserting an element in the input list in to the correct position in a list (that is already sorted). This process is applied repeatedly until the list is sorted. In insertion sort, sorting is carried out in-place. Therefore after the ith iteration of the algorithm, the first i+1 entries in the list will be sorted and the rest of the list will be unsorted. At each iteration, the first element in the unsorted part of the list will be taken and inserted in to the correct place in the sorted section of the list. Insertion sort has an average case time complexity of O(n2). Due to this, insertion sort is also not suitable for sorting large lists.
*/
