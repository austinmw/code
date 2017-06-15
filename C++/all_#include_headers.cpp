#include <iostream>


// for C++:
// containers
#include <array>
#include <bitset>
#include <deque>
#include <forward_list>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>
// general
#include <algorithm>
#include <chrono>
#include <functional>
#include <iterator>
#include <memory>
#include <stdexcept>
#include <tuple>
#include <utility>
// localization
#include <locale>
#include <codecvt>
// strings
#include <string>
#include <regex>
// streams and input/output
#include <fstream>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <iostream>
#include <istream>
#include <ostream>
#include <sstream>
#include <streambuf>
// language support
#include <exception>
#include <limits>
#include <typeinfo>
// thread support library
#include <thread>
#include <mutex>
#include <condition_variable>
#include <future>
// numerics library
#include <complex>
#include <random>
#include <valarray>
#include <numeric>


// from C:
#include <cassert> 
#include <ccomplex> 
#include <cctype> 
#include <cerrno> 
#include <cfenv> 
#include <cfloat> 
#include <cinttypes> 
#include <ciso646> 
#include <climits> 
#include <clocale> 
#include <cmath> 
#include <csetjmp>
#include <csignal> 
// #include <cstdalign> // not found
#include <cstdarg> 
// #include <cstdatomic> // not found
#include <cstdbool> 
#include <cstddef> 
#include <cstdint> 
#include <cstdio> 
#include <cstdlib> 
// #include <cstdnoreturn> // not found
#include <cstring> 
#include <ctgmath> 
// #include <cthreads> // not found
#include <ctime> 
// #include <cuchar> // not found
#include <cwchar> 
#include <cwctype> 

 

/* C++

CONTAINERS:
<array>
New in C++11 and TR1. Provides the container class template std::array, a container for a fixed sized array.
<bitset>
Provides the specialized container class std::bitset, a bit array.
<deque>
Provides the container class template std::deque, a double-ended queue.
<forward_list>
New in C++11 and TR1. Provides the container class template std::forward_list, a singly linked list.
<list>
Provides the container class template std::list, a doubly linked list.
<map>
Provides the container class templates std::map and std::multimap, sorted associative array and multimap.
<queue>
Provides the container adapter class std::queue, a single-ended queue, and std::priority_queue, a priority queue.
<set>
Provides the container class templates std::set and std::multiset, sorted associative containers or sets.
<stack>
Provides the container adapter class std::stack, a stack.
<unordered_map>
New in C++11 and TR1. Provides the container class template std::unordered_map and std::unordered_multimap, hash tables.
<unordered_set>
New in C++11 and TR1. Provides the container class template std::unordered_set and std::unordered_multiset.
<vector>
Provides the container class template std::vector, a dynamic array.

GENERAL
<algorithm>
Provides definitions of many container algorithms.
<chrono>
Provides time elements, such as std::chrono::duration, std::chrono::time_point, and clocks.
<functional>
Provides several function objects, designed for use with the standard algorithms.
<iterator>
Provides classes and templates for working with iterators.
<memory>
Provides facilities for memory management in C++, including the class template std::unique_ptr.
<stdexcept>
Contains standard exception classes such as std::logic_error and std::runtime_error, both derived from std::exception.
<tuple>
New in C++11 and TR1. Provides a class template std::tuple, a tuple.
<utility>
Provides the template class std::pair, for working with object pairs (two-member tuples), and the namespace std::rel_ops, for easier operator overloading.

LOCALIZATION
<locale>
Defines classes and declares functions that encapsulate and manipulate the information peculiar to a locale.
<codecvt>
Provides code conversion facets for various character encodings.

STRINGS
<string>
Provides the C++ standard string classes and templates.
<regex>
New in C++11. Provides utilities for pattern matching strings using regular expressions.

STREAMS AND INPUT/OUTPUT
<fstream>
Provides facilities for file-based input and output. See fstream.
<iomanip>
Provides facilities to manipulate output formatting, such as the base used when formatting integers and the precision of floating point values.
<ios>
Provides several types and functions basic to the operation of iostreams.
<iosfwd>
Provides forward declarations of several I/O-related class templates.
<iostream>
Provides C++ input and output fundamentals. See iostream.
<istream>
Provides the template class std::istream and other supporting classes for input.
<ostream>
Provides the template class std::ostream and other supporting classes for output.
<sstream>
Provides the template class std::stringstream and other supporting classes for string manipulation.
<streambuf>
Provides reading and writing functionality to/from certain types of character sequences, such as external files or strings.

LANGUAGE SUPPORT
<exception>
Provides several types and functions related to exception handling, including std::exception, the base class of all exceptions thrown by the Standard Library.
<limits>
Provides the template class std::numeric_limits, used for describing properties of fundamental numeric types.
<new>
Provides operators new and delete and other functions and types composing the fundamentals of C++ memory management.
<typeinfo>
Provides facilities for working with C++ run-time type information.


THREAD SUPPORT LIBRARY
<thread>
New in C++11. Provide class and namespace for working with threads.
<mutex>
New in C++11. 30.4-1 This section provides mechanisms for mutual exclusion: mutexes, locks, and call once.
<condition_variable>
New in C++11. 30.5-1 Condition variables provide synchronization primitives used to block a thread until notified by some other thread that some condition is met or until a system time is reached.
<future>
New in C++11. 30.6.1-1 Describes components that a C++ program can use to retrieve in one thread the result (value or exception) from a function that has run in the same thread or another thread.

NUMERICS LIBRARY
Components that C++ programs may use to perform seminumerical operations.
<complex>
The header <complex> defines a class template, and numerous functions for representing and manipulating complex numbers.
<random>
Facility for generating (pseudo-)random numbers
<valarray>
Defines five class templates (valarray, slice_array, gslice_array, mask_array, and indirect_array), two classes (slice and gslice), and a series of related function templates for representing and manipulating arrays of values.
<numeric>
Generalized numeric operations.
*/






