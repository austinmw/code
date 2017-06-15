#include <iostream>
//int y = 2147483647;
using namespace std;

int main()

{
	int x = 1;
	while (x > 0)
	{
		x = x+100000;
	}
	x = x - 100000;

	while (x > 0)
	{
		x = x + 1000;
	}
	x = x - 1000;

	while (x > 0)
	{
		x = x + 10;
	}
	x = x - 10;

	while (x > 0)
	{
		x = x + 1;
	}
	x = x - 1;
	cout << "max int value is " << x << endl;
}

