#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int generateComputerChoice() {
  srand(time(NULL));
  int computerChoice = rand() % 3;
  return computerChoice;
}


int determineWinner(int userChoice, int computerChoice) {

  if (userChoice == computerChoice) {
    printf("It's a tie!\n");
    return 0;
  } else if ((userChoice == 0 && computerChoice == 2) ||
             (userChoice == 1 && computerChoice == 0) ||
             (userChoice == 2 && computerChoice == 1)) {
    printf("You win!\n");
    return 1;
  } else {
    printf("Computer wins!\n");
    return -1;
  }
}

int main() {
  int userChoice;


  printf("Enter your choice (0 for rock, 1 for paper, 2 for scissors): ");
  scanf("%d", &userChoice);


  int computerChoice = generateComputerChoice();


  int winner = determineWinner(userChoice, computerChoice);

  return 0;
}
