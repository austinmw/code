#include <iostream>
using namespace std;

// If you only want to use an object once, 
// you don't have to name it. This is called
// an Anonymous Object.

class Circle
{// Creates a class
public:
	Circle();               //Constructor
	Circle(double);         //Constructor
	 
	double getArea();        //Function
	double getRadius();      //Function
	void setRadius(double);  //Function

private:
	double radius;             //Data
};

// Constructor: no-arg constructor
Circle::Circle() 
{
	radius = 1;
}

// Constructor: second constructor
Circle::Circle(double newRadius)
{
	radius = newRadius;
}

// Function: Return the area of this circle
double Circle::getArea()
{
	return radius * radius * 3.14159;
}

// Function: Return the radius of this circle
double Circle::getRadius()
{
	return radius;
}

// Function: Set a new radius
void Circle::setRadius(double newRadius)
{
	radius = (newRadius >= 0) ? newRadius : 0;
}

//-------------------------------------------------------------------
// Main program
int main(int argc, char const *argv[])
{
	Circle(); // Anonymous Object using no-arg constructor
	Circle(5); // Anonymous Object using constructor with arguments
	cout << Circle(5).getArea() << endl; // Using an Anonymous Object
	
	Circle c1;	// Instantiates a no-arg Circle object
	c1 = Circle(2); // Constructs an anon object & copies its data to c1
	cout << c1.getArea() << endl;	
	
	c1 = Circle(3); // Constructs new anon object to rewrite data in c1
	cout << c1.getArea() << endl;
		
	Circle c2(4); // Instantiates object with argument
	cout << c2.getArea() << endl;
	
	c2 = Circle(8); // Constructs anon object to rewrite data in c2
	cout << c2.getArea() << endl;

	c1 = c2; // Copies data of c2 to c1
	cout << c1.getArea() << endl;
	cout << c2.getArea() << endl;

	return 0;
}











