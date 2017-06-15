#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void printvector(vector<int> v){
	for (auto x: v){
		cout << x << " ";
	}
	cout << endl;
}

int main(int argc, char const *argv[])
{
	int N=argc-1;
	vector<int> v(N);

	// Read in the numbers	
	cout << "sort these numbers" << endl;
	for (int i=0 ; i < N ; i++ )
	 {
		v[i]=stoi(argv[i+1]);
     }

     printvector(v);

     sort(v.begin(),v.end());

     printvector(v);

	return 0;
}