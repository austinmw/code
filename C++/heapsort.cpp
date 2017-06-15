/*
 * C++ Program to Implement Heap Sort
	O(n log(n))	O(n log(n))	O(n log(n))	O(1)
	Best 	Average		Worst 	Space		
 */
#include <iostream>
using namespace std;
void max_heapify(int *a, int i, int n)
{
	int j, temp;
	temp = a[i];
	j = 2*i;
	while (j <= n)
	{
		if (j < n && a[j+1] > a[j])
			j = j+1;
		if (temp > a[j])
			break;
		else if (temp <= a[j])
		{
			a[j/2] = a[j];
			j = 2*j;
		}
	}
	a[j/2] = temp;
	return;
}
void heapsort(int *a, int n)
{
	int i, temp;
	for (i = n; i >= 2; i--)
	{
		temp = a[i];
		a[i] = a[1];
		a[1] = temp;
		max_heapify(a, 1, i - 1);
	}
}
void build_maxheap(int *a, int n)
{
	int i;
	for(i = n/2; i >= 1; i--)
	{
		max_heapify(a, i, n);
	}
}
int main()
{
	int n, i, x;
	cout<<"enter no of elements of array\n";
	cin>>n;
	int a[n];//was 20
	for (i = 1; i <= n; i++)
	{
		cout<<"enter element"<<(i)<<endl;
		cin>>a[i];
	}
	build_maxheap(a,n);
	heapsort(a, n);
	cout<<"sorted output\n";
	for (i = 1; i <= n; i++)
	{
		cout<<a[i]<<endl;
	}
	fflush(stdin);
	getchar();
}

/*
from array: just fill in from 1->n then maxheapify()
for (i = floor(length(array)/2); i >= 1; i--) {
	maxheapify(A,i);
}
maxheapify(A,i){}
the last step (when i is at the root) is to simply call Max-Heapify, which fixes the rest of the issues in the Heap. So, to re-cap, first you fill up the heap, top to bottom, left to right (just for visuals - its actually just an array). Next you begin calling Max-Heapify from the bottom (middle of the array) to the top. Max-Heapify will correct any issues within the "sub-tree" that it is working on. As it moves upward, it continually fixes the Heap (all the way to the bottom from where it is currently being called).
*/