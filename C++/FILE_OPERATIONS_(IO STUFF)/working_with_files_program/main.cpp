#include <iostream>
#include <fstream>
using namespace std;

// this is "prototyping" 
int getWhatTheyWant();
void displayItems(int x);

// main program
int main() {
	int whatTheyWant;
	
	whatTheyWant = getWhatTheyWant();
	while (whatTheyWant != 4) {
		
		switch(whatTheyWant){
			case 1:
				displayItems(1);
				break;
			case 2:
				displayItems(2);
				break;
			case 3:
				displayItems(3);
				break;
		}
		whatTheyWant = getWhatTheyWant();
	}
}

// select choice
int getWhatTheyWant(){
	int choice;
	
	cout << "\n1 - just plain items" << endl;
	cout << "2- helpful items" << endl;
	cout << "3 - harmful items" << endl;
	cout << "4 - quit program" << endl;
	
	cin >> choice;
	return choice;
}

// read, filter, display
void displayItems(int x){	
	ifstream objectFile("objects.txt");
	string name;
	double power;
	
	if (x==1) {
		while(objectFile >> name >> power){
			if (power == 0)
				cout << name << endl;
		}
	}
	else if (x==2) {
		while(objectFile >> name >> power){
			if (power > 0)
				cout << name << endl;
		}
	}
	else if (x==3) {
		while(objectFile >> name >> power){
			if (power < 0)
				cout << name << endl;
		}
	}
}







