// austinmw
// Ran default in 3s in OSX, but 9s in Codeblocks
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

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

string reducePermutation(string letters, int length)
{// Reduces permutation count to smaller of two words
	int letterslength = letters.size();
	int firstwordlength = letterslength - length;
	int secondwordlength = letterslength - firstwordlength;
	int uselength1 = secondwordlength;
	int uselength2 = firstwordlength;
	if (firstwordlength > secondwordlength)
	{
		uselength1 = firstwordlength;
		uselength2 = secondwordlength;
	}
	string boolstring;
	for (int i = 0; i < uselength1; i++)
		boolstring += '0';
	for (int i = 0; i < uselength2; i++)
		boolstring += '1';
	return boolstring;
}

vector<string> createdcombos(string letters, string boolstring)
{// Creates permutation lists for strings
	vector<string> lettercombos;
	sort(letters.begin(), letters.end());
	do
	{
		string tempword;
		for (int j = 0; j != boolstring.size(); j++)
		{
			if (boolstring[j] == '1')
				tempword += letters[j];
		}
		do
			lettercombos.push_back(tempword);
		while(next_permutation(tempword.begin(), tempword.end()));
	}
	while(next_permutation(boolstring.begin(), boolstring.end()));
	return lettercombos;
}

vector<string> combosVsWords(vector<string> &words,
							 vector<string> &lettercombos)
{// Checks permutations against word list
	vector<string> firstwords;
	sort(words.begin(), words.end());
	sort(lettercombos.begin(), lettercombos.end());
	set_intersection(words.begin(),words.end(),lettercombos.begin(),
					 lettercombos.end(), back_inserter(firstwords));
	return firstwords;
}

vector<string> secondletters(string letters, vector<string> firstwords)
{// Returns available second letters for each created first word
	vector<string> secletters(firstwords.size());
	for (int i = 0; i != firstwords.size(); i++)
	{
		string templetters = letters;
		for (int j = 0; j != firstwords[i].size(); j++)
		{
			auto k = find(templetters.begin(), templetters.end(),
						  firstwords[i][j]);
			if (k != templetters.end())
				templetters.erase(k);
		}
		secletters[i] += templetters;
	}
	return secletters;
}

vector<vector<string> > secondwords(vector<string> secletters,
									vector<string> words)
{// Creates second word lists for each first word
	string boolstring;
	vector<vector<string> > seclettercombos(secletters.size());
	vector<vector<string> > secwords(secletters.size());
	for (int i = 0; i != secletters[0].size(); i++)
		boolstring += '1';
	for (int i = 0; i != secletters.size(); i++)
		seclettercombos[i] = createdcombos(secletters[i], boolstring);
	for (int i = 0; i != secletters.size(); i++)
		secwords[i] = combosVsWords(words, seclettercombos[i]);
	return secwords;
}

void wordcombos(vector<string> firstwords, vector<vector<string> > secwords)
{// Adds first and second words together and prints them out
	vector<string> twowordcombos;
	if (secwords.size() >= 1)
	{
		for (int i = 0; i != secwords.size(); i++)
		{
			if (secwords[i].size() > 0)
			{
				for (int j = 0; j != secwords[i].size(); j++)
				{
					twowordcombos.push_back(firstwords[i] + " "
					 + secwords[i][j]);
				}
			}
		}
		for (auto i: twowordcombos)
			cout << i << endl;
	}
}

int main(int argc, char *argv[])
{
	string wordlist = "enable1.txt";
	string letters = "aadekmmnortww";
	int length = 7;
	vector<string> words;
	string boolstring;
	vector<string> lettercombos;
	vector<string> firstwords;
	vector<string> secletters;
	vector<vector<string> > secwords;
	vector<string> answers;

	if (argc == 4)
	{// Terminal input parameters
		wordlist = argv[1];
		letters = argv[2];
		length = atoi(argv[3]);
	}
	words = getFileData(wordlist);
	boolstring = reducePermutation(letters, length);
	lettercombos = createdcombos(letters, boolstring);
	firstwords = combosVsWords(words, lettercombos);
	if (firstwords.size() > 0)
	{
		secletters = secondletters(letters, firstwords);
		secwords = secondwords(secletters, words);
		wordcombos(firstwords, secwords);
	}
	return 0;
}
