#include <cmath>
#include <iostream>
#include <exception>
#include <stdexcept>
using namespace std;


/*
If the class is declared using the keyword class then its members are private by default; 
if it is declared using the keyword struct or union then its members are public by default. 
Note that all three kinds of types are officially known as classes.

The C++ Standard library provides a base class specifically designed to declare objects to be 
thrown as exceptions. It is called std::exception and is defined in the <exception> header. 
This class has a virtual member function called what that returns a null-terminated character sequence 
(of type char *) and that can be overwritten in derived classes to contain some sort of description of the exception.

exception is a class with virtual public member function what()
*/


struct MyException : public exception { // inheritance
	virtual const char* what() const throw() {
		return "n and p should be non-negative";
	}  
};

class Calculator {
	public:		
		int power(int n, int p) {
			if (n < 0 || p < 0) {
				throw MyException();
			}
			return pow(n,p);
		}    
};



// Given:
int main()
{
	 Calculator myCalculator=Calculator();
	 int T,n,p;
	 cin>>T;
	 while(T-->0){
		if(scanf("%d %d",&n,&p)==2){
			try{
					int ans=myCalculator.power(n,p);
					cout<<ans<<endl; 
			}
			catch(exception& e){
				 cout<<e.what()<<endl;
			}
		}
	 }
	 
}