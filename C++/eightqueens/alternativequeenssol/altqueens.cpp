#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

int main()
{
int const boardDim = 8;
//Text Processing Specs
int delimiterValue = '/'-'0';
int queenValue = 'Q' - '0';
int endOfBoardValue = ' ' - '0';
bool fullboard = false;
int queenCount = 0;
char inputChar;
//File I/O
ifstream queensSolutionInputFile;
string line;
vector<string> solutionStrings;
ofstream newfile;
bool solutionStatus[] = {0,0,0,0,0};

queensSolutionInputFile.open("attack.fen");
	while (getline(queensSolutionInputFile, line))
		{
		   solutionStrings.push_back(line);
		}
queensSolutionInputFile.close();

for(int y = 0; y<solutionStrings.size(); y++)
	{
		//set-reset board for new solution string
		int board[boardDim][boardDim] = {0};
		fullboard = false;
		queenCount = 0;
		int i=0,j=0,x=0;
				while(!fullboard)
				{//Process solution string to board array
						inputChar = solutionStrings[y][x];
						int inputInt = inputChar - '0';
						if(0<inputChar&&inputInt<9)
							{j=j+inputInt;}
						if(inputInt==queenValue)
							{board[i][j]=1;
							queenCount=queenCount+1;}
						if(inputInt==delimiterValue)
							{i=i+1;
							j=0;}
						if(inputInt==endOfBoardValue)
							{fullboard=true;}
					x++;
				}
	//Check board for valid 8 queen solution.
		bool validSolution = true;
		if (queenCount<8)
			{validSolution = false;}
		//find column and row sums and check for valid solution (sum no greater than 1)
		for(int i = 0; i<boardDim; i++)
			{
			int rowSum = 0;
			int colSum = 0;
			for(int j = 0; j<boardDim; j++)
				{
				rowSum = rowSum + board[i][j];
				colSum = colSum + board[j][i];
				}
			if(rowSum >1||colSum>1)
				{validSolution = false;}
			}

		//find diagonal sums  and check for valid solution (sum no greater than 1)
		for(int i=0; i<boardDim; i++)
			{int diagSumTopToRght = 0, diagSumLftToBttm  = 0, diagSumTopToLft = 0, diagSumRghtToBttm  = 0;
			for(int j=0; (j+i)<boardDim; j++)
				{
				diagSumTopToRght = diagSumTopToRght + board[j][j+i];
				diagSumLftToBttm = diagSumLftToBttm + board[j+i][j];
				diagSumTopToLft = diagSumTopToLft + board[j][boardDim-1-(j+i)];
				diagSumRghtToBttm = diagSumRghtToBttm + board[j+i][boardDim-1-j];
				}
				if(diagSumTopToRght>1||diagSumLftToBttm>1||diagSumTopToLft>1||diagSumRghtToBttm>1)
				{validSolution=false;}

			}
		cout << solutionStrings[y] << endl;
		solutionStatus[y] = validSolution;
	}

	newfile.open("attack.sol");
	for(int i = 0; i<solutionStrings.size(); i++)
	{
		if(solutionStatus[i])
			{newfile << solutionStrings[i] << " 8 queens solution" << endl;}
		if(!solutionStatus[i])
			{newfile << solutionStrings[i] << endl;}
	}
 newfile.close();

	return 0;
}
