// austinmw

#include <iostream>
using namespace std;

bool inputCheck (int num, int sequence)     // checks for proper input
{
	bool goodInput = true;
	int tempSequence = sequence;
	int rem = 0;

	if (num < 0)
			cout << "Number must be positive." << endl;
	if (sequence < 0)
			cout << "Sequence must be positive" << endl;
	if (sequence > 0)
	{
		tempSequence = sequence;
		while (tempSequence >= 1)
		{
			rem = tempSequence % 10;
			tempSequence = tempSequence / 10;
			if (rem != 1 && rem != 0)
				goodInput = false;
		}
		if (goodInput == false)
			cout << "Sequence must be binary." << endl;	
	}
	else
		goodInput = false;
	return goodInput;
}

int binarraysize (int in) // determines required array size for decimal to binary
{
	int binarraysize = 0;
	while (in != 0)
	{
		in = in / 2;
		binarraysize++;
	}
	return binarraysize;
}

int NumDigits(int x) // determines length for binary sequence
{
	return (x < 10 ? 1 :
		(x < 100 ? 2 :
		 (x < 1000 ? 3 :
		  (x < 10000 ? 4 :
		   (x < 100000 ? 5 :
		    (x < 1000000 ? 6 :
		     (x < 10000000 ? 7 :
		      (x < 100000000 ? 8 :
		       (x < 1000000000 ? 9 :
		        10)))))))));
}

bool convertandsearch (int num, int numsize, int sequence, int seqsize)
{
	bool searchresult = false;
	int numarray[numsize], seqarray[seqsize];
	int rem = 0;
	int arrayindex = 0;
	int numIndex = 0;
	int seqIndex = 0;

	while (num > 0)   // converts inputted number to binary array
	{
		for (arrayindex = numsize - 1; arrayindex >= 0; arrayindex--)
		{
			rem = num % 2;
			numarray[arrayindex] = rem;
			num = num / 2;
		}
	}
	while (sequence > 0)   // converts inputted number to binary array
	{
		for (arrayindex = seqsize - 1; arrayindex >= 0; arrayindex--)
		{
			rem = sequence % 10;
			seqarray[arrayindex] = rem;
			sequence = sequence / 10;
		}
	}
	for (numIndex = 0; numIndex < numsize; numIndex++)
	{
		if (numarray[numIndex] ==  seqarray[seqIndex])
			seqIndex++;
		else
			seqIndex = 0;
		if (seqIndex == seqsize)
			searchresult = true;
	}
	return searchresult;
}

int main()
{
	int num, sequence, numsize, seqsize;
	bool goodIn, searchresult;

	cin >> num;
	cin >> sequence;
	goodIn = inputCheck(num, sequence);
	if (goodIn == true)
	{
		numsize = binarraysize (num);
		seqsize = NumDigits (sequence);
		searchresult = convertandsearch(num, numsize, sequence, seqsize);
		if (searchresult == true)
		{
			cout << "Sequence " << sequence << " occurs in ";
			cout << num << endl;
		}
		else
		{
			cout << "Sequence " << sequence << " does not occur in ";
			cout << num << endl;
		}
	}
	return 0;
}
