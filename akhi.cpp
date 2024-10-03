#include <iostream>

using namespace std;


int multiply(int num1, int num2) {
  return num1 * num2;
}

int main() {

  int firstNumber, secondNumber, product;

  cout << "Enter the first number: ";
  cin >> firstNumber;

  cout << "Enter the second number: ";
  cin >> secondNumber;

  product = multiply(firstNumber, secondNumber);

  cout << "The product of " << firstNumber << " and " << secondNumber << " is: " << product << endl;

  return 0;
}
