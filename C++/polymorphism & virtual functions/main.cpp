#include <iostream>
using namespace std;

// regular example, without polymorphism

class Enemy{
	public:
		void setAttackPower(int a){
			attackPower = a;
		}
	protected:
		int attackPower;
};
// We have an Enemy class which is common to all enemies, so
// all enemies are going to have attackPower,
// however, each type of enemy is going to attack in a specific way:


class Ninja: public Enemy{
	public:
		void attack(){
			cout << "i am a ninja, ninja chop! -" << attackPower << endl;
		}
};

class Monster: public Enemy{
	public:
		void attack(){
			cout << "monster must eat you!!! -" << attackPower << endl;
		}
};


int main() {

	Ninja n;
	Monster m;
	
	// pointer set to address of ninja object
	Enemy *enemy1 = &n;  // valid b.c. ninja is a type of enemy
	Enemy *enemy2 = &m;
	
	// working with pointer object, need ->
	enemy1->setAttackPower(29); // knows to apply this to ninja object attackPower
	enemy2->setAttackPower(99);
	
	n.attack();
	m.attack();
	
	// Would be easier if we could just make the enemy objects attack as well
	// rather than having to switch back to ninja, monster classes
	// THIS IS THE CONCEPT OF POLYMORPHISM (GO TO main2.cpp)
	
	
}










