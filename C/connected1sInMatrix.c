#include <stdio.h>
#include <stdlib.h>

// REMEMBER PASS BY REFERENCE IS C++ ONLY
// You need to pass pointer to a variable if you want to change the variable in a function 
// and want the change to be visible in the calling function


int getval(int (*A)[5], int i, int j, int L, int H) {
	if(i<0 || i>=L || j<0 || j>=H)
		return 0;
	else {
		return A[i][j];
	}
}


void findMaxBlock(int (*A)[5], int r, int c, int L, int H, int size, int **cntarr, int *max_sz){
	if(r>=L || c >=H)
		return;
	cntarr[r][c]=1; 
	size++;
	if(size>*max_sz)
		*max_sz = size;
	//search in eight directions
	int direction[][2]={{-1,0},{-1,-1},{0,-1},{1,-1},{1,0},{1,1},{0,1},{-1,1}};
	for(int i=0; i<8; i++) {
		int newi = r+direction[i][0];
		int newj = c+direction[i][1];
		int val = getval(A, newi, newj, L, H);
		if(val>0 && (cntarr[newi][newj]==0)){
			findMaxBlock(A, newi, newj, L, H, size, cntarr, max_sz);
		}
	}
	cntarr[r][c]=0;
}


int** create2darr(int rmax, int colmax) { 	
		int **mat = (int**)calloc(rmax, sizeof(int*));
		for(int i = 0; i < rmax; i++) mat[i] = (int*)calloc(colmax, sizeof(int));
		return mat;
}


int getMaxOnes(int (*A)[5], int rmax, int colmax) {
	int max_sz = 0;
	int size = 0;
	int **cntarr = create2darr(rmax, colmax);
	for(int i=0; i<rmax; i++){
		for(int j=0; j<colmax; j++){
			if(A[i][j] == 1){
				findMaxBlock(A, i, j, rmax, colmax, 0, cntarr, &max_sz);
			}
		}
	}
	return max_sz;
}


int main(int argc, char *argv[]) {
	int zarr[][5] = {{1,1,0,0,0},{0,1,1,0,0},{0,0,1,0,1},{1,0,0,0,1},{0,1,1,1,1}};
	printf("Number of maximum 1s are %d\n", getMaxOnes(zarr, 5, 5));
}

/*
11000
01100
00101
10001
01111

ans: 7 (diagonals count too)
*/
