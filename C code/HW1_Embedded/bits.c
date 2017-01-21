#include <stdio.h>
#include "bits.h"

enum { DWRD = 32 };

unsigned int BinaryMirror(unsigned int decimal) {

	char binstring[33];
	unsigned int mirrordecimal = 0;
	int i, j, z;
	
	// decimal to binary string
	for (i = 31; i >= 0; i--) {
		j = decimal >> i;
		if (j & 1)
			binstring[31-i] = '1';
		else 
			binstring[31-i] = '0';
	}
	binstring[DWRD] = 0; // null-terminate

	// binary string to decimal mirror value
	for (z = 0; z <= 31; z++) {
		if (binstring[z] == '1') {
			mirrordecimal += 1UL << (z);
		}					
	}
	
	return mirrordecimal;
} 

unsigned int SequenceCount(unsigned int decimal) {
	
	unsigned int tencount = 0;
	char binstring[33];
	int i, j, x;
	
	// decimal to binary string
	for (i = 31; i >= 0; i--) {
		j = decimal >> i;
		if (j & 1)
			binstring[31-i] = '1';
		else 
			binstring[31-i] = '0';
	}
	binstring[DWRD] = 0; // null-terminate
	
	// calculate number of 10's in binary number	
	for (x = 0; x <= DWRD - 2; x++) {	
		if ((binstring[x] == '1') && (binstring[x+1] == '0'))
			tencount++;			
	}			
	
	return tencount;
}

