#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int late_calc(int *eday, int *emonth, int *eyear, int *day, 
			  int *month, int *year, int *fine) {
	
	//cout << " " << *eday << " " << *emonth << " " << *eyear;
	//cout << " " << *day << " "  << *month << " " << *year <<  endl;
	if ((*emonth >= *month) && (*eday >= *day) && (*eyear >= *year)) {
		*fine = 0;
		return 0;
	}
		
	else if (*eyear != *year) {
		*fine = 10000;
		return 0;
	}
	
	else if (*emonth != *month) {
			*fine = 500 *  abs(*emonth-*month);
			return 0;
	}
	
	else
		*fine = 15 * abs(*eday-*day);
		return 0;
}

int main() {
	int emonth, eday, eyear, month, day, year, fine;
	cin >> day >> month >> year >> eday >> emonth >> eyear;
	late_calc(&eday, &emonth, &eyear, &day, &month, &year, &fine);
	cout << fine;
}


/*
31 8 2004
20 1 2004
output 3500
2 6 2014
5 7 2014
out 0
*/