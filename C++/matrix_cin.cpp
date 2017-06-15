/* Dynamic allocation of array of arrays input when number of lines also given
You are given NN integer sequences and QQ queries. Each query is in the following format: 
	"aa bb" where aa denotes the index of the sequence, and bb denotes the index of the element 
	in that sequence. Your task is to find the value of the element described in each query.

Input Format 
The first line consists of NN and QQ separated by a space.
The following NN lines contain sequences in this format: "kk s0s0 s1s1 s2s2...... sk−1sk−1"
The following QQ lines contain queries in this format: "aa bb". 

Sample input:
	
2       
3 1 5 4 
5 1 2 8 9 3 
*/




#include <iostream>

using namespace std;
int main(int argc, char *argv[]) {
	
	// Read in variable size matrix (each line is variable size also)
	int n; // n lines, q queries (top line of matrix)
	cin>>n; // read in first line, number of lines in matrix
	int **mat =new int *[n];  // create pointer of pointer of size n
	for (int i = 0; i < n; i++) {  // looping through n lines to fill matrix
		int sz;  // first int of each line is line size
		cin>>sz; // read in line size
		int *line = new int [sz];  // create line of size sz
		for (int j = 0; j < sz; j++) {  // loop through individual ints in line
			int x; // declare individual int
			cin>>x; // read in individual int
			line[j] = x; // fill line with each x
		}
		*(mat+i)=line; // fill lines of matrix
	}
	/* Matrix is now complete */




	// Free matrix memory
	for (int k = 0; k < n; k++) {
		delete[] mat[k]; // free each line
	}
	delete[] mat; // free pointer to pointers


	return 0; 
}

/*
using namespace std;
int main() {
// Read in array of arrays
int n, q; // n lines, q queries (top line of matrix)
cin>>n>>q; // read in first line
int **mat =new int *[n];  // create pointer of pointer of size n
for (int i = 0; i < n; i++) {  // looping through n lines to fill matrix
	int sz;  // first int of each line is line size
	cin>>sz; // read in line size
	int *line = new int [sz];  // create line of size sz
	for (int j = 0; j < sz; j++) {  // loop through individual ints in line
		int x; // declare individual int
		cin>>x; // read in individual int
		line[j] = x; // fill line with each x
	}
	*(mat+i)=line; // fill lines of matrix
}

// Print out queries
for (int i = 0; i < q; i++) {
	int a, b;
	cin>>a>>b;
	cout << mat[a][b] << endl;
}

// Free matrix memory
for (int k = 0; k < n; k++) {
	delete[] mat[k]; // free each line
}
delete[] mat; // free pointer to pointers

	return 0; 
}
*/


