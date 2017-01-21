#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

		// 20 definitely lost (5*4 bytes per int)
		printf("%lu\n", sizeof(int)); // 4 bytes
		printf("%lu\n", 5*sizeof(int)); // 20 bytes (4*5)
		int* A = malloc(5*sizeof(int)); 
		// valgrind --leak-check=yes ./valgrind_mem_debug
		// (notice: definitely lost: 20 bytes in 1 blocks)
		free(A); 
		// valgrind --leak-check=yes ./valgrind_mem_debug  
		// (notice: definitely lost: 0 bytes in 0 blocks)


		// 36 indirectly lost (3*3*4bytes) (and 24 definitely?)
		int **mat = malloc(3*sizeof(int*));
		for(int i = 0; i < 3; i++) mat[i] = malloc(3 * sizeof(int));
		// all freed (4 mallocs = 4 frees)
		for(int i = 0; i < 3; i++) 
			free(mat[i]);
		free(mat);

		
		// 36 definitely lost
		int n = 3;
		// this is still functions as a 2D matrix like the above
		int (*X)[n] = malloc(sizeof(int[n][n])); // variably modified type C99
		free(X); // all freed (one malloc = one free)

		return 0;
}

// http://stackoverflow.com/questions/34573039/possible-memory-leak-valgrind-in-osx-el-capitan
// OS X El Capitan Possibly lost: 2,064 bytes in 1 blocks