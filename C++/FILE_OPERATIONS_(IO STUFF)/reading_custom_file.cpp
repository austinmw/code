#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// assumes players.txt written to with writing_custom_file.cpp

int main() {
	
	// ifstream is derived from the istream class and can be used
	// to handle input from files.
	// istream serves as a parent for the istringstream and iostream classes as well.
	
	// An istream treats "white space" as delimiters
	ifstream theFile("players.txt");
	int id;
	string name;
	double money;
	while(theFile >> id >> name >> money){
		cout << id << ' ' << name << ' ' << money << endl;
	}
	theFile.close();
	
	
	// fstream also has getline() which is inherited from istream
	// std::getline (string)   (other is std::istream::getline, for c-strings)
	// getline (istream& is, string& str, char delim);
	ifstream myFile("players.txt");
	string buffer;
	while(getline(myFile, buffer, '\n')) {
		cout << buffer << endl;
	}
	myFile.close();
	
}

// TWO DIFFERENT GETLINE()s
// std::getline()   c++ string       e.g. getline(cin ...)
// std::istream::getline() c string   e.g. cin.getline




