#include <iostream>
#include <vector>

using namespace std;
	
template <typename Type>
void printArray(vector<Type> vVector) {
for (auto i = vVector.begin(); i != vVector.end(); ++i)
	std::cout << *i << endl;	
}

int main() {
	vector<int> vInt{1, 2, 3};
	vector<string> vString{"Hello", "World"};
	
	printArray<int>(vInt);
	printArray<string>(vString);
	
	return 0;
}



/*
Templates are a feature of the C++ programming language that allows functions and classes to operate with generic types. This allows a function or class to work on many different data types without being rewritten for each one.

Templates are of great utility to programmers in C++, especially when combined with multiple inheritance and operator overloading. The C++ Standard Library provides many useful functions within a framework of connected templates.

There are three kinds of templates: function templates, class templates and, since C++14, variable templates. Since C++11, templates may be either variadic or non-variadic; in earlier versions of C++ they are always non-variadic.

A function template behaves like a function except that the template can have arguments of many different types (see example). In other words, a function template represents a family of functions. The format for declaring function templates with type parameters is

template <class identifier> function_declaration;
template <typename identifier> function_declaration;

Both expressions have the same meaning and behave in exactly the same way. The latter form was introduced to avoid confusion,[2] since a type parameter need not be a class. (it can also be a basic type such as int or double.)

For example, the C++ Standard Library contains the function template max(x, y) which returns the larger of x and y. That function template could be defined like this:

template <typename Type>
Type max(Type a, Type b) {
	return a > b ? a : b;
}
This single function definition works with many data types. The usage of a function template saves space in the source code file in addition to limiting changes to one function description and making the code easier to read.

A template does not produce smaller object code, though, compared to writing separate functions for all the different data types used in a specific program. For example, if a program uses both an int and a double version of the max() function template shown above, the compiler will create an object code version of max() that operates on int arguments and another object code version that operates on double arguments. The compiler output will be identical to what would have been produced if the source code had contained two separate non-templated versions of max(), one written to handle int and one written to handle double.

Here is how the function template could be used:

#include <iostream>

int main()
{
	// This will call max<int> by implicit argument deduction.
	std::cout << max(3, 7) << std::endl;

	// This will call max<double> by implicit argument deduction.
	std::cout << max(3.0, 7.0) << std::endl;

	// This depends on the compiler. Some compilers handle this by defining a template
	// function like double max <double> ( double a, double b);, while in some compilers 
	// we need to explicitly cast it, like std::cout << max<double>(3,7.0);
	std::cout << max(3, 7.0) << std::endl; 
	std::cout << max<double>(3, 7.0) << std::endl;
	return 0;
}
In the first two cases, the template argument Type is automatically deduced by the compiler to be int and double, respectively. In the third case automatic deduction of max(3, 7.0) would fail because the type of the parameters must in general match the template arguments exactly. Therefore we explicitly instantiate the double version with max<double>().

This function template can be instantiated with any copy-constructible type for which the expression y > x is valid. For user-defined types, this implies that the greater-than operator (>) must be overloaded in the type.

Class templates[edit]
A class template provides a specification for generating classes based on parameters. Class templates are generally used to implement containers. A class template is instantiated by passing a given set of types to it as template arguments.[3] The C++ Standard Library contains many class templates, in particular the containers adapted from the Standard Template Library, such as vector.
*/