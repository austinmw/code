#include <stdio.h>

int main(int argc, char *argv[]) {
	int n , m;
	scanf("%d %d", &n, &m);
	int X[n][m];
	
	X[n-1][m-1] = 5;
	printf("%d", X[n-1][m-1]);
}

// variably modified type
// sample input: 3 3