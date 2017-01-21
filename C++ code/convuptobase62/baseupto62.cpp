#include <iostream>
#include <sstream>
#include <string>

using namespace std;

string convertbase (int num, int base)
{
	string snum;
	int remainder;
	string letter;

	while (num != 0)
	{
		remainder = num % base;
		num = num / base;

		if (remainder < 10)
		{
			letter = std::to_string(remainder);
			snum = snum + letter;
		}
		if (remainder >= 10 && remainder < 36)
		{
			remainder = remainder + 55;
			letter = char(remainder);
			snum = snum + letter;
		}
		if (remainder >= 36 && remainder < 62)
		{
			remainder = remainder + 61;
			letter = char(remainder);
			snum = snum + letter;
		}
		
	}
	snum = string(snum.rbegin(), snum.rend());
	return snum;
//	int value = atoi(snum.c_str());
//	return value;  [probably wont use this, but leaving for now]
}

int main()
{
	int in = 0;
	int base = 0;
	int size;
	string convertednum;

	cout << "Enter a number: ";
	cin >> in;
	cout << "Enter a base: ";
	cin >> base;


	convertednum = convertbase (in, base);
		cout << convertednum << endl;
	
	return 0;
}