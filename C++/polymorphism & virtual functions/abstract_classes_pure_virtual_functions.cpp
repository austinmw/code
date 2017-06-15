#include <iostream>
using namespace std;


/* 
an Abstract Class is just a class with a pure virtual function in it.
A class is abstract if it has at least one pure virtual function.

A pure virtual function specifies an interface that must be overridden in a derived class to be able to create objects of the derived class.

A (non-pure) virtual function specifies an interface that can be overridden in a derived class, but the base class provides a default implementation of the interface.

Reason for having them:
The purpose of an abstract class is to define a common protocol for a set of concrete subclasses. This is useful when defining objects that share code, abstract ideas, etc.

Abstract classes have no instances. An abstract class must have at least one deferred method (or function). To accomplish this in C++, a pure virtual member function is declared but not defined in the abstract class
*/



class Enemy{
	public:
		virtual void attack(){
			cout << "i am the enemy class!" << endl;
		}
		// pure virtual function
		virtual void attack2()=0;
		// therefore, Enemy is an abstract class
};

class Ninja: public Enemy{
	public:
		void attack(){
			cout << "ninja attack!" << endl;
		}
		void attack2(){  // required function b.c. inheriting from pure virtual fn
			cout << "ninja second attack!" << endl;
		}
		
};

class Monster: public Enemy{
	public:
		void attack2(){  // required function b.c. inheriting from pure virtual fn
			cout << "monster second attack!" << endl;
		}


};

int main() {

	Ninja n;
	Monster m;
	
	Enemy *enemy1 = &n;
	Enemy *enemy2 = &m;

	
	// even though we inherited the Enemy attack(),
	// we overwrote it in the derived Ninja's attack()
	enemy1->attack();


	// didn't overwrite here because Monster doesn't have attack()
	enemy2->attack();



	/* a pure virtual function, instead, does not give the option 
	to inherit from the base class. 
 	create pure virtual function in Enemy class with '=0':
	virtual void attack2()=0; 
	(doesn't do anything or have {})
	Any derived class that inherits from a class with a pure virtual function,
	MUST overwrite that function. */
	enemy1->attack2();
	enemy2->attack2();


}




