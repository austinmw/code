#include <stdio.h>
 
int main () {

	/* local variable definition */
	int a = 10;

	/* do loop execution */
	do {
	
		if( a == 15) {
			/* skip the iteration */
			a++;
			continue;
		}
		
		printf("value of a: %d\n", a);
		a++;
	  
	} while( a < 20 );
 
	return 0;
}

/* The continue statement in C programming works somewhat like the break statement. Instead of forcing termination, it forces the next iteration of the loop to take place, skipping any code in between. */