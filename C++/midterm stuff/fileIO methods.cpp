// FILE-IO METHODS
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

//---------------------------------------------------------------//

//Good ifstream function
vector<string> getFileData()
{// Open file, read in, close, return string vector to main
	ifstream tttboards;
	string line;
	vector<string> iflines;
	tttboards.open("tictactoeboards.txt");
	while (getline(tttboards, line))
		iflines.push_back(line);
	tttboards.close();
	return iflines;
}
int main() {
	vector<string> iflines;
	iflines = getFileData();
}

//---------------------------------------------------------------//

//With added remove carriage return
void remove_carriage_return(string &line)
{// Removes the \r's
	if (*line.rbegin() == '\r')
	{
		line.erase(line.length() - 1);
	}
}
vector<string> getFileData(string wordsfilename)
{// Open file, read in, close, return string vector to main
	ifstream dictionaryfile;
	string txtline;
	vector<string> iflines;
	dictionaryfile.open(wordsfilename);
	while (getline(dictionaryfile, txtline))
	{
		remove_carriage_return(txtline);
		iflines.push_back(txtline);
	}
	dictionaryfile.close();
	return iflines;	
}	
vector<string> words;
words = getFileData(wordlist);

//---------------------------------------------------------------//

// Inputs integers and alerts if non-integer value is detected
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
int n;
bool datacheck = true;
ifstream filein("gdata.txt");
	
while (filein >> ws && !filein.eof()) //order is important
{
	if (!(filein >> n)) // or cin >> n; if (filein.fail()) {}
	{
		cout << "\nerror in input\n";
		datacheck = false;
		break;
	}
	cout << n << " ";   
}	
cout << "\nGood file: " << boolalpha << datacheck << endl;
}

//---------------------------------------------------------------//

//First book example
#include <iostream>
#include <string>
ifstream input("file.txt");
string firstName;
char mi;
string lastName;
int score;
input >> firstName >> mi >> lastName >> score;
input.close();

//---------------------------------------------------------------//

//Testing File Existence
input.open("file.txt");
if (input.fail())
{
	cout << "File does not exist" << endl;
	return 0;
}	

//---------------------------------------------------------------//

//Testing End of File
ifstream input("file.txt");
while (!input.eof())
{
	input >> number;
	if (input.eof()) break; // Prevents adding last number twice
	sum += number;	
}	

//---------------------------------------------------------------//

//Testing End of File, option 2
while (input >> number) //terminates if NULL (0) is returned
	sum += number;

//---------------------------------------------------------------//
	
//another
std::string s;
std::vector<int> a(3);    // or int a[3];
std::cin >> s >> a[0] >> a[1] >> a[2];
while (infile >> s >> a[0] >> a[1] >> a[2]) 
{	...	
}

//---------------------------------------------------------------//

//from wheel game
while(!infile.eof())
{
	for (int i = 0; i < 3; i++)
	{
		infile >> name >> l[0] >> l[1] >> l[2];

//---------------------------------------------------------------//				
	
//User-entered file name
string filename;
cin >> filename;
ifstream input(filename.c_str());

//---------------------------------------------------------------//

//getline
while (!input.eof())
{
	getline(input, variable, delimiter)
	cout << variable << endl;
}

//---------------------------------------------------------------//
	
//Read by character
char ch = input.get();
while (!input.eof)
	ch = input.get();

//---------------------------------------------------------------//
	
//Appending to a file
inout.open("file.txt", ios::out); // creates file
inout << "blah"; // write to file
inout.close();
inout.open("file.txt", ios::out | ios::app) // opens output for append

//---------------------------------------------------------------//

//Testing Stream States
void showState(fstream &stream)
{
	cout << "Stream status: " << endl;
	cout << "  eof(): " << stream.eof() << endl;
	cout << "  fail(): " << stream.fail() << endl;
	cout << "  bad(): " << stream.bad() << endl;
	cout << "  good(): " << stream.good() << endl;
}
int main()
{
	fstream infile;
	infile.open("file.txt", ios::in)
	string whatev;
	infile >> whatev;
	showState(infile);
	infile.close();
	showState(infile);		
}	

//---------------------------------------------------------------//

//better queens ifstream using vectors
ifstream queensSolutionInputFile;
string line;
vector<string> solutionStrings;
queensSolutionInputFile.open("attack.fen");
while (getline(queensSolutionInputFile, line))
	{
	   solutionStrings.push_back(line);
	}
queensSolutionInputFile.close();

//---------------------------------------------------------------//

//Kind of sloppy ifstream from eightqueens
// Open attack.fen, clear old and open new attack.sol
attackfen.open("attack.fen");
remove("attack.sol");
attacksol.open("attack.sol", ios::app);
while (getline(attackfen, txtline)) 
{// Main while loop: reads, evaluates, and writes
int board[8][8]	= {0};
int i(0), j(0), count(0), queenscount(0);
bool validqueens = true; 
// Set up board filling in queens
while (txtline[i] != ' ') {
	if (isdigit(txtline[i]) == true){
		int n = txtline[i] - '0';
		count = count + n;}
	else if (txtline[i] == 'Q'){
		board[j][count] = 1;
		queenscount++;}
	else if (txtline[i] == '/'){
		j++;
		count = 0;}
	i++; }

//---------------------------------------------------------------//

//Terminal input or default
string filetoopen;
ifstream sudokutxtfile;
string txtline;
string sudokubox[9];
if (argc == 2)
	filetoopen = argv[1];
else
	filetoopen = "sudokuboard.txt";
// Read in file, save to array, close file
sudokutxtfile.open(filetoopen);
while (getline(sudokutxtfile,txtline))
{
	sudokubox[row] = txtline;
	row++;
}
sudokutxtfile.close();

//---------------------------------------------------------------//

// IO stuff from file_adder
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

//---------------------------------------------------------------//

// IO stuff from least_common
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

//---------------------------------------------------------------//

// IO stuff from lonelist_number (given)
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

//---------------------------------------------------------------//




	
	

