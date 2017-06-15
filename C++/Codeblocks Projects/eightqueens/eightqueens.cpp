// austinmw

#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

int main()
{
ifstream attackfen;
string txtline;
ofstream attacksol;

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

if (queenscount == 8)
{// Check rows, columns, and diagonals
	int rowMask = 0;
	int columnMask = 0;
	int diagonalMask0 = 0;
	int diagonalMask1 = 0;
	for(i = 0; i < 8; i++)
	{
		for(j = 0; j < 8; j++)
		{
			if(board[i][j])
			{
				// test row:
				if(rowMask & (1 << i))
					validqueens = false;
				rowMask |= 1 << i; // mark row set

				// test column:
				if(columnMask & (1 << j))
					validqueens = false;
				columnMask |= 1 << j; // mark column set

				// test first diagonal:
				if(diagonalMask0 & (1 << (i + j)))
					validqueens = false;
				diagonalMask0 |= 1 << (i + j); // mark diagonal set

				// test first diagonal:
				if(diagonalMask1 & (1 << (8 + i - j)))
					validqueens = false;
				diagonalMask1 |= 1 << (8 + i - j); // mark diagonal set
			}
		}
	}
}
else
	validqueens = false;

if (validqueens == true)
{// Append txtline with solution text
	attacksol << txtline << " 8 queens solution" << endl;
}
else
{// Only append txtline
attacksol << txtline << endl;
}
}

attackfen.close();
attacksol.close();
return 0;
}
