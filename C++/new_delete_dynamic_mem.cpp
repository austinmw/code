#include <iostream>

// dynamic memory requests are allocated by the system from the memory heap

using namespace std;
int main(int argc, char *argv[]) {
	
	int x = 5;
	
	
	int* array1 = new int[x];
	
	int *foo;
	foo = new int [x];
	
	delete[] array1;
	delete[] foo;

	
}

/*
You should use new when you wish an object to remain in existence until you delete it.
If you do not use new then the object will be destroyed when it goes out of scope.
e.g., class Point:
Point p1 = Point(0,0);
vs.
Point* p1 = new Point(0, 0);
*/

/*
A second example of when to allocate via new is for arrays. You cannot* change the size of an in-place or stack array at run-time so where you need an array of undetermined size it must be allocated via new.

E.g.

void foo(int size)
{
	Point* pointArray = new Point[size];
	...
	delete [] pointArray;
}
*/
