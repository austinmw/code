#include <iostream>
using namespace std;

/* POLYMORPHISM IN OOP
Say you're writing a program that deals with Shapes. So, you write an abstract Shape class which states that all Shapes must have functions to CalculateArea, CalculatePerimiter, and Draw. Then, you write a bunch of other classes called Circle, Square, and Triangle that all inherit from Shape. Because they all inherit from Shape, they all must have those three functions.
Now you can write code that deals with shapes. Lets say you want to add up the area of a whole bunch of different shapes. Instead of having a List of Circles (List<Circle>), List<Square>, and List<Triangle>, and deal with each separately you can just make one generic List<Shape>. Thanks to Polymorphism (poly = "many", morph = "shape"), you can iterate over the this single list, calling CalculateArea on each element of it, and the language/compiler will automatically figure out whether it needs to run Circle.CalculateArea, Square.CalculateArea, or Triangle.CalculateArea for each one.
*/



class Enemy{
	public:
		virtual void attack(){}
		/* whenever you make a function virtual, it means that you are going to be
		using it polymorphically, and that way, it knows to look in specific class for
		the function instead of the top class */
		/* the virtual attack function in Enemy is just a template saying that each
		class which inherits from Enemy is going to have an attack function
		it will find the address (type of enemy) and call that attack instead */
};


class Ninja: public Enemy{
	public:
		void attack(){
			cout << "ninja attack!" << endl;
		}
};

class Monster: public Enemy{
	public:
		void attack(){
			cout << "monster attack!" << endl;
		}
};


int main() {

	Ninja n;
	Monster m;
	
	Enemy *enemy1 = &n;
	Enemy *enemy2 = &m;
	
	// because of the virtual function, can do:
	enemy1->attack();
	enemy2->attack();
	
}

// In summary: same function, same type of object, different results,
// based on which address it's pointing to







