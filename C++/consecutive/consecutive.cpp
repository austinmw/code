#include <iostream>
#include <cstdlib>

using namespace std;

int main(int argc, char const *argv[])
{
	if (argc == 2)
	{
		int length = atoi(argv[1]);
		int count, x, i, temp = 0;
		if (length > 1)
		{
			while (!cin.eof() && count != length)
			{
				cin >> x;
				if (x == temp+1)
				{
					count++;
				}
				else
					count = 1;
				temp = x;
			}

			if (count == length)
			{
				cout << "Sequence found: ";

				for (i = x - length + 1; i <= x; i++)
				{

					cout << i << " ";
				}
			}
			cout << endl;
		}
	}
	return 0;

}
