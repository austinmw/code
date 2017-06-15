// Sample input: 6

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;



class AdvancedArithmetic{
    public:
	// A pure virtual function is specified by placing "= 0" in its declaration 
	virtual int divisorSum(int n)=0; 
};


class Calculator : public AdvancedArithmetic {
	// private by default
	int divisorSum(int n)
	{
		int i, sum = 0;
		for (i = 1; i <= n; i++){
			if (n%i == 0)
				sum+=i;
		}	
		return(sum);
	}
	
};


int main(){
	int n;
	cin >> n;
	AdvancedArithmetic *myCalculator = new Calculator(); 
	int sum = myCalculator->divisorSum(n);
	cout << "I implemented: AdvancedArithmetic\n" << sum;
	return 0;
}

/*
An abstract base class with no non-abstract (pure virtual) methods is functionally equivalent to a C#/Java interface. There is no concept of "interface" per se in C++. AFAIK, interfaces were first introduced in Java to work around the lack of multiple inheritance.

The C++ interfaces are implemented using abstract classes and these abstract classes should not be confused with data abstraction which is a concept of keeping implementation details separate from associated data. A class is made abstract by declaring at least one of its functions as pure virtual function.  


From StackOverflow:
One of the most common reasons for using an interface is so that you can "program against an abstraction" rather then a concrete implementation.

The biggest benefit of this is that it allows changing of parts of your code while minimising the change on the remaining code.

Therefore although we don't know the full background of what you're building, I would go for the Interface / factory approach.

Having said this, in smaller applications or prototypes I often start with concrete classes until I get a feel for where/if an interface would be desirable. Interfaces can introduce a level of indirection that may just not be necessary for the scale of app you're building.

As a result in smaller apps, I find I don't actually need my own custom interfaces. Like so many things, you need to weigh up the costs and benefits specific to your situation.
*/