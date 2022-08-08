#include <iostream>

void prime();

int main() 
{
  // No argument is passed to prime()
  prime();
  return 0;
}

void prime() {
  int num, i, divisor, flag = 0;
  std::cout << "Enter a positive integer to check: ";
  std::cin >> num;

  for (i = 2; i <= num/2; ++i) 
  {
    if(num % i == 0) 
    {
      divisor = i;
      flag = 1;
      break;
    }
  }

  if (flag == 1) {
    std::cout << "The number is not prime, divisor " << divisor << std::endl;
  } else {
    std::cout << "The number is prime!" << std::endl;
  }
}