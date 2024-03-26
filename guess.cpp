#include <iostream>

using namespace std;

int main() {
  int number;
  int guessCount = 0;

  const int secretNumber = 15;

  do {
    cout << "Enter your guess (1-100): ";
    cin >> number;

    guessCount++;

    if (number < secretNumber) {
      cout << "Your guess is too low. Try again." << endl;
    } else if (number > secretNumber) {
      cout << "Your guess is too high. Try again." << endl;
    }
  } while (number != secretNumber);

  cout << "Congratulations! You guessed the number in " << guessCount << " tries." << endl;

  return 0;
}

