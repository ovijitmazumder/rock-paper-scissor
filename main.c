//introduction start
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    char name[100];
    int computer, user;
    int userScore = 0, computerScore = 0;  // Scoring system
    int rounds, currentRound = 0;

    printf("Enter your name: ");
    scanf("%s", name);
    printf("\n");
    printf("== ROCK == PAPER == SCISSORS == LIZARD == SPOCK ==\n");
    printf("RULES:\n");                        // Introduction and rules
    printf("1. Rock crushes Scissors and Lizard.\n");
    printf("2. Paper covers Rock and disproves Spock.\n");
    printf("3. Scissors cut Paper and decapitate Lizard.\n");
    printf("4. Lizard eats Paper and poisons Spock.\n");
    printf("5. Spock smashes Scissors and vaporizes Rock.\n");
    printf("Choices: 0 = Rock, 1 = Paper, 2 = Scissors, 3 = Lizard, 4 = Spock\n");
    printf("Press 9 to Exit the game.\t press 11 to Restart\n\n");

    srand(time(0)); // Seed for random number generation

    printf("How many rounds would you like to play? Enter a number: ");
    scanf("%d", &rounds);
    printf("\nStarting a best of %d rounds match!\n\n", rounds);
    //introduction end
    //game loop start

    while (currentRound < rounds) {
        printf("Round %d/%d\n", currentRound + 1, rounds);
        printf("%s, enter your choice (0-4): ", name);
        scanf("%d", &user);

        if (user == 9) { // Handle exit option
            printf("\nFinal Scores:\n");
            printf("%s: %d\n", name, userScore);
            printf("Computer: %d\n", computerScore);
            printf("Goodbye, %s!\n", name);
            break;
        }
        if (user == 11) { // Handle restart option
            printf("Restarting the program......\n");
            userScore = 0;
            computerScore = 0;
            currentRound = 0;
            printf("How many rounds would you like to play? Enter a number: ");
            scanf("%d", &rounds);
            printf("\nStarting a best of %d rounds match!\n\n", rounds);
            continue;
        }
        if (user < 0 || user > 4) { // Input validation
            printf("Invalid choice! Please choose between 0 and 4, or press 9 to Exit.\n\n");
            continue;
        }
        //game loop end
        //random choice generation start

        computer = rand() % 5; // Random computer choice
        printf("Computer chose: %d\n", computer);
        //random choice generation end
        //determining the winner start

        switch (user) { // Game logic using switch-case
        case 0: // Rock
            if (computer == 0) {
                printf("It's a draw! Both chose Rock.\n");
            } else if (computer == 2 || computer == 3) {
                printf("%s wins! Rock crushes Scissors/Lizard.\n", name);
                userScore++;
            } else {
                printf("Computer wins! Paper covers or Spock vaporizes Rock.\n");
                computerScore++;
            }
            break;

        case 1: // Paper
            if (computer == 1) {
                printf("It's a draw! Both chose Paper.\n");
            } else if (computer == 0 || computer == 4) {
                printf("%s wins! Paper covers Rock/disproves Spock.\n", name);
                userScore++;
            } else {
                printf("Computer wins! Scissors cut or Lizard eats Paper.\n");
                computerScore++;
            }
            break;

        case 2: // Scissors
            if (computer == 2) {
                printf("It's a draw! Both chose Scissors.\n");
            } else if (computer == 1 || computer == 3) {
                printf("%s wins! Scissors cut Paper/decapitate Lizard.\n", name);
                userScore++;
            } else {
                printf("Computer wins! Rock crushes or Spock smashes Scissors.\n");
                computerScore++;
            }
            break;

        case 3: // Lizard
            if (computer == 3) {
                printf("It's a draw! Both chose Lizard.\n");
            } else if (computer == 1 || computer == 4) {
                printf("%s wins! Lizard eats Paper/poisons Spock.\n", name);
                userScore++;
            } else {
                printf("Computer wins! Rock crushes or Scissors decapitate Lizard.\n");
                computerScore++;
            }
            break;

        case 4: // Spock
            if (computer == 4) {
                printf("It's a draw! Both chose Spock.\n");
            } else if (computer == 0 || computer == 2) {
                printf("%s wins! Spock vaporizes Rock/smashes Scissors.\n", name);
                userScore++;
            } else {
                printf("Computer wins! Paper disproves or Lizard poisons Spock.\n");
                computerScore++;
            }
            break;
        }
        //determining the winner end
        //scoring start

        currentRound++;
        printf("\nCurrent Scores:\n"); // Display scores after each round
        printf("%s: %d\n", name, userScore);
        printf("Computer: %d\n\n", computerScore);
    }

    printf("\nFinal Scores:\n");
    printf("%s: %d\n", name, userScore);
    printf("Computer: %d\n", computerScore);
    //scoring end
    //game conclusion start

    if (userScore > computerScore) {
        printf("Congratulations, %s! You won the match!\n", name);
    } else if (computerScore > userScore) {
        printf("Computer wins the match! Better luck next time, %s.\n", name);
    } else {
        printf("It's a draw! Well played, %s.\n", name);
    }

    return 0;
}
//game conclusion end




