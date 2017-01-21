#include <iostream>

int partition(int ar[], int low, int high)
{
	int pivot = ar[(low + high) / 2];
	while (low <= high)
	{
		while (ar[low] < pivot) low++;
		while (ar[high] > pivot) high--;
		
		if (low <= high)
		{
			int temp = ar[low];
			ar[low] = ar[high];
			ar[high] = temp;
			low++;
			high--;
		}
	}
	return low;
}

void quicksort(int ar[],int low,int high)
{
	int index = partition(ar, low, high);
	if (low < index - 1)
	{
		quicksort(ar, low, index - 1);
	}
	
	if (index < high)
	{
		quicksort(ar, index, high);
	}
}

int main(int argc, char* argv[])
{
	int ar[] = {5, 1, 3, 4, 5, 5};
	int high = sizeof ar / sizeof(int) - 1;
	
	std::cout << "Unsorted" << std::endl;
	for (int i = 0; i < high + 1; ++i)
	{
		std::cout << ar[i] << "\t";
	}
	std::cout << std::endl;
	
	quicksort(ar, 0, high);
	
	std::cout << "Sorted" << std::endl;
	for (int i = 0; i < high + 1; ++i)
	{
		std::cout << ar[i] << "\t";
	}
	std::cout << std::endl;
	return 0;
}

