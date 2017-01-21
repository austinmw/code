#include <iostream>
using namespace std;



// class definition
class Person{
	public:
		 int age ;
	//	 Person(); // default constructor
		Person(); // default constructor
		 Person(int initialAge); // parameterized constructor
		~Person(); // destructor
		 void amIOld();
		 void yearPasses();

};

// constructor
Person::Person(int initialAge){
		if (initialAge >= 0)
				age = initialAge;
		else {
				age = 0;
				cout << "Age is not valid, setting age to 0.\n";
		}
	// Add some more code to run some checks on initialAge

}

// destructor
Person::~Person(void)
{
	cout << "Object is being deleted" << endl;
}

// class function
void Person::amIOld(){
		// Do some computations in here and print out the correct statement to the console 
		if (age < 13)
				cout << "You are young.\n";
		else if ((age < 18 ) && (age >= 13))
				cout << "You are a teenager.\n";
		else cout << "You are old.\n";
}
		
// class function 
void Person::yearPasses(){
	// Increment the age of the person in here
		age++;
}
	
	
	
	
int main(){
	int T,age;
	cin>>T;
	for(int i=0;i<T;i++)
	{
		cin>>age;
		Person p(age);
		p.amIOld();
		for(int j=0;j<3;j++)
		{
			p.yearPasses();
			
		}
		p.amIOld();
		cout<<"\n";
	}
	return 0;
}
	

