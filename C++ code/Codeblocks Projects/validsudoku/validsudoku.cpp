#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

int main(int argc, char const *argv[])
{
string filetoopen;
ifstream sudokutxtfile;
string txtline;
string sudokubox[9];
bool goodsudoku = true;
int i(0), j(0), row(0), column(0);

// Terminal input or default
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
// Valid solution check
for (i = 0; i < 9; i++)
{
	for (j = 0; j < 9; j++)
	{
		// check whether sudokubox[i][j] is valid at the i's row
		for (column = 0; column < 9; column++)
			if (column != j && sudokubox[i][column] == sudokubox[i][j])
				goodsudoku = false;

		// check whether sudokubox[i][j] is valid at the j's column
		for (row = 0; row < 9; row++)
			if (row != i && sudokubox[row][j] == sudokubox[i][j])
				goodsudoku = false;

		// check whether sudokubox[i][j] is valid in the 3-by-3 box
		for (row = (i / 3) * 3; row < (i / 3) * 3 + 3; row++)
			for (column = (j / 3) * 3; column < (j / 3) * 3 + 3; column++)
				if (row != i && column != j && sudokubox[row][column] == sudokubox[i][j])
					goodsudoku = false;
	}
}
// Output
if (goodsudoku == true)
	cout << "valid" << endl;
else
	cout << "invalid" << endl;
return 0;
}


