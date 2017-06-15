#include <iostream>
 
using namespace std;

// Base class
class Shape 
{
	public:
		void setWidth(int w)
		{
			width = w;
		}
		void setHeight(int h)
		{
			height = h;
		}
	protected:
		int width;
		int height;
};

// Derived class
class Rectangle: public Shape // grabs all pub fns/vars from Shape class
{
	public:
		int getArea()
		{ 
			return (width * height); 
		}
};

int main(void)
{
	Rectangle Rect;
 
	Rect.setWidth(5);
	Rect.setHeight(7);

	// Print the area of the object.
	cout << "Total area: " << Rect.getArea() << endl;

	return 0;
}

/*
If you want separate files, both .cpp files (Shape.cpp and Rectangle.cpp) will need to #include both .h files (Shape.h and Rectangle.h)


*/
