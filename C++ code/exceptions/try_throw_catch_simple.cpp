#include <iostream>
using namespace std;


int main() {
	
	int momsAge = 30;
	int sonsAge = 34;
	
	try{
		if (sonsAge > momsAge){
			throw 99; // err # (can do other things too) used to identify multiple errors
		}
	}catch(int x){
		cout << "son can not be older than mom, ERROR NUMBER: " << x << endl;
	}
	
	
	
}