#include <iostream>
#include <fstream>
using namespace std;

int main() {
	
	// create and open file object
	ofstream myFile;
	myFile.open("bacon.txt");
	
	// write to file and close
	myFile << "I love bacon!\n";
	myFile.close();
	
	// ---------- Another example ---------- //
	
	// create and open on one line
	ofstream buckysFile("beefjerky.txt");
	// test if open
	if (buckysFile.is_open()) {
		cout << "the file is open" << endl;
	}
	else {
		cout << "the file is not open" << endl;
 	}
	
	// write to file and close
	buckysFile << "i love beef jerky!\n";
	buckysFile.close();
	
	
	
}