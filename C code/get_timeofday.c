#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <unistd.h>
int main()
{
	 struct timeval st , et;
	 gettimeofday(&st , NULL);
	 sleep(2);
	 gettimeofday(&et , NULL);
	 printf("\nTotal time taken is : %lu seconds and %d microseconds\n",(et.tv_sec - st.tv_sec),(et.tv_usec - st.tv_usec));
	 return 0;
}