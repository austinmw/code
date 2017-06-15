#include <iostream>
using namespace std;



void passptr (int *p)
{
	*p = 7; //change the value of num
}

void passaddy (int &a)
{
	a = 7;
}

void ptrfn()
{
	int a = 5;
	int *p;
	p = &a;
	cout << endl;		
	cout << a << endl << *p << endl << p << endl;
	cout << &a << endl << &p << endl;		
	*p = 6;
	cout << a << endl;
}

int main()
{
	int num = 5;
	int *ptr = &num; //pointer to num location
	
	cout<< "num value is "<<num<<endl;
	passptr(ptr);      //pass num location to function
	cout<< "num value is now "<<num<< endl << endl;
		
	num = 5;
	cout<< "num value is "<<num<<endl;
	passaddy(num);
	cout<< "num value is now "<<num<<endl;

	ptrfn();
	return 0;
}

