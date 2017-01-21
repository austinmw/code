#include <iostream>

using namespace std;
int main(int argc, char *argv[]) {
	
	
	uint16_t val = 0x400;
	uint8_t* ptr = (uint8_t*)&val;
	
	if (ptr[0] == 0x04) {
		printf("big endian\n");
	}
	else if (ptr[1] == 0x04) {
		printf("little endian\n");
	}
	
	else {
		printf("unknown endianness!\n");
	}
}