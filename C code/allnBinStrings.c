#include <stdio.h>


char A[5];


void Binary(int n){
	if(n<1)
		printf("%s\n", A);
	else {
		A[n-1] = '0';
		Binary(n-1);
		A[n-1] = '1';
		Binary(n-1);
	}
}


int main(int argc, char *argv[]) {
	
	Binary(4);
}