#include <iostream>
#include <sstream>
#include <string>

using namespace std;
int main() {
	
	int num;
	int base;
	string snum;
	int remainder;

	
	cout << "input num to convert: ";
	cin >> num;
	cout << "input base to convert to: ";
	cin >> base;

while (num != 0) {
	
	remainder = num % base;
	num = num / base;
	
	std::string letter = std::to_string(remainder);
	snum = snum + letter;

}

int value = atoi(snum.c_str());
cout << value << endl;

return 0;
	
}