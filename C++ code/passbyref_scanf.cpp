#include <stdio.h>
#include <iostream>
#include <cmath>

void update(int *a,int *b) {
	int temp = *a;
	*a = *a+*b;
   //  std::cout << a << std::endl;   // prints ADDRESS
	*b = abs(temp-*b);
	// Complete this function    
}





int main() {
	int a, b;
	//int *pa = &a, *pb = &b;
	
	scanf("%d %d", &a, &b);
	// removed pointer declarations and passed address instead of pointers to simplify
	update(&a, &b);
	printf("%d\n%d", a, b);

	return 0;
}

