// austinmw
#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;

const int SIZE=1000000;

vector<unsigned int> get_least_common_vector(
	unsigned int const * const v,int const vsize)
{

	vector<unsigned int> l;
	vector<unsigned int> vvec;
	for (int i = 0; i < vsize; i++)
		vvec.push_back(v[i]);
	sort(vvec.begin(), vvec.end());

	int temp = 100;
	int count = 0;
	int num = 0;
	int count2 = 0;

	for (int i = 0; i < vvec.size() -1; i++)
	{
		if (vvec[i] == vvec[i+1])
			count++;
		else
		{
			if (count < temp)
			{
				temp = count;
			}
			count = 0;
		}
	}
	for (int i = 0; i < vvec.size() -1; i++)
	{
		if (vvec[i+1] == vvec[i])
			count2++;
		else
		{
			if (count2 == temp)
				l.push_back(vvec[i-1]);
			count2 = 0;
		}
	}
	return l;
}

int main()
{

	unsigned int v[SIZE];
	ifstream millints("million_common.txt");
	for (int i=0; i<SIZE; i++)
	{
		millints >> v[i];
		if (millints.fail())
		{
			cout << "data file not found. reread instructions." << endl;
			return 1;
		}
	}

	vector<unsigned int> least_commons_v;
	least_commons_v =get_least_common_vector(v,SIZE);

	for (auto l: least_commons_v)
	{
		cout << l << endl;
	}

	return 0;
}