/* C

<assert.h>		Contains the assert macro, used to assist with detecting logical errors and other types of bug in debugging versions of a program.
<complex.h>	C99	A set of functions for manipulating complex numbers.
<ctype.h>		Defines set of functions used to classify characters by their types or to convert between upper and lower case in a way that is independent of the used character set (typically ASCII or one of its extensions, although implementations utilizing EBCDIC are also known).
<errno.h>		For testing error codes reported by library functions.
<fenv.h>	C99	Defines a set of functions for controlling floating-point environment.
<float.h>		Defines macro constants specifying the implementation-specific properties of the floating-point library.
<inttypes.h>	C99	Defines exact width integer types.
<iso646.h>	NA1	Defines several macros that implement alternative ways to express  several standard tokens. For programming in ISO 646 variant character sets.
<limits.h>		Defines macro constants specifying the implementation-specific properties of the integer types.
<locale.h>		Defines localization functions. 
<math.h>		Defines common mathematical functions.
<setjmp.h>		Declares the macros setjmp and longjmp, which are used for non-local  exits.
<signal.h>		Defines signal handling functions.
<stdalign.h>	C11	For querying and specifying the alignment of objects. 
<stdarg.h>		For accessing a varying number of arguments passed to functions.
<stdatomic.h>	C11	For atomic operations on data shared between threads. 
<stdbool.h>	C99	Defines a boolean data type. 
<stddef.h>		Defines several useful types and macros. 
<stdint.h>	C99	Defines exact width integer types. 
<stdio.h>		Defines core input and output functions
<stdlib.h>		Defines numeric conversion functions, pseudo-random numbers  generation functions, memory allocation, process control functions
<stdnoreturn.h>	C11	For specifying non-returning functions.
<string.h>		Defines string handling functions. 
<tgmath.h>	C99	Defines type-generic mathematical functions. 
<threads.h>	C11	Defines functions for managing multiple Threads as well as mutexes and condition variables.
<time.h>		Defines date and time handling functions 
<uchar.h>	C11	Types and functions for manipulating Unicode characters.
<wchar.h>	NA1	Defines wide string handling functions. 
<wctype.h>	NA1	Defines set of functions used to classify wide characters by their types or to convert between upper and lower case
*/



using namespace std;
int main(int argc, char *argv[]) {
	
}