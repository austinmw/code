#include <stdio.h>
#define MAX 20
#define SHOWPASS
#define BASE 10
void print(int *a, int n)
{
	int i;
	for (i = 0; i < n; i++)
		printf("%d\t", a[i]);
}
 
void radixsort(int *a, int n)
{
	int i, b[MAX], m = a[0], exp = 1;
	for (i = 1; i < n; i++)
	{
		if (a[i] > m)
			m = a[i];
	}
 
	while (m / exp > 0)
	{
		int bucket[BASE] ={  0 };
		for (i = 0; i < n; i++)
			bucket[(a[i] / exp) % BASE]++;
		for (i = 1; i < BASE; i++)
			bucket[i] += bucket[i - 1];
		for (i = n - 1; i >= 0; i--)
			b[--bucket[(a[i] / exp) % BASE]] = a[i];
		for (i = 0; i < n; i++)
			a[i] = b[i];
		exp *= BASE;
 
		#ifdef SHOWPASS
			printf("\nPASS   : ");
			print(a, n);
		#endif
	}
}
 
int main()
{
	int arr[MAX];
	int i, n;
	printf("Enter total elements (n <= %d) : ", MAX);
	scanf("%d", &n);
	n = n < MAX ? n : MAX;
 
	printf("Enter %d Elements : ", n);
	for (i = 0; i < n; i++)
		scanf("%d", &arr[i]);
 
	printf("\nARRAY  : ");
	print(&arr[0], n);
 
	radixsort(&arr[0], n);
 
	printf("\nSORTED : ");
	print(&arr[0], n);
	printf("\n");
}

/*
A comparison sort algorithm compares pairs of the items being sorted and the output of each comparison is binary(i.e. smaller than or not smaller than). Radix sort considers the digits of the numbers in sequence and instead of comparing them, groups numbers in buckets with respect to the value of the digit(in a stable manner). Note that the digit is not compared to anything - it is simply put in a bucket corresponding to its value.

It is important to know why we care about comparison/non-comparison sort algorithms. If we use a comparison sort algorithm then on each comparison we will split the set of possible outcomes roughly in half(because the output is binary) thus the best complexity we can possibly have is O(log(n!)) = O(n*log(n)). This restriction does not hold for non-comparison sorts.


Radix sort implementation:
	
start with m=10, n=1
10 linked lists, 0 -> 9
each number % 10 = x / n  -> put in respective linked list 
go through each list 0-> 9 and put back in array, in order they are found

repeat with new array
multiply m and n by 10 for next sig digit
so next go around, 
(num % 100) / 10  -> list

keep going until max sig digit column is completed


btw: integer will cast e.g. 7.9 into 7
*/

