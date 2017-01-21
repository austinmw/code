// high_resolution_clock example
#include <iostream>
#include <ctime>
#include <ratio>
#include <chrono>


void fn()
{
	long long number = 0;

	for( long long i = 0; i != 2000000; ++i )
	{
	   number += 5;
	}
}


int main ()
{
	using namespace std::chrono;

	high_resolution_clock::time_point t1 = high_resolution_clock::now();

	fn();

	high_resolution_clock::time_point t2 = high_resolution_clock::now();

	duration<double> time_span = duration_cast<duration<double>>(t2 - t1);

	std::cout << "It took me " << time_span.count() << " seconds.";
	std::cout << std::endl;

	return 0;
}