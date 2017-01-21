#include <stdio.h>


int isArrayInSortedOrder(int A[], int n) {
	if(n==1)
		return 1;
	return (A[n-1] < A[n-2])?0:isArrayInSortedOrder(A, n-1);	
}


int main(int argc, char *argv[]) {
	
	int x_sorted, y_sorted;
	int X[] = {1, 2, 3, 4};
	int Y[] = {4, 3, 2, 1};
	
	x_sorted = isArrayInSortedOrder(X, 4);	
	if(x_sorted==1)
		printf("X sorted\n");
	else if(x_sorted==0)
		printf("X not sorted\n");
	
	y_sorted = isArrayInSortedOrder(Y, 4);
	if(y_sorted==1)
		printf("Y sorted\n");
	else if(y_sorted==0)
		printf("Y not sorted\n");
}