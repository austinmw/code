#include <iostream>
// consecutive ones in binary representation

using namespace std;
int main(int argc, char *argv[]) {
	int bin[30] = {0};
	int n, j, count = 0, i = 0, maxConsec = 0;

	cin >> n;
	if (n != 0)
		maxConsec++;
	while (n > 0) {
		bin[i] = n%2;
		n = (int) n/2;
		i++;
	}	
	for (j = 0; j < (sizeof(bin)/sizeof(bin[0]))-1; j++) {	
		if ((bin[j] == 1) && (bin[j+1] == 1)) {
			count++;
			if (count >= maxConsec)
				maxConsec = count+1;	
		}		
		else 
			count = 0;
	}
	cout << maxConsec;
	return 0;
}