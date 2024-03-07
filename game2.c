#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int num1, num2, choice, answer, score = 0;
    char operator;

    srand(time(NULL));

    printf("Welcome to the Math Game!\n");

    while (1) {
        num1 = rand() % 10 + 1;
        num2 = rand() % 10 + 1;
        operator = '+';
        printf("\nWhat is %d %c %d?\n", num1, operator, num2);

        scanf("%d", &answer);


        int correct_answer = (operator == '+') ? num1 + num2 : 0;


        if (answer == correct_answer) {
            printf("Correct!\n");
            score++;
        } else {
            printf("Wrong. The answer is %d.\n", correct_answer);
        }

        printf("Do you want to play again (y/n)? ");
        char play_again;
        scanf(" %c", &play_again);

        if (play_again != 'y' && play_again != 'Y') {
            break;
        }
    }
    printf("\nThank you for playing! Your final score is %d.\n", score);
    return 0;
}

