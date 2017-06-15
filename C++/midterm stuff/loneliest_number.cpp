// austinmw
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <algorithm>

using namespace std;

const int SIZE=1000000;

// Add a function if you want (optional)

int main()
{

	int v[SIZE];
	ifstream millints("million_ints.txt");
	for (int i=0;i<SIZE;i++)
	{
		millints >> v[i];
		if (millints.fail())
		{
			cout << "data file not found. reread instructions." << endl;
			return 1;
		} 
	}	

	int distance = 0;
	int temp = 0;
	int lonelynum = 0;	
	
	sort(begin(v), end(v));
	for (int i = 0; i < SIZE - 1; i++)
	{
		temp = abs(v[i] - v[i+1]);
		if (temp > distance)
		{
			distance = temp;
			lonelynum = v[i];
		}			
	}
	cout << lonelynum << endl;
	return 0;
}