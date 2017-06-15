#include <iostream>
using namespace std;

void pass_by_reference(int &value)
{ // C++ only feature
	value = 6;
}
 
void pass_by_pointer(int *value)
{
	*value = 7;
}

void pass_by_value(int value)
{
	value = 8;
}



int main()
{
	int value = 5;
 
	cout << "value = " << value << '\n';
	
	pass_by_reference(value);
	cout << "value = " << value << '\n';
	
	pass_by_pointer(&value);
	cout << "value = " << value << '\n';
	
	pass_by_value(value);
	cout << "value = " << value << '\n';
	
	

	return 0;
}

/*
// Use reference when you can, and pointers when you have to (NULL)

To summarize:
1. Pass by value when the function does not want to modify the parameter and the
value is easy to copy (ints, doubles, char, bool, etc... simple types. std::string,
std::vector, and all other STL containers are NOT simple types.)

2. Pass by const pointer when the value is expensive to copy AND the function does
not want to modify the value pointed to AND NULL is a valid, expected value that
the function handles.

3. Pass by non-const pointer when the value is expensive to copy AND the function
wants to modify the value pointed to AND NULL is a vlaid, expected value that the
function handles.

4. Pass by const reference when the value is expensive to copy AND the function does
not want to modify the value referred to AND NULL would not be a valid value if 
a pointer was used instead.

5. Pass by non-cont reference when the value is expensive to copy AND the function wants
to modify the value referred to AND NULL would not be a valid value if a pointer was used 
instead.

6. When writing template functions, there isn't a clear-cut answer because there are a few
tradeoffs to consider that are beyond the scope of this discussion, but suffice it to say that
most template functions take their parameters by value or (const) reference, however
because iterator syntax is similar to that of pointers (asterisk to "dereference"), any
template function that expects iterators as arguments will also by default accept pointers
as well (and not check for NULL since the NULL iterator concept has a different syntax).
*/