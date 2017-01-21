#ifndef SALLY_H
#define SALLY_H

// member initializers (vid 45)
// rename to Sally.h

class Sally
{
	public:
		Sally(int a, int b);
		void print(); 
	private:
		int regVar;
		const int constVar; 
		// whenever there is a const variable in a class,
	    // can't initialize it regularly, must initialize it
	    // in a special way through the use of member intializer (list)
	    // this list is in Sally2.cpp
};


#endif // SALLY_H
