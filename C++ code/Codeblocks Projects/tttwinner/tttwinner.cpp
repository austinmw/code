// austinmw
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

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

vector<vector<vector<char> > > makeBoard(vector<string> iflines)
{// Function to fill game boards from input strings
	vector<vector<vector<char> > > tttboard;
	for (int i = 0; i != iflines.size(); i++)
	{
		vector<vector<char> > line(3, vector<char>(3));
		for (int j = 0; j < 9; j++)                     // ++j?
		{
			line[j / 3][j % 3] = iflines[i][j];
		}
		tttboard.push_back(line);
	}
	return tttboard;
}

vector<vector<vector<int > > > boardToLines(
 vector<vector<vector<char> > > tttBoard)
{/* Creates 3x9 vectors with row[0] = x's, row[1] = o's, row[2] = #'s,
 Counts board left to right and down, using 1's to populate x's, o's, and #'s
 Probably should've went straight to this instead of forming boards first */
	vector<vector<vector<int> > > tttPositions;
	tttPositions.resize(tttBoard.size(),
						vector<vector<int > >(3, vector<int>(9,0)));
	for (int i = 0; i != tttBoard.size(); i++)
	{
		for (int j = 0; j < 3; j++)
		{
			for (int k = 0; k < 3; k++)
			{
				if (tttBoard[i][j][k] == 'x')
					tttPositions[i][0][j*3+k] = 1;
				if (tttBoard[i][j][k] == 'o')
					tttPositions[i][1][j*3+k] = 1;
				if (tttBoard[i][j][k] == '#')
					tttPositions[i][2][j*3+k] = 1;
			}
		}
	}
	return tttPositions;
}

vector<char> analyzeBoard(vector<vector<vector<int> > > tttPositions)
{// Analyze boards, return vector of evaluation chars
	vector<char> tttStatus(tttPositions.size(), '-');
	for (int i = 0; i != tttPositions.size(); i++)
	{
		int xcount(0), ocount(0), emptycount(0);
		bool xwon = false;
		bool owon = false;
		for (int j = 0; j < 3; j++)
		{// Checks for x and o wins
			bool winCombos =
				((tttPositions[i][j][0] && tttPositions[i][j][1]
				  && tttPositions[i][j][2])
				 || (tttPositions[i][j][3] && tttPositions[i][j][4]
					 && tttPositions[i][j][5])
				 || (tttPositions[i][j][6] && tttPositions[i][j][7]
					 && tttPositions[i][j][8])
				 || (tttPositions[i][j][0] && tttPositions[i][j][3]
					 && tttPositions[i][j][6])
				 || (tttPositions[i][j][1] && tttPositions[i][j][4]
					 && tttPositions[i][j][7])
				 || (tttPositions[i][j][2] && tttPositions[i][j][5]
					 && tttPositions[i][j][8])
				 || (tttPositions[i][j][0] && tttPositions[i][j][4]
					 && tttPositions[i][j][8])
				 || (tttPositions[i][j][2] && tttPositions[i][j][4]
					 && tttPositions[i][j][6]));
			if (winCombos == true)
			{
				if (j == 0)
					xwon = true;
				if (j == 1)
					owon = true;
			}
			for (int k = 0; k < 9; k++)
			{// Counts x's, o's, and #'s
				if (j == 0 && tttPositions[i][j][k] == 1)
					xcount++;
				if (j == 1 && tttPositions[i][j][k] == 1)
					ocount++;
				if (j == 2 && tttPositions[i][j][k] == 1)
					emptycount++;
			}
		}
		// Checks for wins, invalids, ties, and continues
		if (xcount != ocount+1 && xcount != ocount) // Unbalanced numbers
			tttStatus[i] = 'i';
		else if ((xwon == true) && (owon == true)) // Both won
			tttStatus[i] = 'i';
		else if (xwon == true && xcount == ocount) // Continued after x won
			tttStatus[i] = 'i';
		else if (owon == true && xcount != ocount) // Continued after o won
			tttStatus[i] = 'i';
		else if (xwon == true) // x won
			tttStatus[i] = 'x';
		else if (owon == true) // o won
			tttStatus[i] = 'o';
		else if (emptycount == 0) // Filled board, neither won
			tttStatus[i] = 't';
		else if (emptycount != 0) // Neither won, position(s) still empty
			tttStatus[i] = 'c';
	}
	return tttStatus;
}

void writeFiledata(vector<string> iflines, vector<char> tttStatus)
{// Put together status and iflines into ofstream
	ofstream tttoutput;
	tttoutput.open("tttstatus.txt");
	for (int i = 0; i != iflines.size(); i++)
		tttoutput << iflines[i] << " " << tttStatus[i] << "\n";
	tttoutput.close();
}

int main()
{
	vector<string> iflines;
	vector<vector<vector<char> > > tttBoard;
	vector<vector<vector<int> > > tttPositions;
	vector<char> tttStatus;

	iflines = getFileData();
	tttBoard = makeBoard(iflines);
	tttPositions = boardToLines(tttBoard);
	tttStatus = analyzeBoard(tttPositions);
	writeFiledata(iflines, tttStatus);
	return 0;
}
