#include <iostream>
#include <algorithm>
#include <vector>


using namespace std;

vector<int> insert_sort(vector<int> list)
{
	for (int i = 1; i <= list.size(); i++){
		int key = list[i];
		int j = i - 1;	
		while ((j >= 0) & (list[j] > key)){
			list[j+1] = list[j];
			j--;
		}
		list[j+1] = key;		
	}		
	return list;
}

int main(int argc, char *argv[]) {
	
	vector<int> list = {3, 5, 2, 6, 7, 9};
	vector<int> ans = insert_sort(list);
	for (int i = 0; i <= ans.size(); i++)
		cout << ans[i] << " ";
	
	return 0;
}



