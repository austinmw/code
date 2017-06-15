/* Implement the three functions specified. 
When implemented properly,
the output of this program is
4 2 1 -4 2
5 3 1 -4 2
4
0
-1
3 1 2 -2 -1 0
-2 -1
3 5 1 2 -2 -1 7 8 0 9
*/

#include <iostream>
using namespace std;

// Add one to each element of an array
void array_increment(int* list,const int SIZE)
{
for (int i = 0; i < SIZE; i++)
	list[i] += 1;
}

// Return the index of the final matching value in the array
// or -1 if no element matched

int find_final(int  * const list,const int SIZE,const int FIND)
{
	for (int i = SIZE-1; i >= 0; i--)
		{
			if (list[i] == FIND)
				return i;
		}	
	return -1;
}

// return a pointer to a new array contained the elements of  list[] 
// smaller than THRESHOLD. The relative order of the elements should be preserved
// in the returned array. The size of the returned array is returned in count

int * smaller_than(const int list[],const int SIZE,int& count,const int THRESHOLD=0)
{
	count = 0;
	
	for (int i = 0; i < SIZE; i++)
	{
		if (list[i] < THRESHOLD)
		{
			count++;
		}
	}
		
	int * newArray = new int[count];
	int j = 0;

		for (int i = 0; i < SIZE; i++)
		{
			if (list[i] < THRESHOLD)
			{
				newArray[j] = list[i];
				j++;
			}
		}
		return newArray;	
}

void printarray(int c[],int SIZE){
	int i;
	if (!SIZE) return;
    for (i=0; i<SIZE-1; i++)
		 cout << c[i] << " ";
	cout << c[i] << endl;    
}

int main() {
	int c[]={3,1,0,-5,1};
	array_increment(c,5);
	printarray(c,5);
	array_increment(c,2);
	printarray(c,5);

	int d[]={2,1,3,2,2,0,3};
	cout << find_final(d,7,2) << endl;
	cout << find_final(d,3,2) << endl;	
	cout << find_final(d,7,4) << endl;	
   
    int e[]={3,5,1,2,-2,-1,7,8,0,9};
    int *f;
    int fsize;
   f=smaller_than(e,10,fsize,5);
    printarray(f,fsize);
    f=smaller_than(e,10,fsize);
    printarray(f,fsize);    
    printarray(e,10);

	
}