#include <stdio.h>
#include <time.h>

void sec_wait ( int sec ) {
	clock_t wait_till_end;
	wait_till_end = clock () + sec * CLOCKS_PER_SEC ;
	while (clock() < wait_till_end) {}
}

int main () {
	int i;
	printf ("Starting countdown...\n");
	for (i=10; i>0; i--) {
		 printf ("%d\n",i);
		 sec_wait (1);
		 if ( i == 3 )
			printf ("Engine started...\n");
	}
       printf ("and lift off....\n");
       return 0;
      }