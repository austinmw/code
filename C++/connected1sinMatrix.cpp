#include <stdio.h>
#include <iostream>

using namespace std;

int getval(int (*A)[5], int i, int j, int L, int H) {
	if(i<0 || i>=L || j<0 || j>=H)
		return 0;
	else {
		return A[i][j];
	}
}


void findMaxBlock(int (*A)[5], int r, int c, int L, int H, int size, bool **cntarr, int &maxsize){
	if(r>=L || c >=H)
		return;
	cntarr[r][c]=true; 
	size++;
	if(size>maxsize)
		maxsize = size;
	//search in eight directions
	int direction[][2]={{-1,0},{-1,-1},{0,-1},{1,-1},{1,0},{1,1},{0,1},{-1,1}};
	for(int i=0; i<8; i++) {
		int newi = r+direction[i][0];
		int newj = c+direction[i][1];
		int val = getval(A, newi, newj, L, H);
		if(val>0 && (cntarr[newi][newj]==false)){
			findMaxBlock(A, newi, newj, L, H, size, cntarr, maxsize);
		}
	}
	cntarr[r][c]=false;
}


bool** create2darr(int rmax, int colmax) { // In C99, you can use variable-length arrays:		
		bool **mat = new bool*[rmax];
		for(int i = 0; i < rmax; i++) mat[i] = new bool[colmax];
		return mat;
}


int getMaxOnes(int (*A)[5], int rmax, int colmax) {
	int maxsize = 0;
	int size = 0;
	bool **cntarr = create2darr(rmax, colmax);
	for(int i=0; i<rmax; i++){
		for(int j=0; j<colmax; j++){
			if(A[i][j] == 1){
				findMaxBlock(A, i, j, rmax, colmax, 0, cntarr, maxsize);
			}
		}
	}
	return maxsize;
}




int main(int argc, char *argv[]) {
	
	int zarr[][5] = {{1,1,0,0,0},{0,1,1,0,0},{0,0,1,0,1},{1,0,0,0,1},{0,1,1,1,1}};
	cout << "Number of maximum 1s are " << getMaxOnes(zarr, 5, 5) << endl;
	
	
}

/*
11000
01100
00101
10001
01111

ans: 7 (diagonals count too)
*/
