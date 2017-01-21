// Example of using map to organize the word list by length.

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{

  string word;
  map<int, vector<string> > wordsoflength;
  ifstream words_file;

  words_file.open("smallwordlist.txt");

  while (words_file>>word) {
        wordsoflength[word.size()].push_back(word);
  }

  words_file.close();


    for (int i=2; i<10; i++){
      for (auto word  : wordsoflength[i])
      	 cout<< i <<" " << word << endl;
     }

 	return 0;

}