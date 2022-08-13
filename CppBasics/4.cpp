#include <iostream>

// global variable declaration
// it reserves a memory block for an int
int num;

// function declaration
int& test();

int main() {
  // test function is executed
  // test() returns the memory address of the num variable
  // the memory address of the int variable is filled with the value 5
  test() = 5;

  // outputs 5, since the line above assigned 5 to the num variable
  std::cout << num << std::endl;

  return 0;
}

// function definition
// returns the address of num variable
int& test() {
  return num;
}