//Insertion Sort: 
//Time Complexity: Best: O(n), Average: O(n^2), Worst: O(n^2)
//Space Complexity: Worst: O(1)

#include <algorithm>
#include <iostream>
#include <iterator>
 
template <typename RandomAccessIterator, typename Predicate>
void insertion_sort(RandomAccessIterator begin, RandomAccessIterator end,
										Predicate p) {
	for (auto i = begin; i != end; ++i) {
		std::rotate(std::upper_bound(begin, i, *i, p), i, i + 1);
	}
}
 
template <typename RandomAccessIterator>
void insertion_sort(RandomAccessIterator begin, RandomAccessIterator end) {
	insertion_sort(
			begin, end,
			std::less<
					typename std::iterator_traits<RandomAccessIterator>::value_type>());
}
 
int main() {
	int a[] = { 100, 2, 56, 200, -52, 3, 99, 33, 177, -199 };
	insertion_sort(std::begin(a), std::end(a));
	copy(std::begin(a), std::end(a), std::ostream_iterator<int>(std::cout, " "));
	std::cout << "\n";
}

/*
Insertion sort is another sorting algorithm, which operates by inserting an element in the input list in to the correct position in a list (that is already sorted). This process is applied repeatedly until the list is sorted. In insertion sort, sorting is carried out in-place. Therefore after the ith iteration of the algorithm, the first i+1 entries in the list will be sorted and the rest of the list will be unsorted. At each iteration, the first element in the unsorted part of the list will be taken and inserted in to the correct place in the sorted section of the list. Insertion sort has an average case time complexity of O(n2). Due to this, insertion sort is also not suitable for sorting large lists.
*/