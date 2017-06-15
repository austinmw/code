/*
Merge sort is based on the divide-and-conquer paradigm. Its worst-case running time has a lower order of growth than insertion sort. Since we are dealing with subproblems, we state each subproblem as sorting a subarray A[p .. r]. Initially, p = 1 and r = n, but these values change as we recurse through subproblems.

To sort A[p .. r]:

1. Divide Step

If a given array A has zero or one element, simply return; it is already sorted. Otherwise, split A[p .. r] into two subarrays A[p .. q] and A[q + 1 .. r], each containing about half of the elements of A[p .. r]. That is, q is the halfway point of A[p .. r].

2. Conquer Step

Conquer by recursively sorting the two subarrays A[p .. q] and A[q + 1 .. r].

3. Combine Step

Combine the elements back in A[p .. r] by merging the two sorted subarrays A[p .. q] and A[q + 1 .. r] into a sorted sequence. To accomplish this step, we will define a procedure MERGE (A, p, q, r).

Note that the recursion bottoms out when the subarray has just one element, so that it is trivially sorted.

*/

#include <iostream>

using namespace std;

template<typename IT> void merge(IT begin, IT middle, IT end, IT res)
{
	IT a = begin, b = middle, r = res;

	while (a < middle && b < end)
		if (*a < *b) *r++ = *a++;
		else *r++ = *b++;

	while (a < middle) *r++ = *a++;
	while (b < end) *r++ = *b++;
	while (begin < end) *begin++ = *res++;
}

template<typename IT> void mergesort(IT begin, IT end, IT res)
{
	int s = end-begin;
	if (s > 1)
	{
		IT middle = begin+s/2;
		mergesort(begin, middle, res);
		mergesort(middle, end, res);
		merge(begin, middle, end, res);
	}
}

int main()
{
	int lst[] = {10, 9, 8, 4, 5, 6, 7, 3, 2, 1};
    int sorted[10];

	mergesort(lst, lst + 10, sorted);

	for (int i = 0; i < 10; i++)
		printf("%d ", sorted[i]);
	cout << endl;
	return 0;
}