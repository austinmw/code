#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <queue>
#include "trie.h"
using namespace std;


void getFileData(vector<string> &data1, vector<string> &data2, vector<string> &queries1,
			     vector<string> &queries2, vector<int> &counts1, vector<int> &counts2) {
	ifstream filedata1, filedata2;
	string line1, line2;
	string tempq1, tempq2;
	int i, tempd1, tempd2;
	istringstream iss1, iss2;

	filedata1.open("DC1-sampleQueries.txt");
    filedata2.open("DC2-sampleQueries.txt");
	while (getline(filedata1, line1))
		data1.push_back(line1);
	filedata1.close();
	while (getline(filedata2, line2))
		data2.push_back(line2);
	filedata2.close();
	for (i = 0; i < data1.size(); i++) {
		iss1.clear();
		iss2.clear();
		iss1.str(data1[i]);
		iss2.str(data2[i]);
		iss1 >> tempq1 >> tempd1;
		iss2 >> tempq2 >> tempd2;
		queries1.push_back(tempq1);
		queries2.push_back(tempq2);
		counts1.push_back(tempd1);
		counts2.push_back(tempd2);
	}
}

class MapADT {
	public:
		MapADT();
		MapADT(string filename);
		string find(const string& key);
		void insert(const string& key, const int& value);
		void print();
		unsigned int hash(const string& key);
		int find_index(const string& key, bool override_duplicated_key);
		const static unsigned int size_max = 250000;
		string keys[size_max];
		int values[size_max];
	};

	MapADT::MapADT() {
		for (int i = 0; i < size_max; i++) {
			keys[i] = string();
			values[i] = int();
		}
	}

	unsigned int MapADT::hash(const string& k)
	{
		unsigned int value = 0 ;
		for (int i = 0; i < k.length(); i++)
			value = 37*value + k[i];
		return value;
	}

	void MapADT::print() {
		cout << "{";
		for (int i = 0; i < size_max; i++)
			if (!keys[i].empty())
				cout << keys[i] << ":" << values[i] << ", ";
		cout << "}" << endl;
	}

	int MapADT::find_index(const string& key, bool override_duplicate_key = true) {
		unsigned int h = hash(key) % size_max, offset = 0, index;
		while (offset < size_max) {
			index = (h + offset) % size_max;
			if (keys[index].empty() ||
				(override_duplicate_key && keys[index] == key))
			return index;
			offset++;
		}
		return -1;
	}

	void MapADT::insert(const string& key, const int& value) {
		int index = find_index(key);
		if (index == -1) {
			cerr << "Table is full!" << endl;
			return;
		}
		keys[index] = key;
		values[index] += value;
}

void FillMap(vector<string> &queries1, vector<string> &queries2,
			 vector<int> counts1, vector<int> counts2, int n,
			 MapADT &map) {
	for (int i = 0; i < n; i++){
		map.insert(queries1[i],counts1[i]);
	}
	for (int i = 0; i < n; i++){
		map.insert(queries2[i],counts2[i]);
	}
}


int main(int argc, char *argv[]) {
	vector<string> data1, data2;
	vector<string> queries1, queries2;
	vector<int> counts1, counts2;
	MapADT map;
	getFileData(data1, data2, queries1, queries2, counts1, counts2);
	int n = queries1.size();
	FillMap(queries1, queries2, counts1, counts2, n, map);
	Trie autoc;
	for (int i = 0; i < map.size_max; i++){
        if (!map.keys[i].empty())
            autoc.insert(map.keys[i]);

	}
	vector<string> trieresults;
    const string test = "cach";
	trieresults = autoc.autocomplete(test);

    for (int x = 0; x != trieresults.size(); ++x)
    {
         cout << trieresults[x] << endl;
    }
}
