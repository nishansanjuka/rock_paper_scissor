#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

// Initialize the random number generator
void initRandomGenerator() {
    srand(time(NULL));
}

// Generate a random integer between min and max (inclusive)
char getMyOpenion() {
    initRandomGenerator();
    int random = rand() % 3;  // Generate a random number between 0 and 2

    if (random == 0) {
        return 'r';
    } else if (random == 1) {
        return 'p';
    } else {
        return 's';
    }
}

bool Play(char opponent, char me) {
    if (me == 'r' && opponent == 's') {
        return true;
    } else if (me == 'r' && opponent == 'p') {
        return false;
    } else if (me == 'p' && opponent == 'r') {
        return true;
    } else if (me == 'p' && opponent == 's') {
        return false;
    } else if (me == 's' && opponent == 'p') {
        return true;
    } else if (me == 's' && opponent == 'r') {
        return false;
    }
    return false;  // Default case
}

int main() {
    int score;
    int opponent = 0, me = 0;

    printf("Let's Play Hand Match\n");
    printf("Game Started\n");
    printf("Remember Always...\n");
   
    printf("r for Rock\n");
    printf("p for Paper\n");
    printf("s for Scissor\n\n");
    printf("Tell Us The Score Limit: ");
    scanf("%d", &score);

    while (me < score && opponent < score) {
        printf("Choose: ");
        char userChoice;
        scanf(" %c", &userChoice);  // Read a character (note the space before %c)

        if(userChoice == 's' || userChoice == 'p'|| userChoice == 'r'){
            char computerChoice = getMyOpenion();
            if (userChoice != computerChoice) {
                bool isMe = Play(userChoice, computerChoice);
                if (isMe) {
                    printf("Computer wins this round!\n");
                    me = me + 1;
                } else {
                    printf("You win this round!\n");
                    opponent = opponent + 1;
                }
            } else {
                printf("It's a tie! Try again...\n");
            }

            printf("You: %d scores |||| Computer: %d scores\n\n", opponent, me);
        }
        else
        {
            printf("please schoose valid options!\n");
            printf("Valid Options,\n\n");
            printf("r for Rock\n");
            printf("p for Paper\n");
            printf("s for Scissor\n\n");
        }
    }

    printf("Game Over!\n");

    if (me > opponent) {
        printf("Computer won by %d scores\n\n", ( me - opponent));
        
    } else {
        printf("You won by %d scores\n\n", (opponent - me));
    }

    printf("Your Score - %d\n", opponent);
    printf("------------------\n");
    printf("Computer's Score - %d\n\n", me);

    printf("Press any key to exit...");
    getch();
    
    return 0;
}
