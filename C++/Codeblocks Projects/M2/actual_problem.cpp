// Your assignment is to write a
// complete, readable, documented, tested, and well-designed
//  function called X (see details below)
//
// You may change the calling signature of the function 
//  (i.e. change the parameters (order, type, names) 
//  or the return value)
//
//  Part of your grade will be based on whether/how you do this.

// Your documentation should be appropriate
//
// Your code should be readable

// You must handle all possible bad inputs in a consistent
// way. Your options are:
//   - print the message "Fcn X error" and exit.
//   - return a valid empty result.
//
// Your code should be efficient for large or small values of the input
// parameters.

// Your grade will be based on all of the following factors:
// - the function signature you use
// - the completeness of your test code
// - the readability and documentation of your solution
// - correctly implementing the function for valid inputs
// - handling invalid inputs in a consistent way
// - efficiency for large input values


//
// Here is the function you should implement:
//
//
// vector<float> local_average(vector<string> w, int loc) { }
//

// Find the average length of the strings in the vector *w*
// over an averaging interval of *loc*, with the averaging "window"
// shifting by one each time.
//
// That is, we take the average length of *w* for the first *loc* 
// strings, then the strings from 1 to *loc*, 
// then the strings from 2 to *loc*+1,
// The last value in the returned vector
// will be the average length of the last *loc* strings in *w*


// Example results:
//
//   w                  loc        output    
//   abc abd a b c        1        3 3 1 1 1
//   a z w aaa 123        2        1 1 2 3
//   abc abc a b c        3        2.67 1.67 1
//   abc a b c abd        4        1.5 1.5
//   a bcd e              2        2 2
//   a b abcedae w x z    3        3 3 3 1
//   a 22 333 1           2        1.5 2.5 2




// Add includes, main, and local_average function here.

