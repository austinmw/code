void printInput(vector<string> iflines) 
{// Prints vector string from getFileData function
cout << iflines.size() << endl << endl; // vector size
for (auto i: iflines) // checks iflines vector by printing lines
	cout << i << endl;
cout << endl; 
}

void printBoard(vector<vector< vector<char> > > tttboard) 
{// Prints board made from makeBoard function
for (auto i: tttboard) {
	for (auto j : i) 
	{
		for (auto k : j)
			cout << k << " ";	
		cout << endl;	
	}	
	cout << endl;}
}

void printLines(vector<vector<vector<int> > > tttPositions)
{
for (int i = 0; i != tttPositions.size(); i++)
{
	for (int j = 0; j < 2; j++)
	{
		for (int k = 0; k < 9; k++)	
			cout << tttPositions[i][j][k];
		cout << endl;
	}
	cout << endl;}
}	

void printEvals(vector<char> tttStatus)
{
for (int i = 0; i != tttStatus.size(); i++)
	cout << tttStatus[i] << endl;
}


for (int i = 0; i != tttBoard.size(); i++){	
	int xcount = 0;
	int ocount = 0;
	for (int j = 0; j < 3; j++)
	{
		for (int k = 0; k < 3; k++)
		{
			if (tttBoard[i][j][k] == 'x')
				xcount++;
			if (tttBoard[i][j][k] == 'o')
				ocount++;			
		}
	}
	if (xcount != ocount+1 && xcount != ocount) // Unbalanced numbers
		tttStatus[i] = 'i';}


for (int i = 0; i != tttStatus.size(); i++)
cout << tttStatus[i] << endl;


for (int i = 0; i != tttboard.size(); i++)
	tttstatus[i] = 'A';


for (auto i: tttboard) 
{
	xcount = 0;
	ocount = 0;
	
	for (auto j : i) 
	{
		for (auto k : j)
		{
			if (k == 'x')
				xcount++;
			else if (k == 'o')
				ocount++;
		}				
	}	
	if (xcount+1 != ocount && xcount != ocount) // Unbalanced numbers
		tttstatus[i] = 'i';
		cout << ncount << endl;
		ncount++;		

	//else if()

	
// To fill a single 3x3 box with zeros
vector< vector<int> > tttboard;  
	for (int i = 0; i < 3; i++) {
		vector<int> row; // Create an empty row
		for (int j = 0; j < 3; j++) 
			row.push_back(0); // Add an element (column) to the row	
		tttboard.push_back(row);} // Add the row to the main vector	
		
// Another way to do it
	for (int i = 0; i < 3; i++) 
		tttboard.push_back(vector<int>()); // Add an empty row	
	for (int j = 0; j < 3; j++) 
		for (int i = 0; i < tttboard.size(); i++) 
			tttboard[i].push_back(0); // Add column to all rows	 						
		return tttboard;	




Longer way: 
for (int i = 0; i < tttboard.size(); i++ )
{
	for (int j = 0; j < tttboard[i].size(); j++ )
		cout << tttboard[i][j] << ' ';
	cout << endl;
}	

