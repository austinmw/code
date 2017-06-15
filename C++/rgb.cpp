// Colors on the web are stored as 24-bit numbers.
// In hex, the color 0xa1b2c3 means rgb(161,178,195)
// using C notation: 0xa1 in red, 0xb2 in green, and 0xc3 in blue

#include <iostream>
#include <iomanip>

using namespace std;
int main(){


	int x=0xa1b2c3;

	/// extract the red, green, and blue parts of x into r,g,b

	// your code here l1
	// your code here l2
	// your code here l3

	cout << "rgb " << r <<',' << g << ',' << b <<endl;
	cout << "hex "  << hex << r << g << b  << dec << endl;



	// create the webcolor e5c8B0 as int color1 and rgb(229,200,176) as int color2 
	
	// your code here l4
	// your code here l5

	cout << "1 " << color1 << " 2 " << color2 << endl;

	// print out how much green is in the color myst, as a real number from 0 to 1
	int myst=0x331211;

	double greenamount;
	
	// your code here l6
	
	cout << "green amount=" << greenamount << endl; 


}