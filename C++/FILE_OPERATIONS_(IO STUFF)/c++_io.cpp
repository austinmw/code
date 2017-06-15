/* C++ I/O Summary:
In the C++ programming language, Input/output library refers to a family of class templates and supporting functions in the C++ Standard Library that implement stream-based input/output capabilities. It is an object-oriented alternative to C's FILE-based streams from the C standard library.

Header files: The classes of the input/output library reside in several headers.
<ios> contains the definitions of ios_base and basic_ios classes, that manage formatting information and the associated streambuffer.
<istream> contains the definition of basic_istream class template, which implements formatted input
<ostream> contains the definition of basic_ostream class template, which implements formatted output
<iostream> contains the definition of basic_iostream class template, which implements formatted input and output
<fstream> contains the definitions of basic_ifstream, basic_ofstream and basic_fstream class templates which implement formatted input, output and input/output on file streams.
<sstream> contains the definitions of basic_istringstream, basic_ostringstream and basic_stringstream class templates which implement formatted input, output and input/output on string-based streams.
<iomanip> contains formatting manipulators.
<iosfwd> contains forward declarations of all classes in the input/output library.
*/

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;






/* ~~~~~~~~~~~~~~~~~~~~ <string> ~~~~~~~~~~~~~~~~~~~~ */
/* ~~~~~~~~~~~~~~~~~~~~ <string> ~~~~~~~~~~~~~~~~~~~~ */
// The standard string class
void string_getline_fn() // for c++ (string) strings
{/* (1)	
istream& getline (istream&  is, string& str, char delim);
istream& getline (istream&& is, string& str, char delim);
	(2)	
istream& getline (istream&  is, string& str);
istream& getline (istream&& is, string& str); */
	cin.ignore(); // move past previous '\0' (when needed)
	string s;
	getline(cin, s);
	cout << s;
} // http://www.cplusplus.com/reference/string/string/
/* includes Interator, Capacity, Element Access, Modifier, and String Operation functions:
Iterators:
	begin
	Return iterator to beginning (public member function )
	end
	Return iterator to end (public member function )
	rbegin
	Return reverse iterator to reverse beginning (public member function )
	rend
	Return reverse iterator to reverse end (public member function )
	cbegin 
	Return const_iterator to beginning (public member function )
	cend 
	Return const_iterator to end (public member function )
	crbegin 
	Return const_reverse_iterator to reverse beginning (public member function )
	crend 
	Return const_reverse_iterator to reverse end (public member function )

	Capacity:
	size
	Return length of string (public member function )
	length
	Return length of string (public member function )
	max_size
	Return maximum size of string (public member function )
	resize
	Resize string (public member function )
	capacity
	Return size of allocated storage (public member function )
	reserve
	Request a change in capacity (public member function )
	clear
	Clear string (public member function )
	empty
	Test if string is empty (public member function )
	shrink_to_fit 
	Shrink to fit (public member function )

	Element access:
	operator[]
	Get character of string (public member function )
	at
	Get character in string (public member function )
	back 
	Access last character (public member function )
	front 
	Access first character (public member function )

	Modifiers:
	operator+=
	Append to string (public member function )
	append
	Append to string (public member function )
	push_back
	Append character to string (public member function )
	assign
	Assign content to string (public member function )
	insert
	Insert into string (public member function )
	erase
	Erase characters from string (public member function )
	replace
	Replace portion of string (public member function )
	swap
	Swap string values (public member function )
	pop_back 
	Delete last character (public member function )

	String operations:
	c_str
	Get C string equivalent (public member function )
	data
	Get string data (public member function )
	get_allocator
	Get allocator (public member function )
	copy
	Copy sequence of characters from string (public member function )
	find
	Find content in string (public member function )
	rfind
	Find last occurrence of content in string (public member function )
	find_first_of
	Find character in string (public member function )
	find_last_of
	Find character in string from the end (public member function )
	find_first_not_of
	Find absence of character in string (public member function )
	find_last_not_of
	Find non-matching character in string from the end (public member function )
	substr
	Generate substring (public member function )
	compare
	Compare strings (public member function )

	Member constants
	npos
	Maximum value for size_t (public static member constant )

	Non-member function overloads:
	operator+
	Concatenate strings (function )
	relational operators
	Relational operators for string (function )
	swap
	Exchanges the values of two strings (function )
	operator>>
	Extract string from stream (function )
	operator<<
	Insert string into stream (function )
	getline
	Get line from stream into string (function )
*/


/* ~~~~~~~~~~~~~~~~~~~~ <iostream> ~~~~~~~~~~~~~~~~~~~~ */
/* ~~~~~~~~~~~~~~~~~~~~ <iostream> ~~~~~~~~~~~~~~~~~~~~ */
// Header that defines the standard input/output stream objects:
// Most modern compilers have included <ostream> and <istream> into <iostream>
void cin_cout_fn()
{
	int in, out;
	cin >> in;
	out = in;
	cout << out;
}

/* output to stderr via cerr flushes out the pending output on cout, 
   while output to stderr via clog does not
   By default, cerr & clog are both synchronized with stderr */
void cerr_clog_fn()
{// standard output streams for errors and logging (both correpond to stderr)
	clog << "This output from main is not tie()'d to cout\n";
	cerr << "This output is tie()'d to cout\n";
}

void endl_ends_flush_fn()
{// <ostream> Input manipulators (functions)
	cout << endl; // Insert newline and flush
	cout << ends; // Insert null character 
	cout << flush; // Flush stream buffer 
}

void istream_getline_fn() // for c (char*) strings
{// istream& getline (char* s, streamsize n );     ('\n' default delimiter)
// istream& getline (char* s, streamsize n, char delim );
	char name[256], title[256];
	cout << "Please, enter your name: ";
	cin.getline(name,256);
	cout << "Please, enter your favourite movie: ";
	cin.getline(title,256);
	cout << name << "'s favourite movie is " << title;
}






/* ~~~~~~~~~~~~~~~~~~~~ <string>, <fstream>, <sstream> example ~~~~~~~~~~~~~~~~~~~~ */


void getFileData() 
{// opens file, reads entire file, closes, formats list of "word number" into separate
// vector<string> and vector<int>
	fstream file; // also istream, ostream
	stringstream ss; // also istringstream, ostringstream	
	string line;
	vector<string> fulldata;
	string temp_s;
	int temp_i;
	vector<string> words;
	vector<int> numbers;

	file.open("readwritetest.txt");
	/* or to create/overwrite: 
	file.open("readwritetest.txt", fstream::in | fstream::out | fstream::trunc); */
	file << "write stuff\n"; // this will write overtop of data, but not clear data immediately 
	
	while (getline(file, line))
		fulldata.push_back(line);
	file.close();
	
	// using fulldata (for example, each line contains: "blaaah  5"
	for (int i = 0; i < fulldata.size(); i++) {
		ss.clear();
		ss.str(fulldata[i]); // can also do things like: string s = ss.str("testing");
		ss >> temp_s >> temp_i;
		words.push_back(temp_s);
		numbers.push_back(temp_i);
	}	
}





/* ~~~~~~~~~~~~~~~~~~~~ main ~~~~~~~~~~~~~~~~~~~~ */
/* ~~~~~~~~~~~~~~~~~~~~ main ~~~~~~~~~~~~~~~~~~~~ */
int main(int argc, char *argv[]) {

	
	return 0;
}




// add later:
	// getline()
	// auto (11/14)
	// nullptr
	// lambdas

	// string
	// cstdlib
	// fstream
	// sstream
	// iomanip
	// iosfwd??