#include <iostream>
using namespace std;


// Uninitialized matrix
int** create2darr(int rmax, int colmax) { // In C99, you can use variable-length arrays:		
		int **mat = new int*[rmax];
		for(int i = 0; i < rmax; i++) mat[i] = new int[colmax];
		return mat;
}


// Zero initialized matrix
int** create2darrZeroInit(int rmax, int colmax) { // In C99, you can use variable-length arrays:		
		int **mat = new int*[rmax](); // notice the parenthesis
		for(int i = 0; i < rmax; i++) mat[i] = new int[colmax]();
		return mat;
}


using namespace std;
int main(int argc, char *argv[]) {
	
	// message
	cout << "Run multiple times if first array is showing as 0's" << endl;
	
	// set row and col sizes
	int r = 5, c = 5;
	
	// create uninitialized A and initialized B matrices
	int **A = create2darr(r, c);
	int **B = create2darrZeroInit(r, c);
	
	
	// print A (uninitialized matrix)
	for (int i=0; i<r;i++){
		for (int j=0; j<c;j++) {
			cout << A[i][j] << " ";
		}
		cout << endl;
	}
	
	// print B (initialized matrix)
	for (int i=0; i<r;i++){
		for (int j=0; j<c;j++) {
			cout << B[i][j] << " ";
		}
		cout << endl;
	}
	
	// delete after use
	for (int i = 0; i < r; ++i)
		delete [] A[i];
	delete [] A;
	
	for (int i = 0; i < r; ++i)
		delete [] B[i];
	delete [] B;
}


/*
The delete operator deallocates memory and calls the destructor for a single object created with new.

The delete [] operator deallocates memory and calls destructors for an array of objects created with new [].
*/