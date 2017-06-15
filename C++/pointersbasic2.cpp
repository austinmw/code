#include <iostream>
using namespace std;

void passptr(int *p)
{
	*p = 7;
}
	
void passaddy(int &a)
{
	a = 7;
}
	
int main()
{
	int a = 5;
	int *p = &a;

	passptr(p);
	cout << a << endl;

	a = 5;
	passaddy(a);
	cout << a << endl;

	return 0;
}

/*

There are a few issues at play.

Plain arrays aren't copyable or assignable.
Function parameters such as int a[] get adjusted to pointer int* a.
Array names can decay decay to a pointer to their first element
That 2nd point means that

void array_increment(int list[],int SIZE) 
is really

void array_increment(int* list,int SIZE) 
and the 3rd point means you can pass array c as first argument because it can decay to int*.

*/

