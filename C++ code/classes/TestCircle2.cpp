#include <iostream>
using namespace std;

// Define a new type: Circle
// this class has methods (functions) and data (attributes)
//
// This class definition is the nicer way of doing it 
// which is separating the interface from the implementation

class Circle
{
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

// Main program
int main(int argc, char const *argv[])
{
	Circle c; // Creates an object c (instance) of class Circle
	cout << c.getRadius() << " "  << c.getArea() << endl;
	return 0;
}