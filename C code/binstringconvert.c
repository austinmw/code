# include <stdio.h>
# include <stdlib.h>
# include <string.h>

enum { DWRD = 32 };

void binstringconvert (unsigned *decimals, char (*binarystrings)[DWRD+1], int n);

int main (void)
{
	/* initialize variables */
	unsigned int decimals[] = { 1, 255, 65535, 8388607,
								3241580200, 2898560974,
								4294967295, 3097295382,
								1076482445, 1234567890,
								3241580200,
								3270055958,
								1206215586,
								2720116784,
								3423335924,
								1851806274,
								204254658,
								2047265792,
								19088743,
								19088743
 };
	char (*binarystrings)[DWRD+1] = {NULL};
	int j, n = sizeof decimals/sizeof *decimals;

	binarystrings = calloc (n, sizeof *binarystrings);
	binstringconvert (decimals, binarystrings, n);

	/* test print */
	for (j = 0; j < n; j++)
		printf (" %10u : %s\n", decimals[j], binarystrings[j]);

	free (binarystrings);

	return 0;
}

void binstringconvert (unsigned *decimals, char (*binarystrings)[DWRD+1], int n)
{
	int c, i, k;
	for (i = 0; i < n; i++) {
		for (c = 31; c >= 0; c--)
		{
			k = decimals[i] >> c;
			if (k & 1)
				binarystrings[i][31-c] = '1';
			else
				binarystrings[i][31-c] = '0';
		}
		binarystrings[i][DWRD] = 0;  /* nul-terminate */
	}
}
/*

You need to allocate space for the array of pointers to strings as well as the strings themselves. The first call to calloc() allocates the array of pointers to strings and each malloc() allocates the strings themselves:
	Also, you didn't write a null terminator to the end of the strings. When you try to write it (printf("\n%s", binarystrings[0]);) it will keep reading through memory, past where you want the end to be. Writing a zero ('\0') at the end requires one additional character in the allocation, hence the +1 in the malloc() calls.

	Notice the use of the sizeof() operator. You should never hard code memory sizes. In C, let the compiler figure out how big things are, don't try to guess. A pointer could be 4 bytes on a 32-bit system, and 8 bytes on a 64-bit system. Even if you know what system you have and how big it will be, use sizeof().
	
	*/