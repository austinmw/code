#include <iostream>

using namespace std;

int perfect (int in)
{
	int r;
	int sum = 0;
	int i;
	for (i=1; i<in; i++)
	{
		if (in % i == 0)
		{
			sum = sum + i;
		}
	}
	if (sum == in)
	{
		return 1;
	}
	else
		return 0;
}

int main()
{
	int x = 1;
	int out;

	while (x != 0)
	{
		cout << "Enter a number to test for perfectness: ";
		cin >> x;
		if (x != 0)
		{
			out = perfect (x);

			if (out == 1)
			{
				cout << x << " is perfect" << endl;
			}
			else
			{
				cout << x << " is not perfect" << endl;
			}
		}
	}
	return 0;
}

