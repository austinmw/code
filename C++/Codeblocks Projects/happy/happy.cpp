// Austin Welch
// happy.cpp


#include <iostream>

using namespace std;

int main()
{

	int i;
	int num;
	int newnum;
	int digit;
	int count = 0;

	for (i=1; i<=100000; i++)
	{
		num = i;
		if (num != 1)
		{
			while (num != 1 && num != 4)
			{
				newnum = 0;
				while (num > 0)
				{
					digit = num % 10;
					newnum = newnum + digit * digit;
					num = num / 10;
				}
				num = newnum;
			}
			if (newnum == 1)
			{
				count = count + 1;
				cout << i << ' ';
			}
		}
		else
		{
			count = count + 1;
			cout << 1 << ' ';
		}
		if (count == 10)
		{
			cout << endl;
			count = 0;
		}
	}
	return 0;
}




