#include <stdio.h>

// Function prototypes
int get_int(char *prompt);

int main(void)
{
    int num;
    do 
    {
        num = get_int("Please enter how many primes you want to see: ");
    }
    while (num < 1);
    int remain = num % 7;

    if (remain == 0)
    {
        printf("%i is divisible by 7.\n", num);
    }
    else
    {
        printf("You need to add %i to %i for it to be divisible by 7.\n", 7 - remain, num);
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