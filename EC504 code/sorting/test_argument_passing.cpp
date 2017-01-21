#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	for (int i; i<argc; i++){
		cout << argv[i];
	}
	return 0;
}