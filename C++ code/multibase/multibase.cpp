// austinmw

#include <iostream>
using namespace std;

int arraysize (int in, int base)
{
	int count = 0;
	while (in != 0)
	{
		in = in / base;
		count++;
	}
	return count;
}

bool convertandcheck (int in, int base, int size)
{
	int remainder = 0;
	int arrayindex = 0;
	int convertednum[size];
	int i = 0;
	int low = 0;
	int high = size - 1;
	bool isPalindrome = true;

	while (in > 0)
	{
		for (arrayindex = size - 1; arrayindex >= 0; arrayindex--)
		{
			remainder = in % base;
			convertednum[arrayindex] = remainder;
			in = in / base;
		}
	}
	while (low < high)
	{
		if 	(convertednum[low] != convertednum[high])
		{
			isPalindrome = false;
			break;
		}
		low++;
		high--;
	}
	return isPalindrome;
}

int main()
{
	int in = 0;
	int base = 0;
	int size = 0;
	bool isPalindrome;

	cout << "Enter a number to test for palindromicity: ";
	cin >> in;
	for (base = 2; base < in; base++)
	{
		size = arraysize(in, base);
		isPalindrome = convertandcheck(in, base, size);
		if (isPalindrome == true)
		{
			cout << base << endl;
		}
	}
	return 0;
}







