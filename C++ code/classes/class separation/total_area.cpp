#include <iostream>
#include <iomanip>
#include <string>
#include "circle_class.hpp"
using namespace std;

// Add circle areas
double sum(Circle circleArray[], int size)
{
  // Initialize sum
  double sum = 0;

  // Add areas to sum
  for (int i = 0; i < size; i++)
    sum += circleArray[i].getArea();

  return sum;
}

// Print an array of circles and their total area
void printCircleArray(Circle circleArray[], int size)
{
  cout << setw(10) << "Radius" 
       << setw(10) << "Area" << endl;
  for (int i = 0; i < size; i++)
  {
    cout << setw(10) << circleArray[i].getRadius() 
         << setw(10) << circleArray[i].getArea() << endl;
  }

  cout << "-----------------------------------------" << endl;

  // Compute and display the result
  cout << "The total areas of circles is \t" <<
    sum(circleArray, size) << endl;
}

int main(int argc,const char *argv[])
{

  int SIZE;
  if  (argc==2) {
     string sizearg;
     sizearg=argv[1];
     SIZE = stoi(sizearg);
  }
  else
   return 1;

  Circle circleArray[SIZE];

  for (int i = 0; i < SIZE; i++)
  {
    circleArray[i].setRadius(i + 1);
  }

  printCircleArray(circleArray, SIZE);

  return 0;
}
