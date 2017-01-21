#include <iostream> 
using namespace std;

void quickSort(int arr[], int left, int right) {
	int i = left, j = right;
	int tmp;
	int pivot = arr[(left + right) / 2];
 
	/* partition */
	while (i <= j) {
		while (arr[i] < pivot)
			i++;
		while (arr[j] > pivot)
			j--;
		if (i <= j) {
			tmp = arr[i];
			arr[i] = arr[j];
			arr[j] = tmp;
			i++;
			j--;
		}
	};
 
	/* recursion */
	if (left < j)
		quickSort(arr, left, j);
	if (i < right)
		quickSort(arr, i, right);
		

		for (int i = 0; i < 5; i++){
			
			cout << arr[i] << " ";
		}	
		
}		
int main(){
	
	int arr[5] = {1,3,5,4,2};
	
	
	quickSort(arr, 0, 2);
	

	return 0;
}