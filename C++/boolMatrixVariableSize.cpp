// should change malloc to new or change to C by using int instead of bool and printf instead of cout
#include <iostream>
using namespace std;



bool** create2darr(int rmax, int colmax) { // In C99, you can use variable-length arrays:		
		bool **mat = (bool**)malloc(rmax*sizeof(bool*));
		for(int i = 0; i < rmax; i++) mat[i] = (bool *)malloc(colmax * sizeof(bool));
		return mat;
}



using namespace std;
int main(int argc, char *argv[]) {
	
	// row size, column size
	int r = 3, c = 3;
	
	// create bool matrix
	bool** mymat = create2darr(r, c);
	
	// print false matrix
	for (int i=0;i<3;i++){
		for (int j=0;j<3;j++){
			cout << mymat[i][j];
		}
		cout << endl;
	}
	cout << endl;

	// set entire matrix to true
	for (int i=0;i<3;i++){
		for (int j=0;j<3;j++){
			mymat[i][j] = true;
		}
	}
	
	// print true matrix
	for (int i=0;i<3;i++){
		for (int j=0;j<3;j++){
			cout << mymat[i][j];
		}
		cout << endl;
	}
}