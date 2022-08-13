#include <iostream>

int main() {
  // initialize an array without specifying size
  double numbers[] = {7, 5, 6, 12, 35, 27};

  double sum = 0;
  double count = 0;
  double average;

  std::cout << "The numbers are: ";

  //  print array elements
  // use of range-based for loop
  for (const double &n : numbers) {
    std::cout << n << "  ";

    //  calculate the sum
    sum += n;

    // count the no. of array elements
    ++count;
  }

  // print the sum
  std::cout << "\nTheir Sum = " << sum << std::endl;

  // find the average
  average = sum / count;
  std::cout << "Their Average = " << average << std::endl;
  return 0;
}

