
// AUTHOR1: Austin Welch austinmw@bu.edu
// AUTHOR2: Wasim Khan wasimk95@bu.edu
// AUTHOR3: Dave Ferullo dferullo@bu.edu

int min(int x, int y)
{
	if (x < y)
		return x;
	else
		return y;
}

int NthElement(int Array1[], int Array2[], int Size1, int Size2, int N){
	
	int i =  min(Size1, N/2) ;  
	int j =  min(Size2, N/2) ; 

	if(Size1 > Size2)
		return NthElement(Array2, Array1, Size2, Size1, N);
		if(Size1 == 0)
		   return Array2[N-1];
 
		if(N == 1)
			return min(Array1[0], Array2[0]);

		if(Array1[i-1] > Array2[j-1])
			return NthElement(Array1, Array2+j, i, Size2-j, N-j);
		else
			return NthElement(Array1+i, Array2, Size1-i, j,  N-i);
 
		return 0;
}
 
int  finding_median(int Array1[], int Array2[], int Size1, int Size2){
	int L = (Size1 + Size2 + 1) >> 1;
	int R = (Size1 + Size2 + 2) >> 1;
 
	return  ((NthElement(Array1, Array2, Size1, Size2, L) +
				  NthElement(Array1, Array2, Size1, Size2, R))/2);
}

/*
int main(){
 
	int Array1[] = {0, 1, 2};
	int Array2[] = {4, 5, 6, 7, 8, 9};
 
	int size1  = sizeof(Array1)/sizeof(Array1[0]);
	int size2  = sizeof(Array2)/sizeof(Array2[0]);
 	
	// with stdio
	printf("\nmedian is: %d", finding_median(Array1,Array2,size1, size2));
	return 0;
}
*/