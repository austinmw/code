#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main()
{
ifstream infile("foodsum_files.txt");
string txtline;
vector<string> filenames;
vector<string> output;

while (getline(infile,txtline))
	filenames.push_back(txtline);
infile.close();

for (int i = 0; i != filenames.size(); i++)
{
	ifstream foodfile(filenames[i]);
	vector<int> numbers;
	int temp = 0;
	int val = 0;
	bool goodfile = true;
	string notint = "test";


	while(foodfile >> temp)
	{
		numbers.push_back(temp);
	}

	for (int i = 0; i != numbers.size(); i++)
		val+= numbers[i];


	//if (goodfile == false)
	//	output.push_back("bad number");
	//else
	if (val > 0)
		output.push_back(filenames[i] + " " + to_string(val));
	else if (val == 0)
		output.push_back("not found");


}
for (int i = 0; i != output.size(); i++)
cout << output[i] << endl;


	return 0;
}
