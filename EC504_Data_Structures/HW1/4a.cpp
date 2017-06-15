// AUTHOR1: Austin Welch austinmw@bu.edu
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int binary_sum(string inputfile)
{
	int sum=0;
	string line="";
	ifstream fin;
	fin.open(inputfile.c_str());
	while(!fin.eof())
	{
		getline(fin,line);
		const char *num=line.c_str();
		char *end;
		int dnum=strtol(num,&end,2);
		sum+=dnum;
	}
	fin.close();

	return sum;
}


int main(int argc, char *argv[]) {
	
	string inputfile(argv[1]);
	long in= binary_sum(inputfile); 
	cout<<in<<endl;
	return 0;
}

