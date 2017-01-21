#include <iostream>

using namespace std;

/* keyword friend
Every class can have friends
a friend is totally separate from the class, but still has
access to the stuff inside the class like the variables and functions
*/


class StankFist{
	public:
		StankFist(){stinkyVar=0;} // constructor
	private:
		int stinkyVar; // this is only accessible by things inside this class
		
	// need to prototype friend inside class
	friend void stinkysFriend(StankFist &stfo);
	// now this function has access to everything inside this class
};


void stinkysFriend(StankFist &sfo) {
	sfo.stinkyVar = 99;
	cout << sfo.stinkyVar << endl;
}


int main() {
	
	StankFist sfObj;
	stinkysFriend(sfObj);
		 
}