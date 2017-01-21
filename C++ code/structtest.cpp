#include <iostream>

using namespace std;
int main(int argc, char *argv[]) {
	

	struct something {
		unsigned int field:7;
		//unsigned char padding:1;
	};
	struct something value;
	value.field = -128;


cout << value.field << endl;

}