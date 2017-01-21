#include <iostream>
#include <sstream>
#include <iomanip>

using namespace std;

void remove_carriage_return(string &line)
{
	if (*line.rbegin() == '\r')
	{
		line.erase(line.length() - 1);
	}
}

void find_line_lengths(istream &inputFile,ostream &output)
{
	string currentLine;
	while (getline(inputFile, currentLine))
	{
		remove_carriage_return(currentLine);
		output
			<< "The current line is "
			<< currentLine.length()
			<< " characters long and ends with '0x"
			<< setw(2) << setfill('0') << hex
			<< static_cast<int>(*currentLine.rbegin())
			<< "'"
			<< endl;
	}
}

int main()
{
	istringstream test_data(
		"\n"
		"1\n"
		"12\n"
		"123\n"
		"\r\n"
		"1\r\n"
		"12\r\n"
		"123\r\n"
		);

	find_line_lengths(test_data, cout);
}