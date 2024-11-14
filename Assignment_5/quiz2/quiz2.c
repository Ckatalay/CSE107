#include <stdio.h>

int get_int(char *prompt);

int main(void)
{
    int count = get_int("Count: ");
    while (count < 1)
    {
        count = get_int("Invalid input. Count: ");
    }

    while (count != 0)
    {
        printf("%i\n", count);
        count--;
    }
    printf("Countdown compelete!\n");
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
            printf("Letter input not allowed\n");
            while ((c = getchar()) != '\n' && c != EOF);
        }
    }
    return i;
}