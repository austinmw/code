#include <stdio.h>
#include <stdlib.h>


/* "You must call free once for each malloc. Your code has one malloc and one free (with the same address) so it is correct." */


// Uninitialized matrix
int** mallocMatrix(int rmax, int colmax) {		
		int **mat = malloc(rmax*sizeof(int*));
		for(int i = 0; i < rmax; i++) mat[i] = malloc(colmax * sizeof(int));
		return mat;
}


// Zero initialized matrix
int** callocMatrix(int rmax, int colmax) { 	
		int **mat = calloc(rmax, sizeof(int*));
		for(int i = 0; i < rmax; i++) mat[i] = calloc(colmax, sizeof(int));
		return mat;
}


// Fill matrix
void fillMatrix(int **mat, int r, int c){
	printf("Insert the elements of your matrix:\n");
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			printf("Insert element [%d][%d]: ", i, j);
			scanf("%d", &mat[i][j]);
			printf("matrix[%d][%d]: %d\n", i, j, mat[i][j]);
		}
	}
	return;
}


// Print matrix
void printMatrix(int **mat, int r, int c){
	for (int i=0; i<r;i++){
		for (int j=0; j<c;j++) {
				printf("%d ", mat[i][j]);
		}
		printf("\n");
	}
}


// Uninitialized 3D matrix
int*** malloc3Dmatrix(int n_rows, int n_cols, int depth) {
	int ***matrix;
	matrix = malloc(n_rows*sizeof(int**));
	for (int row = 0; row < n_rows; row++) {
		matrix[row] = malloc(n_cols*sizeof(int*));
		for (int col = 0; col < n_cols; col++) {
			matrix[row][col] = malloc(depth*sizeof(int));
		}
	}
	return matrix;
}


// Zero initialized 3D matrix
int*** calloc3Dmatrix(int n_rows, int n_cols, int depth) {
	int ***matrix;
	matrix = calloc(n_rows, sizeof(int**));
	for (int row = 0; row < n_rows; row++) {
		matrix[row] = calloc(n_cols, sizeof(int*));
		for (int col = 0; col < n_cols; col++) {
			matrix[row][col] = calloc(depth, sizeof(int));
		}
	}
	return matrix;
}


// fill 3D matrix
void fill3DMatrix(int ***matrix, int n_rows, int n_cols, int depth) {
	
	printf("Insert the elements of your matrix:\n");
	for (int i = 0; i < n_rows; i++) {
		for (int j = 0; j < n_cols; j++) {
			for (int k = 0; k < depth; k++) {
				printf("Insert element [%d][%d][%d]: ", i, j, k);
				scanf("%d", &matrix[i][j][k]);
				printf("matrix[%d][%d][%d]: %d\n", i, j, k, matrix[i][j][k]);
			}
		}
	}	
	return;
}


// Print 3D matrix
void print3DMatrix(int ***mat, int r, int c, int d){
	printf("\n");
	for (int i=0; i<r;i++){
		for (int j=0; j<c;j++) {
			for (int k=0; k<d; k++) {
				printf("%d ", mat[i][j][k]);
			}
				printf("\n");
		}
		printf("\n\n");
	}
}


// MAIN
int main(int argc, char *argv[]) {
	
	// set row and col sizes
	int r = 3, c = 3;
	
	// create uninitialized A and initialized B matrices
	int **A = mallocMatrix(r, c);
	int **B = callocMatrix(r, c);
	
	// print A (uninitialized matrix)
	printMatrix(A, r, c);
	
	// print B (initialized matrix)
	printf("\n");
	printMatrix(B, r, c);
	
	// fill B and reprint
	printf("\n\n");
	fillMatrix(B, r, c);
	printf("\n");
	printMatrix(B, r, c);
		
	// free memory after use
	for(int i = 0; i < r; i++) 
		free(A[i]);
	free(A);
	for(int i = 0; i < r; i++) 
		free(B[i]);
	free(B);	
	
	
	// create uninitialized 3D matrix
	int n_rows = 3, n_cols = 3, depth = 3;
	int ***matrix = malloc3Dmatrix(n_rows, n_cols, depth);
	
	// fill and print 3D matrix
	fill3DMatrix(matrix, n_rows, n_cols, depth);
	print3DMatrix(matrix, n_rows, n_cols, depth);
	
	// free 3D matrix	
	for (int i = 0; i < n_rows; i++) {
		for (int j = 0; j < n_cols; j++){
			free(matrix[i][j]);
		}
		free(matrix[i]);
	}
	free(matrix);
	
	
	/* StackOverflow recommended best way: */
	int n = 5;
	double (*X)[n] = malloc(sizeof(double[n][n]));
	free(X);
	/* The notation int (*X)[n]; means X is a pointer to an array of n values of type int, 
	or a pointer to the start of an array of arrays of n values of type int. This is a 
	'variably modified type'; you need to be using C99 or C11 for it to be legitimate. 
	The allocation allocates enough space for an array of n x n values of type int. 
	This means that you can use the X[i][j] notation to access elements of the array. 
	The allocation is guaranteed to be contiguous, and there is only one allocation, 
	not many allocations as other techniques for allocating 2D arrays tend to have. */
	
	
	
	/* Quora recommended way: */
	// Single level of indirection for matrix, with a macro to handle the 2D indexing 
	int N = 5, M = 5;
	/* Declaration */
	int *a = malloc ( M * N * sizeof(int) );
	/* Indexing scheme */
	#define A(y,x) a[(y)*N+(x)]
	/* Use */
	A(3,4) = 42; // Presuming M>3 and N>4
	printf("%d\n", A(3,4));
	/* Free */
	free(a);
	
	
	return 0;
}



// valgrind --leak-check=yes ./malloc_calloc_matrices
// definitely lost: 0 bytes






/*
// EDITING a pointer (not changing value it points to) 
// (If you want to modify a pointer to pointer you need to pass a pointer to pointer to pointer.)
// also probably not very useful 
void setMatrix(int ***mat, int r, int c){ 
	printf("Insert the elements of your matrix:\n"); 
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) { 
			printf("Insert element [%d][%d]: ", i, j); 
			scanf("%d", &(*mat)[i][j]);
			printf("matrix[%d][%d]: %d\n", i, j, (*mat)[i][j]); 
		}
	}	 
	return; 
}

main:
setMatrix(&mat, r, c);
*/





