// Selection Sort:
// Time Complexity: Best: O(n^2), Average: O(n^2), Worst: O(n^2)
// Space Complexity: Worst: O(1)


#include <algorithm>
#include <iterator>
#include <iostream>
 
template<typename ForwardIterator> void selection_sort(ForwardIterator begin,
																											 ForwardIterator end) {
	for(auto i = begin; i != end; ++i) {
		std::iter_swap(i, std::min_element(i, end));
	}
}
 
int main() {
	int a[] = {100, 2, 56, 200, -52, 3, 99, 33, 177, -199};
	selection_sort(std::begin(a), std::end(a));
	copy(std::begin(a), std::end(a), std::ostream_iterator<int>(std::cout, " "));
	std::cout << "\n";
}