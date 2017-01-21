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

void swap(int &x,int &y){
	int tmp=x;
	x=y;
	y=tmp;
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

     for (int i=0;i < N - 1 ;i++)
     	for (int j= N-1; j>i ; j--)
          if (v[j]<v[j-1]){
            swap(v[j],v[j-1]);
          }
     
     cout << "the sorted numbers are" << endl;
     printvector(v);

	return 0;
}