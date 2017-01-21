#include <iostream>
/* on my compiler <iostream> includes <string> either directly or indirectly,
but you aren't supposed to count on it so should include <string> anyway. */
#include <string>
#include <fstream>
using namespace std;
	
int main() {
	
	ofstream theFile("players.txt"); // will create if doesn't exist
	
	cout << "Etner player's ID, Name, and Money" << endl;
	cout << "press Ctrl+Z to quit\n" << endl;
	// Ctrl+Z is a control character in ASCII code
	// It is used to signal an end-of-file on some operating systems
	
	int idNumber;
	string name;
	double money;
	
	while(cin >> idNumber >> name >> money){
		theFile << idNumber << ' ' << name << ' ' << money << endl;		
		// can enter multiple lines: e.g.: 1 austin 50.25
	}
	
	
}