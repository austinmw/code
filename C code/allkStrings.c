#include <stdio.h>


char A[2];


void k_string(int n, int k) {
	// process all the k-ary strings of length n
	if(n<1)
		printf("%s\n", A);
	else {
		for (int j=0;j<k;j++){
			A[n-1] = j +'0' ;
			k_string(n-1, k);
		}
	}
}



int main(int argc, char *argv[]) {
	// length: 2, chars: 4	
	k_string(2, 4);
}