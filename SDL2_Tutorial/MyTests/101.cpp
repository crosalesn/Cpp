#include <stdio.h>
#include <string>
#include <iostream>

int main() {
  int test = 1;
  std::cout << "test: " << test << std::endl;
  int* pMine = &test;
  std::cout << "The address of test (the value of pMine): " << pMine << std::endl;
  std::cout << "The address of pMine " << &pMine << std::endl;
  std::cout << "The value of what pMine points to " << *pMine << std::endl;
  *pMine  = 2;
  std::cout << "*pMine = 2, changes the value of test" << std::endl;
  std::cout << "test: " << test << std::endl;

}