#include <stdio.h>
#define LINESIZE 128

// simple txt file read in
// no error checking, needs argv[1]
int main(int argc, char *argv[]) {
	
	FILE *fp = fopen(argv[1], "r");
	char line[LINESIZE];
	
	
	while(fgets(line, sizeof(line), fp))
	{
		printf("%s", line);
	}
	
	
	
}