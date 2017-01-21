#include <iostream>

class Circle
{
public:
	// The radius of this circle
	double radius;
	
	// Construct a default circle object
	Circle()
	{
		radius = 1; // no-arg constructor
	}
		
	// Construct a circle object
	Circle(double newRadius)
	{
		radius = newRadius; // 2nd constructor 
	}	
	
	// Return the area of this circle
	double getArea()
	{
		return radius * radius * 3.14159;
	}
}; // Don't forget semicolon



int main() 
{
	Circle circle1(1.0);
	Circle circle2(25);
	Circle circle3(125);
	
	std::cout << "The area of the circle of radius " 
	  << circle1.radius << " is " << circle1.getArea() << std::endl;
	std::cout << "The area of the circle of radius "
	  << circle2.radius << " is " << circle2.getArea() << std::endl;
	std::cout << "The area of the circle of radius "
	  << circle3.radius << " is " << circle3.getArea() << std::endl;
	
	// Modify circle radius
	circle2.radius = 100;
	std::cout << "The area of the circle of radius "
	  << circle2.radius << " is " << circle2.getArea() << std::endl;

	// Data are physically stored in an object, but functions 
	// are not. They are shared by all objects of the same class.
	std::cout << "The size of circle1 in bytes is " 
	  << sizeof(circle1) << std::endl;
	// The size is 8 because the type double takes 8 bytes.


	return 0;
}