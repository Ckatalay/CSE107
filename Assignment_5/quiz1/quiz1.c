#include <stdio.h>

#define SECRET 25

int get_int(char *prompt);

int main(void)
{
    int guess;

    for (int i = 0; i < 5; i++)
    {
        guess = get_int("Guess: ");
        if (guess < SECRET)
        {
            printf("Too low!\n");
        }
        else if (guess > SECRET)
        {
            printf("Too high!\n");
        }
        else
        {
            printf("Congratilations, you guessed the number correctly!\n");
            return 0;
        }
        if (i == 4)
        {
            printf("Sorry, you've used all your attemps. The secret number was %i.\n", SECRET);
        }
    }
}

// Gets input from user and returns it
int get_int(char *prompt)
{
    int i;
    char c;
    while (1)
    {
        printf("%s", prompt);
        if (scanf("%i", &i) == 1)
        {
            // Valid integer input
            break;
        }
        else
        {
            // Invalid input, clear the buffer
            while ((c = getchar()) != '\n' && c != EOF);
        }
    }
    return i;
}