//Zach Colby 11/07/12
//Program that consists of 2 games using functions
//A Guessing and Arithmetic Game

//Included libraries
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

//Constants
#define ADD 1
#define MULT 2

//Function prototypes
int arithGame(int max, int op);
int guessGame();
int max(int a, int b);
int min(int a, int b);

//Main Function
int main() {

    //Seed Random Function
    srand(time(0));

    //Declare Variables
    int choice;
    int max;
    int op;
    int score = 0;

    do {

        //Print Menu
        printf("Please make a selection from the following:\n");
        printf("1. Play Arithmetic Game.\n");
        printf("2. Play Guessing Game.\n");
        printf("3. Print Score.\n");
        printf("4. Quit.\n");
        scanf("%d", &choice);

        //Choice 1: Arithmetic Game.
        if (choice == 1){
            printf("Would you like, 1)Addition or 2)Multiplication?\n");
            scanf("%d", &op);
            printf("What is the maximum number you would like?\n");
            scanf("%d", &max);

            //Display 10 Random problems.
          score += arithGame(max, op);

        }

        //Choice 2: Guessing Game.
        else if (choice == 2)
            score += guessGame();

        //Choice 3: Print Score.
        else if (choice == 3)
            printf("Your score is %d\n", score);

        //Choice 4: Quit.
        else if (choice == 4)
            printf("Thank you for playing!\n");

        //Invalid Choice
        else
            printf("Sorry, that was not a valid input.\n");

    } while (choice !=4);

    return 0;
}

/*Pre-Conditions: This function takes in two integers, max and op.
    This function gives the user 10 arithmetic questions, where
    each operand ranges from 1 to max, inclusive. The value of
    operator dictates whether the problems are addition or
    multiplication problems.
    Namely, if op is 1, they are addition problems, otherwise,
    they are multiplication problems.
*Post-Conditions:  The function returns the number problems solved
    correctly, and prints out for the user after their answer
    whether or not they got the question correct.
*/
int arithGame(int max, int op){
    int i;
    int round_score = 0;

    for (i=0; i<10; i++){
        int num1 = rand()%max + 1;
        int num2 = rand()%max + 1;
        int input;
        int answer;


        //Operand is Addition.
        if (op == ADD){
            answer = num1 + num2;
            printf("What is %d + %d?\n", num1, num2);
            scanf("%d", &input);

            if (input == answer){
                printf("Correct, great job!\n");
                round_score++;
            }
            else
                printf("Sorry that's incorrect, the answer is %d\n", answer);
        }

        //Operand is Multiplication.
        else {
            answer = num1 * num2;
            printf("What is %d * %d?\n", num1, num2);
            scanf("%d", &input);

            if (input == answer){
                printf("Correct, great job!\n");
                 round_score++;
            }
            else
                printf("Sorry that's incorrect, the answer is %d\n", answer);
        }
    }
    printf("Your score for the round is %d\n", round_score);
    return round_score;
}

/*Pre-Conditions: This function does not take in any paraments.
    This function allows the user to play the guessing game
    where the randomly generated number lies in between 1
    and 100, inclusive.
*Post-Conditions:  The value returned is the score of the user in the game.
    This score is 17 minus the number of guesses unless this
    value is lower than 0 or greater than 10.
    In these cases, 0 and 10 are returned, respectively.
*/
int guessGame(){
    int answer = rand()%100 + 1;
    int guess;
    int score = 1;
    int a, b;

    do {
        printf("Enter the guess\n");
        scanf("%d", &guess);

        a = guess; b = answer;

        if (answer == guess)
            printf("Great, you guessed the correct number %d in %d guesses.\n", answer, score);
        else if (guess > answer){
            printf("Your guess is too high, try again.\n");
            score++;
        }
        else if (guess < answer){
            printf("Your guess is too low, try again.\n");
            score++;
        }
    } while (guess != answer);

    //Determine Score using 2 other functions
    score = 17 - score;
    score = max(0, score);
    score = min(10, score);

    printf("Your score for this round is %d", score);

    return score;
}

/*Pre-Conditions: This function takes in two integers, a and b.
  *Post-Conditions: This function returns the larger of a and b.
  */
int max(int a, int b){
    if (a > b)
        return a;
    else
        return b;
}

/*Pre-Conditions: This function takes in two integers, a and b.
  *Post-Conditions: This function returns the smaller of a and b.
  */
int min(int a, int b){
    if (a < b)
        return a;
    else
        return b;
}
