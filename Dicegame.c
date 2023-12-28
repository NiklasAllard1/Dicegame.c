#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>

#define clrscr() printf("\e[1;1H\e[2J")

int main()
{
    srand(time(NULL));
    int bet, guess, balance, dice;
    balance = 1000;

    clrscr();
    printf("Hi and welcome to the Dicegame!\n\n");
    printf("This game starts you off with 1000$\n");
    printf("you throw the dice and either you lose the bet\n");
    printf("or win and triple your bet.\n");
    printf("Good luck!\n\n");
    sleep(8);

    while (balance > 0)
    {
        clrscr();
        printf("Your current balance is: $%d\n", balance);
        printf("How much do you want to bet? (0 = Quit)\n");
        scanf("%d", &bet);

        if (bet == 0)
        {
            printf("Thank you for playing!\n");
            return 0;
        }

        while (bet > balance)
        {
            printf("You don't have that much money! Try again\n");
            printf("Your current balance is: $%d\n", balance);
            printf("How much do you want to bet? (0 = Quit)\n");
            scanf("%d", &bet);

            if (bet == 0)
            {
                printf("Thank you for playing!\n");
                return 0;
            }
        }

        printf("Guess a number between 1 and 6 (0 = Quit)\n");
        scanf("%d", &guess);

        // Dice-throwing simulation
        clrscr();
        printf("Throwing the dice.\n");
        sleep(1);
        clrscr();
        printf("Throwing the dice..\n");
        sleep(1);
        clrscr();
        printf("Throwing the dice...\n");
        sleep(1);

        dice = (rand() % 6 + 1);
        printf("The dice shows: %d\n", dice);
        
        if (guess == dice)
        {
            printf("You won! Congratulations! You tripled your bet!\n");
            balance += bet * 2;
        }
        else
        {
            printf("You lost your bet, better luck next time\n");
            balance -= bet;
        }
        sleep(5);  // pause for a few seconds to let the user see the result before next round
    }

    if (balance <= 0)
    {
        printf("You are out of money, better luck next time!\n");
    }

    return 0;
}
