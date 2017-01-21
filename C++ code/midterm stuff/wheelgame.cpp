/*
The Wheel Game
--------------
- There are three contestants: A, B, C. A plays first, then B, then C.
- Each contestant's score is determined by the sum of three spins of a wheel.
- Each spin is a number from 5 to 100, intervals of 5, ie. 5, 10, 15, 20, ... , 95, 100
- If a players score is at 100 or more after one or two spins, no more spins can be attempted.
- The winner is the player closest to 100 but not over.
- In the case of a tie, the winner is the first player to achieve the winning score.
The Assignment
--------------
Write a C++ program that plays the wheel game using file I/O.
This program shell contains the basics to get started.
The program reads results from a file "wheelgame.txt" in which each
game is coded in three lines of the form:
Name spin1 spin2 spin3
If no spin is attempted for spin2 or spin3, a 0 is entered in its place.
An example wheelgame_example.txt is included
The result of the program should be the creation of a file "wheelresults.txt"
There will be one output line per game, either with the name and score of the winner,
or the text "Invalid Game"
The only invalid game cases you should deal with are non-zero spins when no spin was allowed.
A corresponding example wheelresults_example.txt is included.
*/

//austinmw
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;


// return a players score in total, or zero if they went over.
// valid should indicate with the spins were valid or not.

// implement the following function exactly if you want partial credit
void score(int *l,bool& valid, int& total)
{
	valid = true;
	for (int i = 0; i < 3; i++)
	{
		total += l[i];
		if (l[i] == 0 && i != 2)
			valid = false;
	}
}

int main()
{
	ifstream infile("wheelgame.txt");
	ofstream outfile;
	string name;
	string txt;
	int l[3];
	bool valid = true;
	int total, wintotal;
	vector<string> outlines;
	string winner;
	bool badgame;

	while(!infile.eof())
	{
		badgame = false;
		winner = "test";
		wintotal = 0;
		for (int i = 0; i < 3; i++)
		{
			infile >> name >> l[0] >> l[1] >> l[2];
			total = 0;
			score(l, valid, total);

			if (valid == true && total <= 100 && total > wintotal)
			{
				winner = name;
				wintotal = total;
			}
			else if (valid == false)
				badgame = true;
		}
		if (badgame == true)
			outlines.push_back("Invalid");
		else
			outlines.push_back(winner + " " + to_string(wintotal));
	}
	outlines.resize(outlines.size()-1);
	outfile.open("wheelresults.txt");
	for (int i = 0; i != outlines.size(); i++)
		outfile << outlines[i] << endl;
	return 0;
}




